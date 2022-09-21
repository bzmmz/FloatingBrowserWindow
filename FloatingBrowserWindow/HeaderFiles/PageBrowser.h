#pragma once
#include <Qt>
#include <QUrl>
#include <QWebEngineView>
#include <QWebEngineScriptCollection>
#include <string>
#include "ConfigManager.h"
#include "Tray.h"
#include <Windows.h>
class WebView : public QWebEngineView
{
public:
    WebView(QString css, PageBrowser *parent);
    void ReloadCss(QString css);
    void RemoveCss();
    void LoadUrl(QString url);
    QString GetCss();
    void SetMouseEventTransparent(bool m);
    void SetFreeMove(bool m);
private:
    //拼接脚本
    QString CombineScript(QString css);
    //用java_script脚本注入css
    void InjectCss(QString css);
    PageBrowser *parent;
    QString css;
    QString java_script;
    QWebEngineScript *script_engine;
    bool mouse_transparent = false;
    bool free_move = true;

    const QString JS_LOAD_CSS_FROM_STR = "'(function(){\\nlet style_node = document.createElement(\\'style\\');\\nstyle_node.append(document.createTextNode(`\\n";
protected:
    //鼠标任意位置拖拽
    //QWebEngineView不能直接响应MouseEvent,需要重载eventFilter和event两个函数,
    //event函数中捕获QEvent::ChildPolished产生的child(QOpenGLWidget),然后注册其eventfilter为this
    //之后在eventfilter中捕获相关的event来处理
    QObject *child;
    bool eventFilter(QObject *obj, QEvent *event) override;
    bool event(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    bool be_draggd = false;
    QPoint mouse_start_point;
    QPoint window_pos;
};

/**
 * 内嵌的浏览器
 */
class PageBrowser : public QWidget
{
    friend class Tray;
    Q_OBJECT
public slots:
    void SetWindowTitle(QString title);
    void SetCutomCSS(QString css);
    void SetTransparent(int transparent);
    void ClearCss();
    void ChangeUrl(QString url);
    void lock(bool locked);
signals:
    void MainWindowCloseSignal();
public:
    PageBrowser();
    ~PageBrowser() override;
    void ApplyConfig(BrowserConfig::Config config);
    void MoveWindow(float x, float y);
    void ResizeWindows(float width, float height);
    void ScaleWindowPage(float scale);
    void SetMouseEventTransparent(bool m);
    void SetFreeMove(bool move);
    int GetTransparent();

    QString GetCss();
    QString GetPageUrl();
    CM_LoadConfigCondition GetLoadCondition();
private:
    ConfigManager *manager;
    QHBoxLayout *layout;
    WebView *webview;
    Tray *tray;
    QApplication *main;
    void load_config();
    void InitSystemTray();
    void ReloadCSS(QString css);
    bool refresh = false;

private slots:
    //点击托盘时的响应函数
    void IconClicked(QSystemTrayIcon::ActivationReason reason);
protected:
    void closeEvent(QCloseEvent *event) override;
    void paintEvent(QPaintEvent* event) override;
};
