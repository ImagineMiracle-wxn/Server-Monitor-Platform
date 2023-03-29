#include "timethread_im.h"

TimeThread_IM::TimeThread_IM(int id, bool isexit, QList<int> *mailtime, QLabel *lab, QLCDNumber *lcd, bool *en):
    threadID(id), isExit(isexit), eMailTime(mailtime), isTimeToSend(-1), dispaly_Lab(lab), LcdNum_DateTime(lcd), currentMinute(0), eMailSend_EN(en)
{
    this->dispaly_Lab = lab;
    this->LcdNum_DateTime = lcd;
    this->startTime = QDateTime::currentDateTime();
    this->currentTime = QDateTime::currentDateTime();
    this->today = this->startTime.date().day();
    this->currentMinute = this->startTime.time().minute() / 10 * 10 + 10;

    if (60 == this->currentMinute) {
        this->currentMinute = 10;
    }
    //this->currentHour = this->startTime.time().minute();        //##DEBUG##// 调试结束删除
    //this->today = this->startTime.time().minute();  //##DEBUG##// 调试结束删除

    QString labDisplay = "程序已运行: 0 天 0 小时 0 分钟";
    this->dispaly_Lab->setText(labDisplay);

    // 匹配今日下一次发送邮件时间
    for (int i = 0; i < this->eMailTime->size(); i++) {
        if (this->eMailTime->at(i) >= this->currentTime.time().hour()) {  // 调试结束后开启
        //if (this->eMailTime->at(i) >= this->currentTime.time().minute()) {    //##DEBUG##// 调试结束删除
            this->isTimeToSend = this->eMailTime->at(i);
            break;
        }
    }
    qDebug() << "SendTime:" << this->isTimeToSend << "\n";

    this->isSend = false;   // 匹配成功则表示今日邮件已发送完成，或已超过所有发送邮件时间点

    // 未能成功匹配则不发送   TODO: 后期修改为临时发送（确保每天至少有一次邮件）
    if (-1 == this->isTimeToSend) {
        this->isTimeToSend = this->eMailTime->at(0);
        this->isSend = true;
    }
    qDebug() << "SendTime:" << this->isTimeToSend << "\n";

}

int TimeThread_IM::GetThreadID()
{
    return this->threadID;
}

void TimeThread_IM::ToDead()
{
    this->isExit = false;

    return ;
}

/*
void TimeThread_IM::EmailSendEn_Slot(bool sig)
{
    this->eMailSend_EN = sig;
    qDebug() << "Send_EN:" << (this->eMailSend_EN ? "true" : "false") << "\n";
}
*/

void TimeThread_IM::run()
{
    while(this->isExit)  {
        //qDebug() << "[TimeThread" << this->threadID << "]:" << "Display current time is my job.\n";

        QString display;
        QDateTime interval(QDate(2000, 1, 1), QTime(0, 0, 0, 0));       //以2000-1-1 0:0:0::0为基准，加上程序运行的总秒数，再用toString转换
        this->currentTime = QDateTime::currentDateTime();

        display = interval.addSecs(this->startTime.secsTo(this->currentTime)).toString("dd 天 hh 小时 mm 分钟");
        display = display.replace(1, 1, QString::number(QString(display[1]).toInt() - 1));
        this->dispaly_Lab->setText("程序已运行：" + display);

        //=============================== 根据指定时间每天发送四次信号 ==========================
        //qDebug() << "下一次发送邮件时间: " << this->isTimeToSend << "现在时间：" << this->currentTime.time().hour() << "\n";
        if (this->currentTime.time().hour() == this->isTimeToSend && !this->isSend) {   //调试结束打开//
        //if (this->currentTime.time().minute() == this->isTimeToSend && !this->isSend) {     //##DEBUG##// 调试结束删除改行
            if (*this->eMailSend_EN) {
                qDebug() << "邮件发送信号\n";
                emit this->MailSendSignal();  // 邮件发送信号
            }
            qDebug() << "发送邮件时间: " << this->isTimeToSend << "最后一次时间：" << this->eMailTime->at(this->eMailTime->count() - 1) << "\n";
            if (this->isTimeToSend == this->eMailTime->at(this->eMailTime->count() - 1)) {
                this->isSend = true;
                this->isTimeToSend = this->eMailTime->at(0);
                qDebug() << "今日邮件发送完成\n";
            } else {
                this->isTimeToSend = this->eMailTime->at(this->eMailTime->indexOf(this->isTimeToSend) + 1);
                qDebug() << "等待下一次发送邮件,Time: " << this->isTimeToSend << "\n";
            }
        }
        if (this->currentTime.date().day() != this->today) {      //调试结束打开//
        //if (this->currentTime.time().hour() != this->today) {     //##DEBUG##// 调试结束删除行
            this->today = this->currentTime.date().day();
            //this->today = this->currentTime.time().hour();        //##DEBUG##// 调试结束删除行
            this->isSend = false;
        }
        //=========================================================================================

        //======================== 每隔一个小时发送刷新主界面信号, *:30 时发送刷新信号 =======================
        if (this->currentMinute == this->currentTime.time().minute()) {
            if (50 == this->currentMinute) {
                this->currentMinute = 10;
            } else {
                this->currentMinute += 10;
            }

            emit this->ToFlushMainWindow();
        }
        //=========================================================================

        QDateTime datetime = QDateTime::currentDateTime();
        this->LcdNum_DateTime->display(datetime.toString("yyyy-MM-dd HH:mm:ss"));
        msleep(500);
    }
}
