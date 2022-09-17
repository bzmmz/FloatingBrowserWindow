#include <iostream>
#include <QApplication>
#include "ConfigManager.h"
#include "PageBrowser.h"
#include "StringHelper.h"
#include <QTextCodec>
void Test()
{
    QString test_str = "啊哈";
    SH::utf8_2_gbk(test_str);
}

int main(int argc, char *argv[])
{
    auto a = new QApplication(argc, argv);
    ////设置中文编码
    QTextCodec  *codec =QTextCodec::codecForName("utf-8");


    QTextCodec::setCodecForLocale(codec);
    //Test();
    a->setQuitOnLastWindowClosed(false);
    auto browser = new PageBrowser();
    a->setWindowIcon(QIcon(":image/ruby.icon"));
    int code = a->exec();
    delete browser;
    DBP("OVER");
    return code;

}
