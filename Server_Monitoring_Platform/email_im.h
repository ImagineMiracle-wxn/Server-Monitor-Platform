#ifndef EMAIL_IM_H
#define EMAIL_IM_H

#include <QString>
#include <QDebug>
#include <QObject>
#include <QList>
#include <QWidget>
#include <QThread>
#include <QTextEdit>

#include "typelist.h"
#include "headlist.h"

//#define OUTLOOKMAIL

#define TENCENTMAIL

class Email_IM: public QObject
{
    Q_OBJECT
public:
    Email_IM(QList<ServerDetail_IM *> *serverList = nullptr, bool *mutex = nullptr, QString masterMail = "", QString masterPasswd = "", QString mastername = "", EmailType type = OUTLOOK, QList<QString> *recvList = nullptr, QTextEdit *textedit = nullptr);

signals:
    void ClearTextEditor_Signal(void);

public slots:
    void MailSendSlot();

    void SendUrgentMail(int, int);  // 发送紧急邮件

    void SendPowerDownMail(void); // 发送系统关机邮件

    //=================== 非直接调用函数 ===================
    // 初始化邮件服务
    void InitEmail(const QString &from, const QString &name, const QString &to, const QString &to_name, const QString &subject);

    bool SendEmail(QString msg);    // 发送邮件到指定邮箱, msg: 要发送的内容，ret: true：发送成功，false：发送失败

    void GabageCollectionForEmail();    // 邮件垃圾回收(释放单次发送邮件使用的内存空间)
    //=============== end of 非直接调用函数  ================

    bool Smtp_IM(const QString &contact, QString msg, const QString &name, const QString &subject);        // SMTP 服务发送邮件

private:

    QString messageStr;

    bool eMail_EN;

    QList<ServerDetail_IM *> *serverDetailList;  // 服务器信息与状态列表

    EmailAddress *sender, *to;
    MimeMessage messageMail;
    //MimeText body;      // 文本格式
    MimeHtml body;      // Html 格式
    SmtpClient *smtp;
    bool *urgentMutex;  // 紧急信号锁 true: 空闲，可发送紧急信号;  false: 忙，等待解锁

    QString masterEmailAddress;     // 主机邮箱地址
    QString masterEmailPasswd;      // 主机邮箱密码
    QString masterName;             // 邮箱名
    EmailType   emailType;          // 邮件类型 outlook 或者 tencent

    QList<QString> *recvEmailList;   // 收件人列表

    QTextEdit *textEditor;
};

#endif // EMAIL_IM_H
