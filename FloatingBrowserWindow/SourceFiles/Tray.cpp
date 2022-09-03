#include "Tray.h"
#include "InnerBrowser.h"
void Tray::Init()
{
    trayicon = new QSystemTrayIcon();
    
    InitMenu();
    trayicon->setToolTip(tr("托盘捏"));
    trayicon->setIcon(QIcon("heart.png"));
    //绑定点击托盘的函数
    connect(trayicon, &QSystemTrayIcon::activated, window, &InnerBrowser::IconClicked);


    trayicon->show();

}

void Tray::InitMenu()
{
    menu = new QMenu(window);
    quit = new QAction(menu);
    quit->setText(QStringLiteral("退出"));
    menu->addAction(quit);

    set_title = new QAction(menu);
    set_title->setText(QStringLiteral("更改窗口标题"));
    menu->addAction(set_title);

    connect(quit, &QAction::triggered, [this](bool) {window->close(); });


    

}

Tray::Tray(InnerBrowser* window)
{
    this->window = window;
    Init();
}

void Tray::ShowMenu()
{
    menu->exec(QCursor::pos());
}