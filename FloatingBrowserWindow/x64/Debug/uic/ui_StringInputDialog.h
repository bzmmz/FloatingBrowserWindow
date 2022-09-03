/********************************************************************************
** Form generated from reading UI file 'StringInputDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRINGINPUTDIALOG_H
#define UI_STRINGINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StringInputDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(452, 344);
        gridLayoutWidget = new QWidget(Form);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 411, 321));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout->setContentsMargins(10, 0, 10, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        OkButton = new QPushButton(gridLayoutWidget);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223 Medium"));
        font.setPointSize(11);
        OkButton->setFont(font);

        horizontalLayout->addWidget(OkButton);

        CancelButton = new QPushButton(gridLayoutWidget);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setFont(font);

        horizontalLayout->addWidget(CancelButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(400, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223 Medium"));
        font1.setPointSize(13);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(300, 50));
        textEdit->setFont(font);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        OkButton->setText(QCoreApplication::translate("Form", "\347\241\256\350\256\244", nullptr));
        CancelButton->setText(QCoreApplication::translate("Form", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("Form", "\350\257\267\350\276\223\345\205\245\346\226\260\347\252\227\345\217\243\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_StringInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRINGINPUTDIALOG_H
