#include "ConfigManager.h"
#include <iostream>
#include <QString>
#include "InnerBrowser.h"
#include "StringHelper.h"
void BrowserConfig::to_json(json& j, const Config& config)
{
    j = json{
        {"transparent", config.transparent},
        {"css", SH::qstr2str(config.css)},
        {"x", config.x},
        {"y", config.y},
        {"width", config.width},
        {"height", config.height},
        {"scale", config.scale},
        {"is_transparent", config.is_transparent},
        {"page_url", SH::qstr2str(config.page_url)},
        {"windowtitle", SH::qstr2str(config.windowtitle)},
    };
}

void BrowserConfig::from_json(const json& j, Config& config)
{
    j.at("transparent").get_to(config.transparent);
    config.css = SH::str2qstr(j.at("css").get<string>());
    j.at("x").get_to(config.x);
    j.at("y").get_to(config.y);
    j.at("width").get_to(config.width);
    j.at("height").get_to(config.height);
    j.at("scale").get_to(config.scale);
    j.at("is_transparent").get_to(config.is_transparent);
    config.page_url = SH::str2qstr(j.at("page_url").get<string>());
    config.windowtitle = SH::str2qstr(j.at("windowtitle").get<string>());
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
        load_config_condition = CM_NO_CONFIG_FILE;
    }
    else
    {
        stringstream ss;
        ReadWholeFile(ss, read);
        read->close();
        try
        {
            json j = json::parse(ss.str());
            try
            {
                config = j.get<BrowserConfig::Config>();
                load_config_condition = CM_SUCCESS_LOAD_FILE;
            }
            catch(const std::exception& e)
            {
                load_config_condition = CM_ERROR_CONFIG_FILE;
            }
        }
        catch (const std::exception& e)
        {
            load_config_condition = CM_ERROR_CONFIG_FILE;
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

void ConfigManager::SaveCurrentConfig(InnerBrowser* window)
{
    config.x = window->x();
    config.y = window->y();
    config.width = window->width();
    config.height = window->height();
    config.transparent = window->windowOpacity();
    config.windowtitle = window->windowTitle();
    config.css = window->GetCss();

    SaveConfig();
    
}

void ConfigManager::SetTransparent(double transparent)
{
    config.transparent = transparent;
}

void ConfigManager::SetUrl(QString url)
{
    config.page_url = url;
}

QString ConfigManager::GetUrl()
{
    return config.page_url;
}

BrowserConfig::Config ConfigManager::GetConfig()
{
    return config;
}

CM_LoadConfigCondition ConfigManager::GetLoadConfigCondition()
{
    return load_config_condition;
}
