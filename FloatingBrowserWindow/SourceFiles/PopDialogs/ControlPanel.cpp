#include "ControlPanel.h"
ControlPanel::ControlPanel(PageBrowser *parent)
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
    ui.setupUi(this);

    //窗口标题修改
    ui.titleEdit->setText(parent->windowTitle());
    connect(ui.titleEditConfirm, &QAbstractButton::clicked, this, &ControlPanel::EditTitleConfirmClicked);
    connect(this, &ControlPanel::ModifyTitleSignal, parent, &PageBrowser::SetWindowTitle);
    //CSS修改
    ui.cssEdit->setPlainText(parent->GetCss());
    connect(ui.cssEditConfirm, &QAbstractButton::clicked, this, &ControlPanel::EditCssConfirmClicked);
    connect(this, &ControlPanel::ModifyCSSSignal, parent, &PageBrowser::SetCutomCSS);

    //CSS清除
    connect(ui.clearcss, &QAbstractButton::clicked, this, &ControlPanel::ClearCssClicked);
    connect(this, &ControlPanel::ClearCssSignal, parent, &PageBrowser::ClearCss);

    //透明度修改
    ui.transparentEdit->setValue(parent->GetTransparent());
    ui.transparentNum->setText(QString::number(parent->GetTransparent()));
    //限制输入框输入
    QRegExp t("[0-9]+$");

    QRegExpValidator *validator = new QRegExpValidator(t, ui.transparentNum);
    ui.transparentNum->setValidator(validator);
    ui.transparentNum->setMaxLength(3);

    //启用了跟踪的滑块拖动时就会发出信号
    connect(ui.transparentEdit, &QSlider::valueChanged, this, &ControlPanel::TransparentSliderChanged);
    connect(ui.transparentNum, &QLineEdit::editingFinished, this, &ControlPanel::TransparentNumChanged);

    connect(this, &ControlPanel::ModifyTransparentSignal, parent, &PageBrowser::SetTransparent);

    //URL修改
    ui.urlEditor->setText(parent->GetPageUrl());
    connect(ui.editUrl, &QAbstractButton::clicked, this, &ControlPanel::ModifyUrlClicked);
    connect(this, &ControlPanel::ModifyPageUrlSignal, parent, &PageBrowser::ChangeUrl);

    //绑定收到主窗口关闭信号的反应
    connect(parent, &PageBrowser::MainWindowCloseSignal, this, &ControlPanel::ReceiveMainWindowCloseSignal);
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

void ControlPanel::TransparentSliderChanged()
{
    auto t = ui.transparentEdit->value();
    ui.transparentNum->setText(QString::number(t));
    emit ModifyTransparentSignal(t);
}

void ControlPanel::TransparentNumChanged()
{
    auto t = ui.transparentNum->text().toInt();
    if (t < 0)
    {
        t = 0;
    }
    else if (t > 100)
    {
        t = 100;
    }
    ui.transparentNum->setText(QString::number(t));

    ui.transparentEdit->setValue(t);
    emit ModifyTransparentSignal(t);
}

void ControlPanel::ModifyUrlClicked()
{
    emit ModifyPageUrlSignal(ui.urlEditor->text());
}

void ControlPanel::ReceiveMainWindowCloseSignal()
{
    this->close();
}