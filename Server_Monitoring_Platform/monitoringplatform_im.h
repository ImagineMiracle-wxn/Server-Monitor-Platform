#pragma once
#ifndef MONITORINGPLATFORM_IM_H
#define MONITORINGPLATFORM_IM_H

#include "monitorthread_im.h"
#include "timethread_im.h"
#include "email_im.h"
#include "typelist.h"
#include "emailconfigure.h"
#include "about_im.h"

#include <QList>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QMap>
#include <QIcon>
#include <QScreen>
#include <QTextedit>

#include <QMenuBar>
#include <QMenu>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MonitoringPlatform_IM; }
QT_END_NAMESPACE

class MonitoringPlatform_IM;

// 线程类型
enum ThreadType {
    TimeThread = 0,
    MonitorThread = 1,
};

typedef struct TimeThread_Args {

    QLabel *dispaly_Lab;        // 显示软件运行总时长标签
    QLCDNumber *LcdNum_DateTime;    // 显示当前时间的 LCD
} TimeThread_Args;  // 时间线程参数

typedef struct Thread_ListNode {
    int id;
    ThreadType type;
    void *threadPoint;
} Thread_ListNode;  // 线程链表节点

typedef struct MainMenuActionModeule {
    QAction *action;       // 行为
    QString name;          // 行为名称
    void (MonitoringPlatform_IM::*func) (); // 行为函数
} MainMenuActionModeule;    // 主菜单行为模组

typedef struct  MainMenuModule {
    QMenu *menu;        // 菜单
    QString name;       // 菜单名
    QList<MainMenuActionModeule> actionList;    // 菜单行为列表
} MainMenuModule;  // 主菜单模组



class MonitoringPlatform_IM : public QWidget
{
    Q_OBJECT

public:

    QList<int> EmailTime;   // 每天发送时间，小时
    //int EmailTime[EMAILSENDTIMES]; // 每天发送时间，小时

    MonitoringPlatform_IM(QWidget *parent = nullptr);
    ~MonitoringPlatform_IM();


    void Init_EmailTime();  // 初始化邮件发送时间
    void Init_Parameters(); // 初始化类成员变量

    void Init_EmailConfigure(); // 初始化邮件配置类成员

    void Init_AboutIM(void);    // 初始化介绍类

    void Init_Ui(void);     // 初始化 UI 界面空间

    void Init_MenuBar(void);    // 初始化菜单栏

    void Init_TimeThread(void); // 创建并初始化时间显示线程

    void Init_Email_IM(void);   // 初始化邮件类成员

    void Init_MonitorThread(void);  // 初始化监控线程

    void AddServerToList(QString ip, QString username, QString admin, QString hostname);     // 添加服务器信息到列表

    void ConnectSignalToEmailSlot();    // 绑定信号和邮件服务槽函数

    void StartThreads(void);    // 启动所有线程

    void ShowThreadNode_ByID(int id);   // 根据线程 ID 显示该线程信息

    void GabageCollection(void);  // 内存回收函数，释放所有动态申请的内存空间

    // 为主菜单模块添加行为函数
    void NewActionForMainMenu(MainMenuModule *mainMenu, QString actionName, void (MonitoringPlatform_IM::*func) (void), QString icoPath = "");

    // 关于“设置”菜单的行为函数-----------start

    void ShowEmailConfigure(void);  // 显示邮件设置类界面

    // 关于“设置”菜单的行为函数-----------end

    // 关于“启动”菜单的行为函数-----------start

    void EmailServiceStart(void);  // 启动邮件服务

    // 关于“启动”菜单的行为函数-----------end

    // 关于“工具”菜单的行为函数-----------start

    void MonitorThreadReConnect(void);  // 重连断线的线程

    // 关于“工具”菜单的行为函数-----------end

    // 关于“关于”菜单的行为函数-----------start

    void ShowAboutIM(void);  // 打开关于界面

    // 关于“关于”菜单的行为函数-----------end



signals:
    //void Test_SendLabToMonitorThread(QLabel *);

    void EmailSendEn_Signal(bool sig);

public slots:
    void RiskDisplayMode_Slot(int);

    void SafeDisplayMode_Slot(int);

    void FlushMainWindow(void);     // 刷新主界面

    void ClearTextEditor_Slot(void);



protected:
    void changeEvent(QEvent * event);

private slots:
    void on_CheckBox_Email_En_stateChanged(int arg1);

    void on_CheckBox_Email_En_clicked();

private:
    Ui::MonitoringPlatform_IM *ui;

    TimeThread_IM *timeThread;  // 时间线程

    Email_IM * eMail_IM;        // 邮件类成员
    bool *urgentMutex;  // 紧急信号锁 true: 空闲，可发送紧急信号;  false: 忙，等待解锁
    bool *displayMutex; // 显示锁

    QMap<int, QLabel*> displayLabelMap;     // 显示标签 map
    QList<Thread_ListNode *> threadList;    // 线程列表
    QList<ServerDetail_IM *> serverDetailList;  // 服务器信息与状态列表
    bool *eMailSend_EN;  // 日常邮件发送使能 true: 开启日常邮件发送功能， false: 关闭日常邮件发送功能

    EmailConfigure *emailConfigure; // 邮件配置类成员

    QMenuBar * masterMenuBar;   // 主菜单栏
    QList<MainMenuModule *> mainMenuList;    // 菜单模块

    bool *eMailSevice_EN;   // 邮件服务系统锁

    About_IM *aboutIM;  // 自介绍类成员

    QTextEdit *textEditor;  //

};
#endif // MONITORINGPLATFORM_IM_H
