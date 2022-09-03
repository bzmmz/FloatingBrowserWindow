#pragma once
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
    void SetVisiable(bool visible);
    
    Tray(InnerBrowser* window);
    void ShowMenu();
    
public slots:
    void PopModifyTitleWindow();
    void SetWindowTitle(QString title);
private:
    void Init();
    void InitMenu();
    InnerBrowser* window;
    QSystemTrayIcon *trayicon;  //托盘核心
    QMenu *menu;
    QAction* quit;
    QAction* set_title;
};
