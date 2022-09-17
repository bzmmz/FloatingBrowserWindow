#pragma once
#include <qsystemtrayicon.h>
#include <QtWidgets/QtWidgets>
#include "PageBrowser.h"
#include "StringInputDialog.h"
#include "ControlPanel.h"
/*
 * 系统托盘的实现
 */
class Tray : public QObject
{
   Q_OBJECT
public:
    
    Tray(PageBrowser* window);
    void ShowMenu();
    PageBrowser* GetWindow();
    void ShowMessage(QString message);
    
public slots:
    void PopModifyTitleWindow();
    void PopControlPanel();
    
private:
    void Init();
    void InitMenu();
    void ShowWindowLoadConfigInfo();
    PageBrowser* window;
    QSystemTrayIcon *trayicon;  //托盘核心
    QMenu *menu;
    QAction* quit;
    QAction* control_panel;
};
