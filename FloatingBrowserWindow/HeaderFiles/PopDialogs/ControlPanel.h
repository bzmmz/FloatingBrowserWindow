#pragma once
#include "Tray.h"
#include "ui_ControlPanel.h"
class Tray;
class PageBrowser;
/**
 * 控制面板
 */
class ControlPanel : public QMainWindow
{
    Q_OBJECT
public:
    ControlPanel(PageBrowser* parent);
signals:
    void ModifyTitleSignal(QString title);
    void ModifyCSSSignal(QString css);
    void ClearCssSignal();
    void ModifyTransparentSignal(int transparent);
    void ModifyPageUrlSignal(QString url);


private:
    Ui_ControlPanel ui;

private slots:
    void EditTitleConfirmClicked();
    void EditCssConfirmClicked();
    void ClearCssClicked();
    void TransparentSliderChanged();
    void TransparentNumChanged();
    void ModifyUrlClicked();
    //收到主窗口关闭的信号关闭窗口
    void ReceiveMainWindowCloseSignal();
};
