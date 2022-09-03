#include "ConfigManager.h"

#include <iostream>

#include "QMessageBox"
#include <QString>
#include <QTextCodec>
void BrowserConfig::to_json(json& j, const Config& config)
{
    j = json{
        {"transparent", config.transparent},
        {"css_file", config.css_file},
        {"x", config.x},
        {"y", config.y},
        {"width", config.width},
        {"height", config.height},
        {"scale", config.scale},
        {"is_transparent", config.is_transparent},
        {"room_url", config.room_url},
        {"windowtitle", config.windowtitle},
    };
}

void BrowserConfig::from_json(const json& j, Config& config)
{
    j.at("transparent").get_to(config.transparent);
    j.at("css_file").get_to(config.css_file);
    j.at("x").get_to(config.x);
    j.at("y").get_to(config.y);
    j.at("width").get_to(config.width);
    j.at("height").get_to(config.height);
    j.at("scale").get_to(config.scale);
    j.at("is_transparent").get_to(config.is_transparent);
    j.at("room_url").get_to(config.room_url);
    j.at("windowtitle").get_to(config.windowtitle);
}

void ConfigManager::ReadWholeFile(stringstream& ss, ifstream* read)
{
    char ch;
    while (ss && read->get(ch))
    {
        ss.put(ch);
    }
}

ConfigManager::ConfigManager()
{
    read = new ifstream(config_file_name);
}


void ConfigManager::LoadConfig()
{
    if (read->fail())
    {
        string s = "配置文件错误";
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QString p = QString::fromLocal8Bit(s.c_str());
        QMessageBox::warning(nullptr, p, QStringLiteral("无配置文件或配置文件损坏"),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        read->close();
    }
    else
    {
        stringstream ss;
        ReadWholeFile(ss, read);
        read->close();
        json j = json::parse(ss.str());
        try
        {
            config = j.get<BrowserConfig::Config>();
            QMessageBox::information(nullptr, QStringLiteral("成功"), QStringLiteral("加载配置文件成功"),QMessageBox::Ok);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            QMessageBox::warning(nullptr, QStringLiteral("配置文件出错"), QStringLiteral("无配置文件或配置文件损坏"),QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            read->close();
        }
        


        
    }

}

void ConfigManager::SaveConfig()
{
    json j = config;
    write = new ofstream(config_file_name, ios::out);
    *write << j.dump();
    write->close();
}

void ConfigManager::SaveCurrentConfig(QWidget* window)
{
    config.x = window->x();
    config.y = window->y();
    config.width = window->width();
    config.height = window->height();
    config.transparent = window->windowOpacity();
    config.windowtitle = window->windowTitle().toStdString();

    SaveConfig();
    
}

BrowserConfig::Config ConfigManager::GetConfig()
{
    return config;
}
