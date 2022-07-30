/********************************************************************************
** Form generated from reading UI file 'FloatingBrowserWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOATINGBROWSERWINDOW_H
#define UI_FLOATINGBROWSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FloatingBrowserWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FloatingBrowserWindowClass)
    {
        if (FloatingBrowserWindowClass->objectName().isEmpty())
            FloatingBrowserWindowClass->setObjectName(QString::fromUtf8("FloatingBrowserWindowClass"));
        FloatingBrowserWindowClass->resize(600, 400);
        menuBar = new QMenuBar(FloatingBrowserWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        FloatingBrowserWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FloatingBrowserWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FloatingBrowserWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(FloatingBrowserWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        FloatingBrowserWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FloatingBrowserWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FloatingBrowserWindowClass->setStatusBar(statusBar);

        retranslateUi(FloatingBrowserWindowClass);

        QMetaObject::connectSlotsByName(FloatingBrowserWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *FloatingBrowserWindowClass)
    {
        FloatingBrowserWindowClass->setWindowTitle(QCoreApplication::translate("FloatingBrowserWindowClass", "FloatingBrowserWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FloatingBrowserWindowClass: public Ui_FloatingBrowserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOATINGBROWSERWINDOW_H
