#pragma once
#include <Qt>
#include <QUrl>
#include <QWebEngineView>
#include <QWebEngineScript>
#include <QWidget>
#include <QHBoxLayout>
#include <string>

#include "ConfigManager.h"


class WebView : public QWebEngineView
{
    
};




/**
 * 内嵌的浏览器
 */
class InnerBrowser : public QWidget
{
private:
    BrowserConfig::Config browser_config;
    QHBoxLayout* layout;
    WebView* webview;

    void load_config();
public:
    InnerBrowser();
    ~InnerBrowser() override;
    void lock(bool on);


    void InitWindowByConfig();
};



