#pragma once
#include <Qt>
#include <QUrl>
#include <QWebEngineView>
#include <QWebEngineScriptCollection>
#include <string>
#include "ConfigManager.h"
#include "Tray.h"



class WebView : public QWebEngineView
{
public:
    WebView(QString css);



private:

    //用java_script脚本注入css
    void InjectCss(QString css);
    QString css;
    QString java_script;
    QWebEngineScript *script_engine;


    QString JS_LOAD_CSS_FROM_STR = "\
        (function(){\
        let style_node = document.createElement('style');\
        style_node.append(document.createTextNode(`\n%s\n`));\
        document.head.append(style_node);\
        console.log('Additional inline style sheet:\\n', style_node);\
        })();\
    ";

    QString JS_LOAD_CSS_FROM_URL = "\
        (function(){\
        let link = document.createElement('link');\
        link.href = '%s';\
        link.rel = 'stylesheet';\
        document.head.append(link);\
        console.log('Additional link to style sheet:\\n', link);\
        })();\
    ";
};




/**
 * 内嵌的浏览器
 */
class InnerBrowser : public QWidget
{
    friend class Tray;
    Q_OBJECT
public slots:
    void SetWindowTitle(QString title);
signals:
    void MainWindowCloseSignal();
public:
    InnerBrowser();
    ~InnerBrowser() override;
    void lock(bool on);
    void ApplyConfig(BrowserConfig::Config config);
    void MoveWindow(float x, float y);
    void ResizeWindows(float width, float height);
    void ScaleWindowPage(float scale);
    CM_LoadConfigCondition GetLoadCondition();
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



