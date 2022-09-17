#include "Tray.h"
#include "PageBrowser.h"
#include "StringHelper.h"
void Tray::Init()
{
    trayicon = new QSystemTrayIcon();
    
    InitMenu();
    trayicon->setToolTip(QStringLiteral("悬浮窗小工具"));
    trayicon->setIcon(QIcon(":/image/ruby.png"));
    //绑定点击托盘的函数
    connect(trayicon, &QSystemTrayIcon::activated, window, &PageBrowser::IconClicked);


    trayicon->show();
    ShowWindowLoadConfigInfo();
}

void Tray::InitMenu()
{
    menu = new QMenu(window);


    //控制面板
    control_panel = new QAction(menu);
    control_panel->setText(QStringLiteral("控制面板"));
    control_panel->setToolTip(QStringLiteral("控制窗口的方方面面"));
    connect(control_panel, &QAction::triggered, this, &Tray::PopControlPanel);
    menu->addAction(control_panel);

    //隐藏
    hide_control = new QAction(menu);
    hide_control->setText(QStringLiteral("隐藏窗口"));
    connect(hide_control, &QAction::triggered, this, &Tray::SwitchShowAndHide);
    menu->addAction(hide_control);
    //读取config中的窗口状态
    locked = window->manager->GetConfig().lock;
    mouse_penetration = window->manager->GetConfig().mouse_penetration;


    //锁定
    lock = new QAction(menu);
    lock->setCheckable(true);
    lock->setChecked(locked);
    lock->setText(QStringLiteral("锁定窗口"));
    lock->setToolTip(QStringLiteral("窗口将不能移动,隐藏标题栏,取消窗口阴影,同时会置顶"));
    connect(lock, &QAction::triggered, this, &Tray::SwitchLock);
    menu->addAction(lock);
    //鼠标穿透
    mouse_control = new QAction(menu);
    mouse_control->setCheckable(true);
    mouse_control->setChecked(mouse_penetration);
    mouse_control->setText(QStringLiteral("鼠标穿透"));
    mouse_control->setToolTip(QStringLiteral("开启鼠标穿透"));
    connect(mouse_control, &QAction::triggered, this, &Tray::SwitchMousePenertration);
    menu->addAction(mouse_control);
    //重置位置
    reset_pos = new QAction(menu);
    reset_pos->setText(QStringLiteral("重置窗口位置"));
    reset_pos->setToolTip(QStringLiteral("把窗口弄到看不见的地方之后重置位置"));
    connect(reset_pos, &QAction::triggered, [this](void) {window->move(QPoint(0, 0)); });
    menu->addAction(reset_pos);
    


    //退出
    quit = new QAction(menu);
    quit->setText(QStringLiteral("退出"));
    connect(quit, &QAction::triggered, [this](bool) { QApplication::exit(0); });
    menu->addAction(quit);
}

void Tray::ShowWindowLoadConfigInfo()
{
    QString message;
    CM_LoadConfigCondition result = this->window->GetLoadCondition();
    switch (result)
    {
    case CM_NO_CONFIG_FILE:
        message = QStringLiteral("未能找到配置文件，已使用默认配置"); break;
    case CM_ERROR_CONFIG_FILE:
        message = QStringLiteral("配置文件损坏，已使用默认配置");break;
    case CM_SUCCESS_LOAD_FILE:
        message = QStringLiteral("成功加载配置文件!"); break;
    }
    ShowMessage(message);
}

Tray::Tray(PageBrowser* window)
{
    this->window = window;
    Init();
}

Tray::~Tray()
{
    delete trayicon;
    delete quit;
    delete control_panel;
    delete hide_control;
    delete mouse_control;
    delete lock;
    delete reset_pos;
    delete menu;
}

void Tray::ShowMenu()
{
    QPoint Pos;
    Pos = QCursor::pos();
    Pos.setY(Pos.y() - menu->sizeHint().height());
    menu->exec(Pos);
}

PageBrowser* Tray::GetWindow()
{
    return window;
}

void Tray::ShowMessage(QString message)
{

    //windows下的通知需要改为GBK编码的字符
    //SH::utf8_2_gbk(message);
    QString title = QStringLiteral("提示");
    trayicon->showMessage(
        title,
        message,
        QSystemTrayIcon::MessageIcon::Information,
        1000
    );
}

void Tray::PopControlPanel()
{
    auto control_panel = new ControlPanel(window);
    control_panel->setWindowModality(Qt::ApplicationModal);
    control_panel->show();
}

void Tray::SwitchShowAndHide()
{
    if (show)
    {
        show = false;
        window->hide();
        hide_control->setText(QStringLiteral("显示窗口"));
    }
    else
    {
        show = true;
        window->show();
        hide_control->setText(QStringLiteral("隐藏窗口"));
    }
}

void Tray::SwitchLock()
{
    locked = !locked;
    window->setWindowFlag(Qt::WindowStaysOnTopHint, locked);
    window->setWindowFlag(Qt::FramelessWindowHint, locked);
    //window->setWindowFlag(Qt::Tool, locked);
    window->show();
    window->manager->SetLock(locked);
    this->lock->setChecked(locked);
}

void Tray::SwitchMousePenertration()
{
    mouse_penetration = !mouse_penetration;
    window->SetMouseEventTransparent(mouse_penetration);
    window->manager->SetMousePenertration(mouse_penetration);
    this->mouse_control->setChecked(mouse_penetration);
}


