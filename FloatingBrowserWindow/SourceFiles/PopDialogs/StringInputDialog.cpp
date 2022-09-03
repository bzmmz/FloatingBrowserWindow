#include "StringInputDialog.h"
StringInputDialog::StringInputDialog(Tray* parent)
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    setWindowFlags(flags);
    setFixedSize(400, 300);
    ui.setupUi(this);
    connect(ui.OkButton, &QAbstractButton::clicked, this, &StringInputDialog::OkClicked);
    connect(ui.CancelButton, &QAbstractButton::clicked, this, &QWidget::close);
    connect(this, &StringInputDialog::ModifyTitleSignal, parent, &Tray::SetWindowTitle);
    connect(this, &StringInputDialog::ModifyTitleSignal, this, &QWidget::close);
}


void StringInputDialog::OkClicked()
{
    emit ModifyTitleSignal(ui.textEdit->toPlainText());
}
