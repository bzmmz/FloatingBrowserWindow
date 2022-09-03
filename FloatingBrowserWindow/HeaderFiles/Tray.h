#pragma once
#include <qsystemtrayicon.h>
#include <QtWidgets/QtWidgets>
#include "InnerBrowser.h"
class InnerBrowser;
/*
 * 系统托盘的实现
 */
class Tray : public QObject
{
   
public:
    void SetVisiable(bool visible);
    void Init();
    void InitMenu();
    Tray(InnerBrowser* window);
    void ShowMenu();
private:
    InnerBrowser* window;
    QSystemTrayIcon *trayicon;  //托盘核心
    QMenu *menu;
    QAction* quit;
    QAction* set_title;
};
