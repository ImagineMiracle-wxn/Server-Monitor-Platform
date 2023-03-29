#pragma once
#ifndef TYPELIST_H
#define TYPELIST_H

#include <QString>
#include <QDateTime>
#include <QString>

#define MAXSAFETEMPATURE    (65)    // 最高安全温度
#define POWEROFFTEMPATURE   (75)    // 超过 75 度强制系统关机

#define EMAILSENDTIMES  (4)     // 每天发送邮件次数

#define SERVER_TCP_PORT ("21031")   // TCP 连接端口

#define INITSERVER_CMD  ("initdata")    // 自定义协议，初始化服务端命令（[注]：服务端接收到该命令后将开始采集系统信息并发送）
#define ACKSERVER_CMD   ("ackdata")     // 自定义协议，应答消息
#define POWEROFF_CMD    ("poweroff")    // 自定义协议，关闭系统消息

#define BENCHMARKSERVERS       ("测评验证实验室")
#define EDASERVERS              ("EDA 机房")
#define MONITOROBJECT   EDASERVERS

/*
 * 发布命名：APPName-VMajor.Minor.Type.Language.BuildNumber
 *
 * 正式版：
 *  Enhance：增强版或者加强版，属于正式版；
 *  Full：完全版，属于正式版；
 *  Release：发行版，有时间限制；
 *  Upgrade：升级版；
 *  Retail：零售版；
 *  Plus：增强版，不过这种大部分是在程序界面及多媒体功能上增强。
 *
 * 测试版：
 *  Alpha：内部测试版；
 *  Beta：外部测试版；
 *  M版：Milestone，意思是每个开发阶段的终结点的里程碑版本
 *  Trail：试用版（含有某些限制，如时间、功能，注册后也有可能变为正式版）；
 *  RC版：Release Candidate，意思是发布倒计时，该版本已经完成全部功能并清除大部分的BUG。到了这个阶段只会除BUG，不会对软件做任何大的更改；
 *  RTM版：Release To Manufactur，意思是发布到生产商，这基本就是最终的版本；
 *  GA版：Generally Available，最终版。
 */

#define APPVERSION ("IM Monitoring Platform-V1.4.1000.Release.CN.b20230329")
#define BYLINEEMAIL ("服务器监测助手 v1.4.1000")

#define ABOUTVERSION ("V1.4.Release.CN.b20230329")
#define ABOUTRELEASETIME ("2023年03月29日 10:00:00")

typedef struct {
    bool tcpConnectStatus;  // TCP 连接状态
    unsigned int coreCount; // 服务器 CPU 核心数
    QList<double> cpuCore_currentTemperature;  // 服务器每个核心的当前温度
    double cpuTemperature;  // CPU 所有核心的平均温度
    double maxTemperatureOf24H; // 24 小时内最高温度
    int ramSize;    // 内存大小 (单位：GB)
    int ramUsed;    // 内存使用大小
    double ramOccupancyRate;    // 内存使用率 = ramUsed / ramSize * 100%
    // ...... 未定参数

} ServerState_IM;   // 服务器状态结构体

typedef struct ServerDetail_IM{
    bool powerStatus;   // 电源状态 ture:运行中，false:已关机
    QString tcpIPv4;    // 服务器 IP 地址
    QString tcpPort;    // 服务器 TCP 通信端口
    QString userName;   // 使用人
    QString admin;      // 管理员
    QString hostName;   // 主机名
    ServerState_IM serverState; // 服务器实时状态

    ServerDetail_IM() :
        powerStatus(false), tcpIPv4(""), tcpPort(""), userName(""), admin(""), hostName("")
    {
        this->serverState.tcpConnectStatus = false;
        this->serverState.coreCount = 0;
        this->serverState.cpuTemperature = 0;
        this->serverState.maxTemperatureOf24H = 0;
        this->serverState.ramSize = 0;
        this->serverState.ramUsed = 0;
        this->serverState.ramOccupancyRate = 0;
    }

} ServerDetail_IM; // 服务器主机信息结构体

// 邮件类型
enum EmailType {
    OUTLOOK = 0,
    TENCENT = 1,
};

#endif // TYPELIST_H
