#pragma once
#include <QString>
#include <string>
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
}
