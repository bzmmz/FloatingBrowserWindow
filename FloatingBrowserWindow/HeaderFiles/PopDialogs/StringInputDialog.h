#pragma once
#include "ui_StringInputDialog.h"
#include "Tray.h"
#include "PageBrowser.h"
class Tray;
class PageBrowser;
/*
 * 按钮改成汉字，留下修改样式的空间
 */
class StringInputDialog : public QMainWindow
{
    Q_OBJECT

public:
    StringInputDialog(PageBrowser* parent);
signals:
    void ModifyTitleSignal(QString title);
private:
    Ui_StringInputDialog ui;


private slots:
    void OkClicked();
    //收到主窗口关闭的信号关闭窗口
    void ReceiveMainWindowCloseSignal();


};
