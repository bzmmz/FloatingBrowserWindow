#pragma once
#include <Qt>
#include <QUrl>
#include <QWebEngineView>
#include <QWebEngineScript>
#include <QMainWindow>
#include <QHBoxLayout>
#include <string>
#include "ConfigManager.h"
#include "Tray.h"

class WebView : public QWebEngineView
{
    
};




/**
 * 内嵌的浏览器
 */
class InnerBrowser : public QWidget
{
    friend class Tray;
public:
    InnerBrowser();
    ~InnerBrowser() override;
    void lock(bool on);
    void ApplyConfig(BrowserConfig::Config config);
    void MoveWindow(float x, float y);
    void ResizeWindows(float width, float height);
    void ScaleWindowPage(float scale);
private:
    ConfigManager manager;
    QHBoxLayout *layout;
    WebView *webview;
    Tray* tray;
    void load_config();
    void InitSystemTray();
private slots:
    //点击托盘时的响应函数
    void IconClicked(QSystemTrayIcon::ActivationReason reason); 
    
protected:
    void closeEvent(QCloseEvent* event) override;


};



