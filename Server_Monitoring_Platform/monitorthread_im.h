#pragma once
#ifndef MONITORTHREAD_IM_H
#define MONITORTHREAD_IM_H

#include <QThread>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QTcpSocket>
#include <QByteArray>

#include "typelist.h"

// TODO: 添加槽函数，当一天结束时，清零今日最高温度

class MonitorThread_IM : public QThread
{
    Q_OBJECT
public:
    MonitorThread_IM(int id, bool isexit, QList<int> *mailtime, ServerDetail_IM *server = nullptr, QLabel *lab = nullptr, bool *mutex = nullptr, bool *display_mutex = nullptr);

    ~MonitorThread_IM();

    void InitConnectToHost(void);

    int GetThreadID(void);

    QLabel * GetLabelP(void);

    void ToDead(void);

    void ReConnectToHost(void);

signals:
    void test_signal(QString );

    void RiskSignal(void);

    void RiskDisplayMode_Signal(int);

    void SafeDisplayMode_Signal(int);

    void SendUrgentMail_Signal(int level, int id);  // 携带风险等级,以及风险机器 id 的信号

    void PowerDownMail_Signal(void);

public slots:
    //void Test_GetLabFromMaster(QLabel * lab);

    //void RiskTempature(void);


protected:
    void run();

private slots:
    void RecvDataFromServerAndDisplay(void);

    void ConnectedSuccessful(void);

    void LossConnectionAndRetry(void);

private:
    int threadID;
    bool isExit;    // 线程退出标记 true: 线程正常运行, false: 线程退出, default: true

    QList<int> *eMailTime;     // 指定邮件发送时间列表
    ServerDetail_IM *serverDetail; // 当前线程所负责的服务器信息(线程内实时更新)
    QLabel *displayLab; // 主界面的 QLabel

    QTcpSocket *socket; // 连接socket

    bool messageInit;   // 连接初始化阶段
    bool messageChange; // 是否接收到新消息
    bool isRisk;    // 判断是否危险
    bool isRiskDisplay; // 危险高亮显示

    unsigned int riskCount; //风险计数 数值越高，风险越高，初始值为 0
    unsigned int riskLevel; //风险等级 数值越高，风险越高，初始值为 0

    bool *urgentMutex;  // 紧急信号锁 true: 空闲，可发送紧急信号;  false: 忙，等待解锁
    bool *displayMutex;

    double lastTemperature; // 记录上一次温度值，用于监测服务器异常关机
    int noChangeCountor;    // 状态无变化计数器，累计 10 次状态相同，判定服务器异常关机
    int disconnectCountor;  // 断开连接计数器
};

#endif // MONITORTHREAD_IM_H
