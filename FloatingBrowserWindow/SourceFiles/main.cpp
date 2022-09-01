#include <iostream>
#include <QApplication>
#include "ConfigManager.h"
#include "InnerBrowser.h"
#include <QTextCodec>
#include "ui_MainWindow.h"

//class MainWindow : public QMainWindow
//{
//
//private:
//    Ui::MainWindow ui;
//public:
//    MainWindow()
//    {
//        ui.setupUi(this);
//        auto browser = new InnerBrowser();
//        this->setCentralWidget(browser);
//    }
//};


int main(int argc, char *argv[])
{
    auto a = new QApplication(argc, argv);
    ////设置中文编码
    //QTextCodec  *codec =QTextCodec::codecForName("utf-8");


    //QTextCodec::setCodecForLocale(codec);
        

    a->setQuitOnLastWindowClosed(true);
    auto browser = new InnerBrowser();
    int code = a->exec();
    return code;

}
