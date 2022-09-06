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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StringInputDialog
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QTextEdit *textEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(425, 299);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(10, -1, 10, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        OkButton = new QPushButton(centralwidget);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223 Medium"));
        font.setPointSize(11);
        OkButton->setFont(font);

        horizontalLayout->addWidget(OkButton);

        CancelButton = new QPushButton(centralwidget);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setFont(font);

        horizontalLayout->addWidget(CancelButton);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        textEdit->setMaximumSize(QSize(300, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\200\235\346\272\220\351\273\221\344\275\223 CN Bold"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        textEdit->setFont(font1);
        textEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));

        gridLayout->addWidget(textEdit, 2, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(400, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223 Medium"));
        font2.setPointSize(13);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 425, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("StringInputDialog", "\344\277\256\346\224\271\347\252\227\345\217\243\345\220\215\347\247\260", nullptr));
        OkButton->setText(QCoreApplication::translate("StringInputDialog", "\347\241\256\350\256\244", nullptr));
        CancelButton->setText(QCoreApplication::translate("StringInputDialog", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("StringInputDialog", "\350\257\267\350\276\223\345\205\245\346\226\260\347\252\227\345\217\243\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StringInputDialog: public Ui_StringInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRINGINPUTDIALOG_H
