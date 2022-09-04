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
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *StringInputDialog)
    {
        if (StringInputDialog->objectName().isEmpty())
            StringInputDialog->setObjectName(QString::fromUtf8("StringInputDialog"));
        StringInputDialog->resize(414, 241);
        widget = new QWidget(StringInputDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 11, 371, 211));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(10, 0, 10, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(400, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223 Medium"));
        font.setPointSize(13);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        OkButton = new QPushButton(widget);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223 Medium"));
        font1.setPointSize(11);
        OkButton->setFont(font1);

        horizontalLayout->addWidget(OkButton);

        CancelButton = new QPushButton(widget);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setFont(font1);

        horizontalLayout->addWidget(CancelButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(300, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN Bold"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        textEdit->setFont(font2);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);


        retranslateUi(StringInputDialog);

        QMetaObject::connectSlotsByName(StringInputDialog);
    } // setupUi

    void retranslateUi(QWidget *StringInputDialog)
    {
        StringInputDialog->setWindowTitle(QCoreApplication::translate("StringInputDialog", "\344\277\256\346\224\271\347\252\227\345\217\243\345\220\215\347\247\260", nullptr));
        label->setText(QCoreApplication::translate("StringInputDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\347\252\227\345\217\243\345\220\215\347\247\260", nullptr));
        OkButton->setText(QCoreApplication::translate("StringInputDialog", "\347\241\256\350\256\244", nullptr));
        CancelButton->setText(QCoreApplication::translate("StringInputDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StringInputDialog: public Ui_StringInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRINGINPUTDIALOG_H
