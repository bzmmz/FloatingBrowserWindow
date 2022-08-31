#pragma once
#include "json.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
using namespace nlohmann;


namespace BrowserConfig
{
    struct Config
    {
        double transparent = 50.0f;
        std::string css_file;
        int x{};
        int y{};
        int width = 800;
        int height = 600;
        double scale = 100;
        bool is_transparent = true;
        std::string room_url = "http://localhost:12450/room/test?minGiftPrice=7&showDanmaku=true&showGift=true&showGiftName=false&mergeSimilarDanmaku=false&mergeGift=true&maxNumber=60&blockGiftDanmaku=true&blockLevel=0&blockNewbie=false&blockNotMobileVerified=false&blockKeywords=&blockUsers=&blockMedalLevel=0&relayMessagesByServer=false&autoTranslate=false&giftUsernamePronunciation=&emoticons=%5B%5D&lang=zh";
    };

    void to_json(json& j, const Config& config);

    void from_json(const json& j, Config& config);
};


class ConfigManager
{
private:
    string config_file_name = "config.json";
    ifstream *read;
    ofstream *write;
    BrowserConfig::Config config;


    inline void ReadWholeFile(stringstream& ss, ifstream *read);
public:
    ConfigManager();
    void LoadConfig();
    void SaveConfig();
    BrowserConfig::Config GetConfig();
};
