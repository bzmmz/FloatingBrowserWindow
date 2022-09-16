#include "ControlPanel.h"
ControlPanel::ControlPanel(InnerBrowser* parent)
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
    ui.setupUi(this);

    //窗口标题修改
    ui.titleEdit->setText(parent->windowTitle());
    connect(ui.titleEditConfirm, &QAbstractButton::clicked, this, &ControlPanel::EditTitleConfirmClicked);
    connect(this, &ControlPanel::ModifyTitleSignal, parent, &InnerBrowser::SetWindowTitle);
    //CSS修改
    ui.cssEdit->setPlainText(parent->GetCss());
    connect(ui.cssEditConfirm, &QAbstractButton::clicked, this, &ControlPanel::EditCssConfirmClicked);
    connect(this, &ControlPanel::ModifyCSSSignal, parent, &InnerBrowser::SetCutomCSS);

    //CSS清除
    connect(ui.clearcss, &QAbstractButton::clicked, this, &ControlPanel::ClearCssClicked);
    connect(this, &ControlPanel::ClearCssSignal, parent, &InnerBrowser::ClearCss);


    //透明度修改
    //todo



    //绑定收到主窗口关闭信号的反应
    connect(parent, &InnerBrowser::MainWindowCloseSignal,this, &ControlPanel::ReceiveMainWindowCloseSignal);
}

void ControlPanel::EditTitleConfirmClicked()
{
    emit ModifyTitleSignal(ui.titleEdit->toPlainText());
}

void ControlPanel::EditCssConfirmClicked()
{
    emit ModifyCSSSignal(ui.cssEdit->toPlainText());
}

void ControlPanel::ClearCssClicked()
{
    ui.cssEdit->clear();
    emit ClearCssSignal();
}

void ControlPanel::ReceiveMainWindowCloseSignal()
{
    this->close();
}
