﻿#pragma once
#include <qsystemtrayicon.h>
#include <QtWidgets/QtWidgets>
#include "InnerBrowser.h"
#include "StringInputDialog.h"
class InnerBrowser;
/*
 * 系统托盘的实现
 */
class Tray : public QObject
{
   Q_OBJECT
public:
    
    Tray(InnerBrowser* window);
    void ShowMenu();
    InnerBrowser* GetWindow();
    void ShowMessage(QString message);
    
public slots:
    void PopModifyTitleWindow();
    
    
private:
    void Init();
    void InitMenu();
    void ShowWindowLoadConfigInfo();
    InnerBrowser* window;
    QSystemTrayIcon *trayicon;  //托盘核心
    QMenu *menu;
    QAction* quit;
    QAction* set_title;
};
