#pragma once
#include <qsystemtrayicon.h>
#include <QtWidgets/QtWidgets>
#include "PageBrowser.h"
#include "ControlPanel.h"
/*
 * 系统托盘的实现
 */
class Tray : public QObject
{
    Q_OBJECT
        
public:
    friend PageBrowser;
    Tray(PageBrowser* window);
    ~Tray() override;
    void ShowMenu();
    PageBrowser* GetWindow();
    void ShowMessage(QString message);
public slots:
    void PopControlPanel();
    void SwitchShowAndHide();
    void SwitchStayOnTop();
    void SwitchMousePenertration();
    void SwitchFreeMove();
private:
    void Init();
    void InitMenu();
    void ShowWindowLoadConfigInfo();
    bool show = true;
    bool locked;
    bool mouse_penetration;
    bool can_free_move;
    PageBrowser* window;
    QSystemTrayIcon *trayicon;  //托盘核心
    QMenu *menu;
    QAction* quit;
    QAction* control_panel;
    QAction* hide_control;
    QAction* mouse_control;
    QAction* lock;
    QAction* reset_pos;
    QAction* free_move;
private slots:
    void TrayClicked(QSystemTrayIcon::ActivationReason reason);
};
