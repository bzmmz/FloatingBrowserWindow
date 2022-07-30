#include <iostream>
#include <QApplication>
#include "ConfigManager.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ////设置中文编码
    //QTextCodec  *codec =QTextCodec::codecForName("utf-8");


    //QTextCodec::setCodecForLocale(codec);
        
    auto config_manager = new ConfigManager();
    config_manager->LoadConfig();
    config_manager->SaveConfig();
    return 0;
}
