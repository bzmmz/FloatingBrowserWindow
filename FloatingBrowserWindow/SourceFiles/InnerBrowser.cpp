﻿#include "InnerBrowser.h"
#include "StringHelper.h"
#include <QString>
void InnerBrowser::load_config()
{
    manager.LoadConfig();
    return;
}

void InnerBrowser::InitSystemTray()
{
    tray = new Tray(this);
}

void InnerBrowser::ReloadCSS(QString css)
{
    this->webview->ReloadCss(css);
}

void InnerBrowser::IconClicked(QSystemTrayIcon::ActivationReason reason)
{
    //左键单击，显示窗口
    if (reason == QSystemTrayIcon::Trigger)
    {
        this->show();
    }
    //右键显示菜单
    else if(reason == QSystemTrayIcon::Context)
    {
        tray->ShowMenu();
    }
}

void InnerBrowser::closeEvent(QCloseEvent* event)
{
    emit MainWindowCloseSignal();
    manager.SaveCurrentConfig(this);
}

WebView::WebView(QString css)
{
    this->css = css;
    InjectCss(this->css);
}

void WebView::ReloadCss(QString css)
{
    this->css = css;
    java_script = CombineScript(css);
    this->page()->runJavaScript(java_script);
}

QString WebView::GetCss()
{
    return css;
}

QString WebView::CombineScript(QString css)
{
    auto _css = css.replace("\n","\\n");
    auto s = JS_LOAD_CSS_FROM_STR + _css + "\\n`));document.head.append(style_node);})();'";
    return s;
}

void WebView::InjectCss(QString css)
{
    java_script = CombineScript(css);
    script_engine = new QWebEngineScript();
    script_engine->setInjectionPoint(QWebEngineScript::DocumentReady);
    script_engine->setSourceCode(java_script);
    this->page()->scripts().insert(*script_engine);
}

void InnerBrowser::SetWindowTitle(QString title)
{
    this->setWindowTitle(title);
    this->webview->titleChanged(title);
}

void InnerBrowser::SetCutomCSS(QString css)
{
    this->webview->ReloadCss(css);
}

void InnerBrowser::SetTransparent(int transparent)
{
    double t = transparent / 100.0f;
    this->setWindowOpacity(t);
}

InnerBrowser::InnerBrowser()
{
    
    load_config();
    InitSystemTray();
    auto config = manager.GetConfig();
    this->lock(true);
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
    webview = new WebView(config.css);
    this->webview->page()->setBackgroundColor(QColor(0, 0, 0, 0));
    this->webview->titleChanged(this->windowTitle());
    this->layout->addWidget(this->webview);
    this->setLayout(this->layout);

    
    //移动和缩放
    this->MoveWindow(config.x, config.y);
    this->ResizeWindows(config.width, config.height);
    
    
    this->ScaleWindowPage(config.scale);
    this->show();
    this->webview->load(QUrl(config.room_url));

}



InnerBrowser::~InnerBrowser()
= default;

void InnerBrowser::lock(bool on)
{
    this->setWindowFlag(Qt::WindowStaysOnTopHint, on);
    this->setAttribute(Qt::WA_TranslucentBackground, on);
}

void InnerBrowser::ApplyConfig(BrowserConfig::Config config)
{
}

void InnerBrowser::MoveWindow(float x, float y)
{
    this->move(x, y);
}

void InnerBrowser::ResizeWindows(float width, float height)
{
    this->resize(width, height);
}

void InnerBrowser::ScaleWindowPage(float scale)
{
    this->webview->page()->setZoomFactor(scale);
}

QString InnerBrowser::GetCss()
{
    return webview->GetCss();
}

CM_LoadConfigCondition InnerBrowser::GetLoadCondition()
{
    return this->manager.GetLoadConfigCondition();
}

