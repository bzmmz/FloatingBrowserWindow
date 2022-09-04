#include "StringInputDialog.h"
StringInputDialog::StringInputDialog(InnerBrowser* parent)
{
    setStyle(QStyleFactory::create("fusion"));
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint | Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
    setFixedSize(400, 250);
    ui.setupUi(this);
    //ui.textEdit->setText(parent->windowTitle());
    connect(ui.OkButton, &QAbstractButton::clicked, this, &StringInputDialog::OkClicked);
    connect(ui.CancelButton, &QAbstractButton::clicked, this, &QWidget::close);
    connect(this, &StringInputDialog::ModifyTitleSignal, parent, &InnerBrowser::SetWindowTitle);
    connect(this, &StringInputDialog::ModifyTitleSignal, this, &QWidget::close);

    //绑定收到主窗口关闭信号的反应
    connect(parent, &InnerBrowser::MainWindowCloseSignal,this, &StringInputDialog::ReceiveMainWindowCloseSignal);
}


void StringInputDialog::OkClicked()
{
    emit ModifyTitleSignal(ui.textEdit->toPlainText());
}

void StringInputDialog::ReceiveMainWindowCloseSignal()
{
    this->close();
}
