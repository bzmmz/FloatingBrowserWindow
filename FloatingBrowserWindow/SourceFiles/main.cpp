#include <iostream>
#include <QApplication>
#include "ConfigManager.h"
#include "InnerBrowser.h"
#include <QTextCodec>

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