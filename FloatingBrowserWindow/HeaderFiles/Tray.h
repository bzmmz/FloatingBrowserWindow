#pragma once
#include <qsystemtrayicon.h>
#include <QtWidgets/QtWidgets>
#include "InnerBrowser.h"
#include "StringInputDialog.h"
#include "ControlPanel.h"
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
    void PopControlPanel();
    
private:
    void Init();
    void InitMenu();
    void ShowWindowLoadConfigInfo();
    InnerBrowser* window;
    QSystemTrayIcon *trayicon;  //托盘核心
    QMenu *menu;
    QAction* quit;
    QAction* set_title;
    QAction* control_panel;
};
