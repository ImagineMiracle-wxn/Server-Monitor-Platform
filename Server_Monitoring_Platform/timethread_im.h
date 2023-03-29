#ifndef TIMETHREAD_IM_H
#define TIMETHREAD_IM_H

#include <QList>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QLabel>
#include <QDateTime>
#include <QLCDNumber>

class TimeThread_IM: public QThread
{
    Q_OBJECT
public:
    TimeThread_IM(int id, bool isexit, QList<int> *mailtime, QLabel *lab = nullptr, QLCDNumber *lcd = nullptr, bool *en = nullptr);

    int GetThreadID(void);

    void ToDead(void);

signals:
    void MailSendSignal();

    void ToFlushMainWindow(void);   // 刷新主界面信号

public slots:
    //void EmailSendEn_Slot(bool sig);

protected:

    void run();



private:
    int threadID;       // 主进程为其分配的 IDcode
    bool isExit;    // 线程退出标记 true: 线程正常运行, false: 线程退出, default: true
    bool isSend;    // 今日邮件是否发送完成
    QList<int> *eMailTime;    // 自定义邮件发送时间列表
    int isTimeToSend; // 下一次发送邮件时间
    QLabel *dispaly_Lab;            // 显示软件运行总时长标签
    QLCDNumber *LcdNum_DateTime;    // 显示当前时间的 LCD

    QDateTime startTime;    // 运行起始时间
    QDateTime currentTime;  // 当前时间

    int today;  // 今日日期
    int currentMinute;    // 现在分钟

    bool *eMailSend_EN;  // 日常邮件发送使能 true: 开启日常邮件发送功能， false: 关闭日常邮件发送功能
    // [注]: 关闭日常邮件发送功能不会影响紧急邮件发送功能

};

#endif // TIMETHREAD_IM_H
