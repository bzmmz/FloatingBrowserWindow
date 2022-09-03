#pragma once
#include "ui_StringInputDialog.h"
#include "Tray.h"
class Tray;
/*
 * 按钮改成汉字，留下修改样式的空间
 */
class StringInputDialog : public QMainWindow
{
    Q_OBJECT
public:
    StringInputDialog(Tray* parent);
signals:
    void ModifyTitleSignal(QString title);
private:
    Ui_StringInputDialog ui;


private slots:
    void OkClicked();


};
