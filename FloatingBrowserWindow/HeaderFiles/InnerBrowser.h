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
    void ReloadCss(QString css);
    void RemoveCss();
    QString GetCss();

private:
    //拼接脚本
    QString CombineScript(QString css);
    //用java_script脚本注入css
    void InjectCss(QString css);
    
    QString css;
    QString java_script;
    QWebEngineScript *script_engine;


    const QString JS_LOAD_CSS_FROM_STR = "'(function(){\\nlet style_node = document.createElement(\\'style\\');\\nstyle_node.append(document.createTextNode(`\\n";
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
    void SetCutomCSS(QString css);
    void SetTransparent(int transparent);
    void ClearCss();
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
    int GetTransparent();
    QString GetCss();
    CM_LoadConfigCondition GetLoadCondition();
private:
    ConfigManager manager;
    QHBoxLayout *layout;
    WebView *webview;
    Tray* tray;
    void load_config();
    void InitSystemTray();
    void ReloadCSS(QString css);
    
private slots:
    //点击托盘时的响应函数
    void IconClicked(QSystemTrayIcon::ActivationReason reason);
protected:
    void closeEvent(QCloseEvent* event) override;


};



