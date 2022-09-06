/********************************************************************************
** Form generated from reading UI file 'ControlPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANEL_H
#define UI_CONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanel
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *WindowTitle;
    QLabel *label_3;
    QTextEdit *titleEdit;
    QPushButton *titleEditConfirm;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *CSS;
    QLabel *label_2;
    QPlainTextEdit *cssEdit;
    QPushButton *cssEditConfirm;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *transparent;
    QLabel *label;
    QSlider *transparentEdit;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ControlPanel)
    {
        if (ControlPanel->objectName().isEmpty())
            ControlPanel->setObjectName(QString::fromUtf8("ControlPanel"));
        ControlPanel->resize(1009, 1066);
        ControlPanel->setMinimumSize(QSize(800, 600));
        ControlPanel->setMaximumSize(QSize(1920, 1080));
        centralwidget = new QWidget(ControlPanel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        WindowTitle = new QHBoxLayout();
        WindowTitle->setObjectName(QString::fromUtf8("WindowTitle"));
        WindowTitle->setSizeConstraint(QLayout::SetMinimumSize);
        WindowTitle->setContentsMargins(10, 10, 10, 10);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(200, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223"));
        font.setPointSize(16);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        WindowTitle->addWidget(label_3);

        titleEdit = new QTextEdit(centralwidget);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));
        titleEdit->setEnabled(true);
        titleEdit->setMaximumSize(QSize(400, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        titleEdit->setFont(font1);
        titleEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        titleEdit->setLayoutDirection(Qt::LeftToRight);

        WindowTitle->addWidget(titleEdit);

        titleEditConfirm = new QPushButton(centralwidget);
        titleEditConfirm->setObjectName(QString::fromUtf8("titleEditConfirm"));
        titleEditConfirm->setMaximumSize(QSize(16777215, 40));
        titleEditConfirm->setFont(font);
        titleEditConfirm->setCursor(QCursor(Qt::PointingHandCursor));

        WindowTitle->addWidget(titleEditConfirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        WindowTitle->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(WindowTitle);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        CSS = new QHBoxLayout();
        CSS->setObjectName(QString::fromUtf8("CSS"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);

        CSS->addWidget(label_2);

        cssEdit = new QPlainTextEdit(centralwidget);
        cssEdit->setObjectName(QString::fromUtf8("cssEdit"));
        cssEdit->setMinimumSize(QSize(200, 600));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\200\235\346\272\220\345\256\213\344\275\223"));
        font3.setPointSize(12);
        cssEdit->setFont(font3);

        CSS->addWidget(cssEdit);

        cssEditConfirm = new QPushButton(centralwidget);
        cssEditConfirm->setObjectName(QString::fromUtf8("cssEditConfirm"));
        cssEditConfirm->setMaximumSize(QSize(16777215, 40));
        cssEditConfirm->setFont(font);
        cssEditConfirm->setCursor(QCursor(Qt::PointingHandCursor));

        CSS->addWidget(cssEditConfirm);


        verticalLayout->addLayout(CSS);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer_2);

        transparent = new QHBoxLayout();
        transparent->setObjectName(QString::fromUtf8("transparent"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        transparent->addWidget(label);

        transparentEdit = new QSlider(centralwidget);
        transparentEdit->setObjectName(QString::fromUtf8("transparentEdit"));
        transparentEdit->setMaximumSize(QSize(300, 30));
        transparentEdit->setMaximum(100);
        transparentEdit->setValue(100);
        transparentEdit->setOrientation(Qt::Horizontal);

        transparent->addWidget(transparentEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        transparent->addItem(horizontalSpacer);


        verticalLayout->addLayout(transparent);


        gridLayout->addLayout(verticalLayout, 0, 3, 1, 1);

        ControlPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ControlPanel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1009, 26));
        ControlPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(ControlPanel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ControlPanel->setStatusBar(statusbar);

        retranslateUi(ControlPanel);

        QMetaObject::connectSlotsByName(ControlPanel);
    } // setupUi

    void retranslateUi(QMainWindow *ControlPanel)
    {
        ControlPanel->setWindowTitle(QCoreApplication::translate("ControlPanel", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("ControlPanel", "\344\277\256\346\224\271\347\252\227\345\217\243\346\240\207\351\242\230", nullptr));
        titleEditConfirm->setText(QCoreApplication::translate("ControlPanel", "\347\241\256\350\256\244", nullptr));
        label_2->setText(QCoreApplication::translate("ControlPanel", "\350\207\252\345\256\232\344\271\211CSS", nullptr));
        cssEditConfirm->setText(QCoreApplication::translate("ControlPanel", "\347\241\256\350\256\244", nullptr));
        label->setText(QCoreApplication::translate("ControlPanel", "\351\200\217\346\230\216\345\272\246\350\260\203\350\212\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControlPanel: public Ui_ControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANEL_H
