#include "email_im.h"

Email_IM::Email_IM(QList<ServerDetail_IM *> *serverList, bool *mutex, QString masterMail, QString masterPasswd, QString mastername, EmailType type, QList<QString> *recvList, QTextEdit *textedit) :
    urgentMutex(mutex), masterEmailAddress(masterMail), masterEmailPasswd(masterPasswd), masterName(mastername), emailType(type), recvEmailList(recvList), textEditor(textedit)
{
    this->serverDetailList = serverList;
}

void Email_IM::MailSendSlot()
{
    QString message = QString(MONITOROBJECT) + "各机器状态:<br>------------------------------------------------------<br>";
    qDebug() << "日常通知邮件！！\n";

    for (int i = 0; i < this->serverDetailList->size(); i++) {
        if (this->serverDetailList->at(i)->powerStatus) {
            if (this->serverDetailList->at(i)->serverState.cpuTemperature > 60) {
                qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "温度:" << this->serverDetailList->at(i)->serverState.cpuTemperature << "<br>";
                message += "主机：";
                message += this->serverDetailList->at(i)->hostName;
                message += " | ";
                message += "电源状态：运行中";
                message += "<br>";
                message += "当前温度：<font color=#199E07>";
                message += QString::number(this->serverDetailList->at(i)->serverState.cpuTemperature, 10, 2);
                message += "℃</font>";
                message += " | ";
                message += "今日最高温度：<font color=#B30E11><b>";
                message += QString::number(this->serverDetailList->at(i)->serverState.maxTemperatureOf24H, 10, 2);
                message += "℃</b></font>";
                message += "<br>";
            } else {
                qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "温度:" << this->serverDetailList->at(i)->serverState.cpuTemperature << "<br>";
                message += "主机：";
                message += this->serverDetailList->at(i)->hostName;
                message += " | ";
                message += "电源状态：运行中";
                message += "<br>";
                message += "当前温度：<font color=#199E07>";
                message += QString::number(this->serverDetailList->at(i)->serverState.cpuTemperature, 10, 2);
                message += "℃</font>";
                message += " | ";
                message += "今日最高温度：<font><b>";
                message += QString::number(this->serverDetailList->at(i)->serverState.maxTemperatureOf24H, 10, 2);
                message += "℃</b></font>";
                message += "<br>";
            }

        } else {
            qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "状态: 已关机" << "<br>";
            message += "<font color=#AB9FBF>主机：";
            message += this->serverDetailList->at(i)->hostName;
            message += " | ";
            message += "电源状态：已关机";
            message += "<br></font>";
        }
        message += "使用人：";
        message += this->serverDetailList->at(i)->userName;
        message += "<br>------------------------------------------------------<br>";
    }

    QDateTime datetime = QDateTime::currentDateTime();
    message += "<br><br>" + QString(BYLINEEMAIL) + "<br>" + datetime.toString("yyyy-MM-dd HH:mm:ss");

    if (this->recvEmailList) {
        for (int i = 0; i < this->recvEmailList->size(); i++) {
            this->Smtp_IM(this->recvEmailList->at(i), message, QString("尊贵的订阅用户"), QString("服务器日常通知"));
        }
    }

}

void Email_IM::SendUrgentMail(int level, int id)
{
    qDebug() << "紧急通知邮件！！\n";
    QString message = "服务器“" + this->serverDetailList->at(id)->hostName + "”温度超过危险温度(65℃)，<font color=#B30E11>当前风险等级为 Lv:" + QString::number(level, 10) + "</font><br>";
           message += QString(MONITOROBJECT) + "各机器状态:\n------------------------------------------------------\n";

    for (int i = 0; i < this->serverDetailList->size(); i++) {
        if (this->serverDetailList->at(i)->powerStatus) {
            qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "温度:" << this->serverDetailList->at(i)->serverState.cpuTemperature << "<br>";
            message += "主机：";
            message += this->serverDetailList->at(i)->hostName;
            message += " | ";
            message += "电源状态：运行中";
            message += "<br>";
            message += "当前温度：<font color=#B30E11>";
            message += QString::number(this->serverDetailList->at(i)->serverState.cpuTemperature, 10, 2);
            message += "℃</font>";
            message += " | ";
            message += "今日最高温度：<font color=#B30E11><b>";
            message += QString::number(this->serverDetailList->at(i)->serverState.maxTemperatureOf24H, 10, 2);
            message += "℃</b></font>";
            message += "<br>";
        } else {
            qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "状态: 已关机" << "<br>";
            message += "<font color=#AB9FBF>主机：";
            message += this->serverDetailList->at(i)->hostName;
            message += " | ";
            message += "电源状态：已关机</font>";
            message += "<br>";
        }
        message += "使用人：";
        message += this->serverDetailList->at(i)->userName;
        message += "<br>------------------------------------------------------<br>";
    }

    QDateTime datetime = QDateTime::currentDateTime();
    message += "<br><br>" + QString(BYLINEEMAIL) + "<br>" + datetime.toString("yyyy-MM-dd HH:mm:ss");

    if (this->recvEmailList) {
        for (int i = 0; i < this->recvEmailList->size(); i++) {
            this->Smtp_IM(this->recvEmailList->at(i), message, QString("尊贵的订阅用户"), QString("紧急通知邮件！！"));
        }
    }
    // 紧急邮件开锁
    if (this->urgentMutex) {
        *this->urgentMutex = true;
    }

}

void Email_IM::SendPowerDownMail()
{
    qDebug() << "通知！！\n";
    qDebug() << "高温机器关机！！\n";

    QString message = "存在服务器温度高温运行过久，已执行关机指令，风险解除！<br>";
           message += QString(MONITOROBJECT) + "各机器状态:<br>------------------------------------------------------<br>";
    for (int i = 0; i < this->serverDetailList->size(); i++) {
        if (this->serverDetailList->at(i)->powerStatus) {
            if (this->serverDetailList->at(i)->serverState.cpuTemperature > 60) {
                qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "温度:" << this->serverDetailList->at(i)->serverState.cpuTemperature << "<br>";
                message += "主机：";
                message += this->serverDetailList->at(i)->hostName;
                message += " | ";
                message += "电源状态：运行中";
                message += "<br>";
                message += "当前温度：<font color=#199E07>";
                message += QString::number(this->serverDetailList->at(i)->serverState.cpuTemperature, 10, 2);
                message += "℃</font>";
                message += " | ";
                message += "今日最高温度：<font color=#B30E11><b>";
                message += QString::number(this->serverDetailList->at(i)->serverState.maxTemperatureOf24H, 10, 2);
                message += "℃</b></font>";
                message += "<br>";
            } else {
                qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "温度:" << this->serverDetailList->at(i)->serverState.cpuTemperature << "<br>";
                message += "主机：";
                message += this->serverDetailList->at(i)->hostName;
                message += " | ";
                message += "电源状态：运行中";
                message += "<br>";
                message += "当前温度：<font color=#199E07>";
                message += QString::number(this->serverDetailList->at(i)->serverState.cpuTemperature, 10, 2);
                message += "℃</font>";
                message += " | ";
                message += "今日最高温度：<font><b>";
                message += QString::number(this->serverDetailList->at(i)->serverState.maxTemperatureOf24H, 10, 2);
                message += "℃</b></font>";
                message += "<br>";
            }
        } else {
            qDebug() << "服务器： " + this->serverDetailList->at(i)->hostName + "状态: 已关机" << "<br>";
            message += "<font color=#AB9FBF>主机：";
            message += this->serverDetailList->at(i)->hostName;
            message += " | ";
            message += "电源状态：已关机</font>";
            message += "<br>";
        }
        message += "使用人：";
        message += this->serverDetailList->at(i)->userName;
        message += "<br>------------------------------------------------------<br>";
    }

    QDateTime datetime = QDateTime::currentDateTime();
    message += "<br><br>" + QString(BYLINEEMAIL) + "<br>" + datetime.toString("yyyy-MM-dd HH:mm:ss");

    if (this->recvEmailList) {
        for (int i = 0; i < this->recvEmailList->size(); i++) {
            this->Smtp_IM(this->recvEmailList->at(i), message, QString("尊贵的订阅用户"), QString("风险解除通知: 高温机器已关机"));
        }
    }
    // 紧急邮件开锁
    if (this->urgentMutex) {
        *this->urgentMutex = true;
    }


}

void Email_IM::InitEmail(const QString &from, const QString &name, const QString &to, const QString &to_name, const QString &subject)
{
    this->sender = new EmailAddress(from, name);

    this->messageMail.setSender(*this->sender);

    this->to = new EmailAddress(to, to_name);
    this->messageMail.addRecipient(*this->to);

    this->messageMail.setSubject(subject);
}

bool Email_IM::SendEmail(QString msg)
{
    /*
    if (this->textEditor) {
        this->textEditor->setLineWrapMode(QTextEdit::NoWrap);
        this->textEditor->append(msg);
        msg.clear();
        msg = this->textEditor->toHtml();
    } else {
        return false;
    }
    */


    this->body.setHtml(msg);
    this->messageMail.addPart(&this->body);

    /*
#ifdef OUTLOOKMAIL
    // 选择微软 outlook 邮箱发送
    this->smtp = new SmtpClient("smtp-mail.outlook.com", 587, SmtpClient::TlsConnection);
#endif  // OUTLOOKMAIL


#ifdef TENCENTMAIL
    // 选用腾讯企业微信邮箱发送
    this->smtp = new SmtpClient("smtp.exmail.qq.com", 465, SmtpClient::SslConnection);
#endif  // TENCENTMAIL
    */

    switch(this->emailType) {
    case OUTLOOK: {
        this->smtp = new SmtpClient("smtp-mail.outlook.com", 587, SmtpClient::TlsConnection);
        break;
    }
    case TENCENT: {
        this->smtp = new SmtpClient("smtp.exmail.qq.com", 465, SmtpClient::SslConnection);
        break;
    }
    }

    this->smtp->connectToHost();

    if (!this->smtp->waitForReadyConnected()) {
        qDebug() << "Failed to connect to host!";
        return false;
    }

    this->smtp->login(this->masterEmailAddress, this->masterEmailPasswd);

    if (!smtp->waitForAuthenticated()) {
        qDebug() << "Failed to login!";
        return false;
    }

    smtp->sendMail(this->messageMail);
    if (!smtp->waitForMailSent()) {
        qDebug() << "Failed to send mail!";
        return false;
    }

    qDebug() << "send mail success!";
    //this->textEditor->clear();
    //emit this->ClearTextEditor_Signal();

    this->smtp->quit();
    return true;
}

void Email_IM::GabageCollectionForEmail()
{
    delete this->sender;
    this->sender = nullptr;
    delete this->to;
    this->to = nullptr;
    delete this->smtp;
    this->smtp = nullptr;
    this->messageMail.ClearBuf_IM();        //*****************************************
}

bool Email_IM::Smtp_IM(const QString &contact, QString msg, const QString &name, const QString &subject)
{
    bool ret = false;
    this->InitEmail(masterEmailAddress, masterName, contact, name, subject);

    ret = this->SendEmail(msg);
    //QThread::msleep(100);
    this->GabageCollectionForEmail();
    return ret;
}
