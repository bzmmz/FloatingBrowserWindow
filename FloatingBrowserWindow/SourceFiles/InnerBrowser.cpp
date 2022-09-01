﻿#include "InnerBrowser.h"
#include <QString>
void InnerBrowser::load_config()
{
    manager.LoadConfig();
    return;
}

void InnerBrowser::closeEvent(QCloseEvent* event)
{
    manager.SaveCurrentConfig(this);
}

InnerBrowser::InnerBrowser()
{
    
    load_config();
    auto config = manager.GetConfig();
    this->lock(true);
    //移动窗口
    this->move(config.x, config.y);
    //调整窗口大小
    this->resize(config.width, config.height);
    //调节页面缩放比列
    //调节透明度
    this->setWindowOpacity(config.transparent);


    this->setWindowTitle(QString::fromLocal8Bit(config.windowtitle.c_str()));
    
    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    webview = new WebView();
    this->webview->page()->setBackgroundColor(QColor(0, 0, 0, 0));
    this->webview->titleChanged(this->windowTitle());
    this->layout->addWidget(this->webview);
    this->setLayout(this->layout);

    
    //移动和缩放
    this->MoveWindow(config.x, config.y);
    this->ResizeWindows(config.width, config.height);
    
    this->webview->load(QUrl(QString::fromStdString(config.room_url)));
    this->ScaleWindowPage(config.scale);
    this->show();

}



InnerBrowser::~InnerBrowser()
= default;

void InnerBrowser::lock(bool on)
{
    this->setWindowFlag(Qt::WindowStaysOnTopHint, on);
    this->setAttribute(Qt::WA_TranslucentBackground, on);
}

void InnerBrowser::ApplyConfig(BrowserConfig::Config config)
{
}

void InnerBrowser::MoveWindow(float x, float y)
{
    this->move(x, y);
}

void InnerBrowser::ResizeWindows(float width, float height)
{
    this->resize(width, height);
}

void InnerBrowser::ScaleWindowPage(float scale)
{
    this->webview->page()->setZoomFactor(scale);
}

