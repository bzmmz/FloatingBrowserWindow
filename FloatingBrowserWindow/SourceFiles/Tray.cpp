#include "Tray.h"
#include "InnerBrowser.h"
#include "StringHelper.h"
void Tray::Init()
{
    trayicon = new QSystemTrayIcon();
    
    InitMenu();
    trayicon->setToolTip(QStringLiteral("托盘捏"));
    trayicon->setIcon(QIcon("heart.png"));
    //绑定点击托盘的函数
    connect(trayicon, &QSystemTrayIcon::activated, window, &InnerBrowser::IconClicked);


    trayicon->show();
    ShowWindowLoadConfigInfo();
}

void Tray::InitMenu()
{
    menu = new QMenu(window);

    set_title = new QAction(menu);
    set_title->setText(QStringLiteral("更改窗口标题"));
    connect(set_title, &QAction::triggered, this, &Tray::PopModifyTitleWindow);
    menu->addAction(set_title);







    quit = new QAction(menu);
    quit->setText(QStringLiteral("退出"));
    connect(quit, &QAction::triggered, [this](bool) {window->close(); });
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

Tray::Tray(InnerBrowser* window)
{
    this->window = window;
    Init();
}

void Tray::ShowMenu()
{
    QPoint Pos;
    Pos = QCursor::pos();
    Pos.setY(Pos.y() - menu->sizeHint().height());
    menu->exec(Pos);
}

InnerBrowser* Tray::GetWindow()
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

void Tray::PopModifyTitleWindow()
{
    auto dialog = new StringInputDialog(window);

    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->show();
}

