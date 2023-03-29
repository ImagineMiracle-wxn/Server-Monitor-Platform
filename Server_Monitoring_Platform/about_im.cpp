#include "about_im.h"
#include "ui_about_im.h"

About_IM::About_IM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About_IM)
{
    ui->setupUi(this);
    this->Init_UI();
}

About_IM::~About_IM()
{
    delete ui;
}

void About_IM::Init_UI()
{
    // 设置整体背景图片
    QPalette pa(this->palette());

    QImage img = QImage(":/img/img/bg01.png");
    img = img.scaled(this->size());

    QBrush *pic = new QBrush(img);

    pa.setBrush(QPalette::Window, *pic);
    this->setPalette(pa);

    this->setWindowTitle(QString("About"));

    // 设置 label 背景图片
    this->ui->Lab_Logo->setText("");
    this->ui->Lab_Logo->resize(100, 100);
    this->ui->Lab_Logo->setStyleSheet("QLabel{""background-image:url(:/img/img/logo100x100.png);""background-position:top right;""background-origin:content;""background-repeat:none;""}");

    this->ui->Lab_AppVersionV->setText(QString(ABOUTVERSION));
    this->ui->Lab_AppTimeV->setText(QString(ABOUTRELEASETIME));

    // 设置软件描述
    this->ui->Lab_AppNoteV->setText(QString("      本软件可实时监测获取服务器运行状态及服务温度等信息，并可\n通过设置邮件服务实现日常服务器状态邮件通知和服务器异常状态及\n时邮件通知。\n      感谢使用本软件。"));
}
