#include "InnerBrowser.h"
void InnerBrowser::load_config()
{

    return;
}

InnerBrowser::InnerBrowser()
{
    load_config();
    this->setWindowTitle("测试窗口");
    this->setWindowOpacity(browser_config.transparent);
    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    webview = new WebView();
    this->webview->page()->setBackgroundColor(QColor(0, 0, 0, 0));
    this->webview->titleChanged(this->windowTitle());
    this->layout->addWidget(this->webview);
    this->setLayout(this->layout);


}



InnerBrowser::~InnerBrowser()
= default;

void InnerBrowser::lock(bool on)
{
    this->setWindowFlag(Qt::WindowStaysOnTopHint, on);
    this->setAttribute(Qt::WA_TranslucentBackground, on);
}

void InnerBrowser::InitWindowByConfig()
{
    this->lock(true);
    //移动窗口
    this->move(browser_config.x, browser_config.y);
    //调整窗口大小
    this->resize(browser_config.width, browser_config.height);
    //加载url
    this->webview->load(QUrl(browser_config.room_url.c_str()));
    //调节页面缩放比列
    this->webview->page()->setZoomFactor(browser_config.scale / 100.0);

}


