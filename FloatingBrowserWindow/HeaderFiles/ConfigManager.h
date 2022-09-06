#pragma once
#include "json.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <QtWidgets/QtWidgets>
using namespace std;
using namespace nlohmann;
class InnerBrowser;
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
        QString room_url = "http://localhost:12450/room/test?minGiftPrice=7&showDanmaku=true&showGift=true&showGiftName=false&mergeSimilarDanmaku=false&mergeGift=true&maxNumber=60&blockGiftDanmaku=true&blockLevel=0&blockNewbie=false&blockNotMobileVerified=false&blockKeywords=&blockUsers=&blockMedalLevel=0&relayMessagesByServer=false&autoTranslate=false&giftUsernamePronunciation=&emoticons=%5B%5D&lang=zh";
        QString windowtitle = QStringLiteral("新窗口");
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
    void LoadConfig();
    void SaveConfig();
    void SaveCurrentConfig(InnerBrowser* window);
    BrowserConfig::Config GetConfig();
    CM_LoadConfigCondition GetLoadConfigCondition();
};
