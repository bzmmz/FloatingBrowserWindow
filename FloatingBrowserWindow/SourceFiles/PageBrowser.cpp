#include "PageBrowser.h"
#include "StringHelper.h"
#include <QString>
void PageBrowser::load_config()
{
    manager = new ConfigManager();
    manager->LoadConfig();
    return;
}

void PageBrowser::InitSystemTray()
{
    tray = new Tray(this);
}

void PageBrowser::ReloadCSS(QString css)
{
    this->webview->ReloadCss(css);
}

void PageBrowser::ClearCss()
{
    this->webview->RemoveCss();
}

void PageBrowser::ChangeUrl(QString url)
{
    manager->SetUrl(url);
    this->webview->LoadUrl(url);
}

void PageBrowser::IconClicked(QSystemTrayIcon::ActivationReason reason)
{
    //左键单击，显示窗口
    if (reason == QSystemTrayIcon::Trigger)
    {
        this->show();
    }
    //右键显示菜单
    else if (reason == QSystemTrayIcon::Context)
    {
        tray->ShowMenu();
    }
}

void PageBrowser::closeEvent(QCloseEvent *event)
{
    emit MainWindowCloseSignal();
    manager->SaveCurrentConfig(this);
    hide();
    event->ignore();
    if (tray != nullptr)
    {
        tray->hide_control->setText(QStringLiteral("显示窗口"));
        tray->show = false;
    }
}

bool WebView::eventFilter(QObject *obj, QEvent *event)
{
    //只在开启了自由移动窗口的情况下额外处理,否则只用默认处理
    if (free_move)
    {
        if (obj == child && event->type() == QEvent::MouseButtonPress)
        {
            mousePressEvent(static_cast<QMouseEvent *>(event));
        }
        else if (obj == child && event->type() == QEvent::MouseMove)
        {
            mouseMoveEvent(static_cast<QMouseEvent *>(event));
        }
        else if (obj == child && event->type() == QEvent::MouseButtonRelease)
        {
            mouseReleaseEvent(static_cast<QMouseEvent *>(event));
        }
    }

    return QWebEngineView::eventFilter(obj, event);
}

bool WebView::event(QEvent *event)
{
    if (event->type() == QEvent::ChildPolished)
    {
        QChildEvent *child_event = static_cast<QChildEvent *>(event);
        child = child_event->child();
        if (child != nullptr)
        {
            child->installEventFilter(this);
        }
    }
    return QWebEngineView::event(event);
}

void WebView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        DBP("鼠标左键按下\n");
        be_draggd = true;
        mouse_start_point = event->globalPos();
        DBP("鼠标位置:%d %d\n", event->globalPos().x(), event->globalPos().y());
        window_pos = parent->pos();
    }
}

void WebView::mouseMoveEvent(QMouseEvent *event)
{
    if (be_draggd)
    {
        DBP("鼠标拖动\t\t");
        QPoint distance = event->globalPos() - mouse_start_point;
        DBP("Distance:%d %d\n", distance.x(), distance.y());
        parent->move(window_pos + distance);
    }
}

void WebView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        be_draggd = false;
    }
}

WebView::WebView(QString css, PageBrowser *parent)
{
    this->parent = parent;
    setMouseTracking(false);
    this->css = css;
    InjectCss(this->css);
}

void WebView::ReloadCss(QString css)
{
    this->css = css;
    java_script = CombineScript(css);
    this->page()->runJavaScript(java_script, QWebEngineScript::ApplicationWorld);
}

QString WebView::GetCss()
{
    return css;
}

void WebView::SetMouseEventTransparent(bool m)
{
    mouse_transparent = m;
    this->setAttribute(Qt::WA_TransparentForMouseEvents, m);
    static_cast<QOpenGLWidget *>(child)->setAttribute(Qt::WA_TransparentForMouseEvents, m);
    child->installEventFilter(this);
}

void WebView::SetFreeMove(bool m)
{
    this->free_move = m;
}

QString WebView::CombineScript(QString css)
{
    QString s = QString::fromLatin1("(function() {"\
                                    "    css = document.createElement('style');"\
                                    "    css.type = 'text/css';"\
                                    "    css.id = 'css';"\
                                    "    document.head.appendChild(css);"\
                                    "    css.innerText = '%1';"\
                                    "})()").arg(css.simplified());
    return s;
}

void WebView::InjectCss(QString css)
{
    java_script = CombineScript(css);
    script_engine = new QWebEngineScript();
    script_engine->setName("css");
    script_engine->setInjectionPoint(QWebEngineScript::DocumentReady);
    script_engine->setSourceCode(java_script);
    script_engine->setRunsOnSubFrames(true);
    script_engine->setWorldId(QWebEngineScript::ApplicationWorld);
    this->page()->scripts().insert(*script_engine);
}

void WebView::RemoveCss()
{
    java_script = QString::fromLatin1("(function() {"\
                                      "    var element = document.getElementById('css');"\
                                      "    element.outerHTML = '';"\
                                      "    delete element;"\
                                      "})()");
    this->css = "";
    //todo,bug.无css样式第一次添加之后立即清除没用,得跑两次,很迷惑.如果是从config里面加载来的就没问题
    this->page()->runJavaScript(java_script, QWebEngineScript::ApplicationWorld);
    this->page()->runJavaScript(java_script, QWebEngineScript::ApplicationWorld);
    auto script = this->page()->scripts().findScript("css");
    this->page()->scripts().remove(script);
}

void WebView::LoadUrl(QString url)
{
    this->load(url);
    InjectCss(this->GetCss());
}

void PageBrowser::SetWindowTitle(QString title)
{
    this->setWindowTitle(title);
    this->webview->titleChanged(title);
}

void PageBrowser::SetCutomCSS(QString css)
{
    this->webview->ReloadCss(css);
}

void PageBrowser::SetTransparent(int transparent)
{
    double t = transparent / 100.0f;
    manager->SetTransparent(t);
    this->setWindowOpacity(t);
}

PageBrowser::PageBrowser()
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    DBP("主窗口生成\n");
    setMouseTracking(false);
    load_config();
    InitSystemTray();
    this->setWindowIcon(QIcon(":/image/ruby.png"));
    auto config = manager->GetConfig();
    //允许透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //移动窗口
    this->move(config.x, config.y);
    //调整窗口大小
    this->resize(config.width, config.height);
    //调节页面缩放比列
    //调节透明度
    this->setWindowOpacity(config.transparent);

    this->setWindowTitle(config.windowtitle);

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    webview = new WebView(config.css, this);
    this->webview->setContextMenuPolicy(Qt::NoContextMenu);
    this->webview->page()->setBackgroundColor(QColor(0, 0, 0, 0));
    this->webview->titleChanged(this->windowTitle());
    this->layout->addWidget(this->webview);
    this->setLayout(this->layout);

    this->webview->load(QUrl(config.page_url));

    SetMouseEventTransparent(config.mouse_penetration);
    SetFreeMove(config.free_move);
    lock(config.lock);
    //移动和缩放
    this->MoveWindow(config.x, config.y);
    this->ResizeWindows(config.width, config.height);
    this->ScaleWindowPage(config.scale);
    this->show();
}

PageBrowser::~PageBrowser()
{
    manager->SaveCurrentConfig(this);
    delete webview;
    delete layout;
    delete manager;
    delete tray;
}

void PageBrowser::lock(bool locked)
{
    this->setWindowFlag(Qt::WindowStaysOnTopHint, locked);
    this->setWindowFlag(Qt::FramelessWindowHint, locked);
    //window->setWindowFlag(Qt::Tool, locked);
}

void PageBrowser::ApplyConfig(BrowserConfig::Config config)
{
    return;
}

void PageBrowser::MoveWindow(float x, float y)
{
    this->move(x, y);
}

void PageBrowser::ResizeWindows(float width, float height)
{
    this->resize(width, height);
}

void PageBrowser::ScaleWindowPage(float scale)
{
    this->webview->page()->setZoomFactor(scale);
}

void PageBrowser::SetMouseEventTransparent(bool m)
{

    //需要先设置鼠标穿透再设置其它不然无法实现鼠标穿透...
    //而且无法实时切换
    //this->setAttribute(Qt::WA_TransparentForMouseEvents, m);
    this->webview->SetMouseEventTransparent(m);
    this->manager->SetMousePenertration(m); //留着做记录作用

    //主窗体的穿透似乎只能靠系统级API实现实时切换
    if (m)
    {
        SetWindowLong(reinterpret_cast<HWND>(this->winId()), GWL_EXSTYLE, GetWindowLong(reinterpret_cast<HWND>(this->winId()), GWL_EXSTYLE) |
                      WS_EX_TRANSPARENT | WS_EX_LAYERED);
    }
    else
    {
        SetWindowLong(reinterpret_cast<HWND>(this->winId()), GWL_EXSTYLE, GetWindowLong(reinterpret_cast<HWND>(this->winId()), GWL_EXSTYLE) &
                      ~WS_EX_TRANSPARENT & ~WS_EX_LAYERED);
    }
   


}

int PageBrowser::GetTransparent()
{
    auto config = manager->GetConfig();
    return static_cast<int>(config.transparent * 100);
}

void PageBrowser::SetFreeMove(bool move)
{
    this->manager->SetFreeMove(move);
    this->webview->SetFreeMove(move);
}

QString PageBrowser::GetCss()
{
    return webview->GetCss();
}

QString PageBrowser::GetPageUrl()
{
    return manager->GetUrl();
}

CM_LoadConfigCondition PageBrowser::GetLoadCondition()
{
    return this->manager->GetLoadConfigCondition();
}