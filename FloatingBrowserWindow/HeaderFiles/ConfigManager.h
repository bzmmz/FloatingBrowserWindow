#pragma once
#include "json.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <QtWidgets/QtWidgets>
using namespace std;
using namespace nlohmann;
class PageBrowser;
namespace BrowserConfig
{
    struct Config
    {
        double transparent = 50.0f;
        QString css;
        int x{};
        int y{};
        int width = 800;
        int height = 600;
        double scale = 100;
        bool is_transparent = true;
        QString page_url = "localhost";
        QString windowtitle = QStringLiteral("新窗口");
        bool lock = false;
        bool mouse_penetration = false;
    };

    void to_json(json& j, const Config& config);

    void from_json(const json& j, Config& config);



};
enum CM_LoadConfigCondition
{
    CM_NO_CONFIG_FILE,
    CM_ERROR_CONFIG_FILE,
    CM_SUCCESS_LOAD_FILE
};

class ConfigManager
{
    
private:
    string config_file_name = "config.json";
    ifstream *read;
    ofstream *write;
    BrowserConfig::Config config;
    CM_LoadConfigCondition load_config_condition;

    inline void ReadWholeFile(stringstream& ss, ifstream *read);
public:
    
    ConfigManager();
    ~ConfigManager();
    void LoadConfig();
    void SaveConfig();
    void SaveCurrentConfig(PageBrowser* window);
    void SetTransparent(double transparent);
    void SetUrl(QString url);
    void SetLock(bool locked);
    void SetMousePenertration(bool m);
    QString GetUrl();
    BrowserConfig::Config GetConfig();
    CM_LoadConfigCondition GetLoadConfigCondition();
};
