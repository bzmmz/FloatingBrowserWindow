#pragma once
#include <QString>
#include <string>
//令DEBUG模式下DBP有效，用来输出一些调试信息
#ifdef _DEBUG
#include <cstdio>
#define DBP(...) printf(__VA_ARGS__)
#else
#define DBP(...)
#endif


namespace SH
{
    inline QString str2qstr(std::string s)
    {
        return QString::fromLocal8Bit(s.data());
    }

    inline std::string qstr2str(QString s)
    {
        QByteArray s_data = s.toLocal8Bit();
        return std::string(s_data);
    }

    inline QString utf8_2_gbk(QString &s)
    {
        QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
        QTextCodec* gbk = QTextCodec::codecForName("GBK");
#ifdef _DEBUG
        QByteArray origin = s.toLocal8Bit();
        DBP("Origin utf-8 bytes:\n");
        for (auto p : origin)
        {
            DBP("%x\n", static_cast<unsigned char>(p));
        }
#endif
        QString unicode = utf8->toUnicode(s.toLocal8Bit().data());
        QByteArray gbk_bytes = gbk->fromUnicode(unicode);
#ifdef _DEBUG
        DBP("gbk bytes:\n");
        for (auto p : gbk_bytes)
        {
            DBP("%x\n", static_cast<unsigned char>(p));
        }
#endif
        s = QString::fromLocal8Bit(gbk_bytes);
        return s;
    }

    inline QString gbk_2_utf8(QString &s)
    {
        QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
        QTextCodec* gbk = QTextCodec::codecForName("GBK");
#ifdef _DEBUG
        QByteArray origin = s.toLocal8Bit();
        DBP("Origin gbk bytes:\n");
        for (auto p : origin)
        {
            DBP("%x\n", static_cast<unsigned char>(p));
        }
#endif

        QString unicode = gbk->toUnicode(s.toLocal8Bit().data());
        QByteArray utf8_bytes = utf8->fromUnicode(unicode);
#ifdef _DEBUG
        DBP("utf-8 bytes:\n");
        for (auto p : utf8_bytes)
        {
            DBP("%x\n", static_cast<unsigned char>(p));
        }
#endif
        s = QString::fromLocal8Bit(utf8_bytes);
        return s;
    }

    


}
