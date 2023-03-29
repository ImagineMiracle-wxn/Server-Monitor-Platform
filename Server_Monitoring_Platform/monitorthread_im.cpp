#include "monitorthread_im.h"

MonitorThread_IM::MonitorThread_IM(int id, bool isexit, QList<int> *mailtime, ServerDetail_IM *server, QLabel *lab, bool *mutex, bool *displaymutex) :
    threadID(id), isExit(isexit), eMailTime(mailtime), serverDetail(server), displayLab(lab), socket(nullptr), messageInit(true),
    messageChange(false), isRisk(false), isRiskDisplay(false), riskCount(0), riskLevel(0), urgentMutex(mutex), displayMutex(displaymutex)
{
    // 初始化显示当前服务器信息
    this->displayLab->setText("服务器: " + serverDetail->hostName + "    状态: 已关机"
                              + "    用户: " + serverDetail->userName);
    this->displayLab->setGeometry(30, (this->threadID) * 20 - 10 + 10, 720, 20);
    this->displayLab->show();

    this->InitConnectToHost();

}

MonitorThread_IM::~MonitorThread_IM()
{
}

void MonitorThread_IM::InitConnectToHost()
{
    if (this->socket) {
        delete this->socket;
    }
    // 初始化套接字
    this->socket = new QTcpSocket();
    //qDebug() << "MonitorThread[" << this->threadID << "]:" << "Ready to connect Server.\n";

    QObject::connect(this->socket, SIGNAL(readyRead()), this, SLOT(RecvDataFromServerAndDisplay()));
    QObject::connect(this->socket, SIGNAL(connected()), this, SLOT(ConnectedSuccessful()));
    QObject::connect(this->socket, SIGNAL(disconnected()), this, SLOT(LossConnectionAndRetry()));


    // 连接服务器 TCP 服务端
    this->socket->connectToHost(QHostAddress(serverDetail->tcpIPv4), serverDetail->tcpPort.toInt()); // 发布时打开该行

    // 等待连接成功并反馈连接状态
    this->serverDetail->serverState.tcpConnectStatus = this->socket->waitForConnected(500);
}

int MonitorThread_IM::GetThreadID()
{
    return this->threadID;
}

QLabel * MonitorThread_IM::GetLabelP()
{
    return this->displayLab;
}

void MonitorThread_IM::ToDead()
{
    this->isExit = false;

    return;
}

void MonitorThread_IM::ReConnectToHost()
{
    /*
    // 连接服务器 TCP 服务端
    this->socket->connectToHost(QHostAddress(serverDetail->tcpIPv4), serverDetail->tcpPort.toInt()); // 发布时打开该行

    // 等待连接成功并反馈连接状态
    this->serverDetail->serverState.tcpConnectStatus = this->socket->waitForConnected(500);
    */

    this->InitConnectToHost();
}

void MonitorThread_IM::run()
{
    while(this->isExit) {
        // TODO: 当服务器状态发生改变时，同步更新界面显示
        if (this->serverDetail->serverState.tcpConnectStatus) {
            // 显示服务器运行状态
            if (this->serverDetail->powerStatus) {
                // 接收到新消息
                if (this->messageChange) {
                    this->messageChange = false;
                    double coreTempatureTotal = 0;

                    for (int i = 0; i < this->serverDetail->serverState.cpuCore_currentTemperature.size(); i++) {
                        coreTempatureTotal += this->serverDetail->serverState.cpuCore_currentTemperature.at(i);
                    }
                    // 计算平均温度值

                    this->serverDetail->serverState.cpuTemperature = coreTempatureTotal / this->serverDetail->serverState.coreCount;
                    // 更新今日最高温度
                    if (this->serverDetail->serverState.cpuTemperature > this->serverDetail->serverState.maxTemperatureOf24H) {
                        this->serverDetail->serverState.maxTemperatureOf24H = this->serverDetail->serverState.cpuTemperature;
                    }
                    // 每日零点重新记录今日最高温度
                    QDateTime datetime = QDateTime::currentDateTime();
                    if (datetime.time().hour() == 0 && datetime.time().minute() == 0 && datetime.time().second() < 10) {
                        this->serverDetail->serverState.maxTemperatureOf24H = this->serverDetail->serverState.cpuTemperature;
                    }

                    // 温度值超过预警值（65℃），状态切换为风险状态
                    if (this->serverDetail->serverState.cpuTemperature > MAXSAFETEMPATURE) {
                        this->isRisk = true;
                        // 温度超过危险值 (75℃)，直接强制系统关机
                        if (this->serverDetail->serverState.cpuTemperature > POWEROFFTEMPATURE) {

                            while(false == *this->displayMutex) {
                                ;
                            }
                            *this->displayMutex = false;
                            emit this->SafeDisplayMode_Signal(this->threadID);
                            // 向 sokcet 写入 poweroff 指令
                            this->socket->write(QString(POWEROFF_CMD).toUtf8().data());
                            this->isRisk = false;   // 解除风险状态
                            this->serverDetail->powerStatus = false;    // 系统电源关闭
                            this->riskLevel = 0;    // 解除风险状态
                            this->riskCount = 0;    // 解除风险状态
                        }
                    } else {
                        this->isRisk = false;
                    }
                    this->displayLab->setText("服务器: " + serverDetail->hostName + "    状态: 运行中"
                                              + "    温度:" + QString::number(this->serverDetail->serverState.cpuTemperature, 10, 2) + "℃"
                                              + "    今日最高:" + QString::number(this->serverDetail->serverState.maxTemperatureOf24H, 10, 2) + "℃"
                                              + "    内存:" + ((this->serverDetail->serverState.ramOccupancyRate < 10) ? "0" : "") + QString::number(this->serverDetail->serverState.ramOccupancyRate, 10, 2) + "% [Total:" + QString::number(this->serverDetail->serverState.ramSize, 10) + "GB]"
                                              + "    用户: " + serverDetail->userName);
                    if (this->isRisk) {
                        if (!this->isRiskDisplay) {
                            // 发送信号通知主进程，让其改变 QLabel 显示字体颜色为红色
                            while(false == *this->displayMutex) {
                                ;
                            }
                            *this->displayMutex = false;
                            emit this->RiskDisplayMode_Signal(this->threadID);
                        }
                        this->isRiskDisplay = true;
                        this->riskCount++;

                        // [注]：服务器端的数据是每两秒更新一次，因此 riskCount 的数值换算为时间的公式为( 经过时间(s) = riskCount * 2)
                        // 风险等级：0，表示常规状态，可能存在风险但非常小
                        // 当温度超过（65℃）半小时后发送第一次紧急邮件，超过半小时（1800s = 0.5h）温度还没降低到预警温度以下，开始每 5 分钟发送一次紧急邮件
                        if ((0 == this->riskLevel) && ((this->riskCount / 900) && (0 == (this->riskCount % 900)))) {
                        //if ((0 == this->riskLevel) && ((this->riskCount / 100) && (0 == (this->riskCount % 100)))) { //#DEBUG#//
                            qDebug() << "thread[" << this->threadID << "]: " << this->riskCount << "s" << "emit SendUrgentMail_Signal\n";

                            //===================== 此处的信号发送限制条件有待优化=========================
                            // 这样会导致有些线程错过发送信号的情况
                            //while (*this->urgentMutex) {
                            while (false == *this->urgentMutex) {
                                ;
                            }
                                *this->urgentMutex = false;
                                emit this->SendUrgentMail_Signal(this->riskLevel + 1, this->threadID);
                                this->riskLevel = 1;
                            //}
                            //===================== 此处的信号发送限制条件有待优化=========================
                        }
                        // 风险等级：1，表示常规状态，可能存在一般风险
                        // 每 5 分钟发送一次紧急信号（300s = 5min），发送 6 次后，即高温运行 1 小时后，仍没有降低至预警温度以下，则不发送邮件，改为发送指令将系统关机，并发送机器关机邮件
                        else if ((1 == this->riskLevel) && ((this->riskCount / 150) && (0 == (this->riskCount % 150)))) {
                        //else if ((1 == this->riskLevel) && ((this->riskCount / 100) && (0 == (this->riskCount % 100)))) {   //#DEBUG#//
                            qDebug() << "thread[" << this->threadID << "]: " << this->riskCount << "s" << "emit SendUrgentMail_Signal\n";

                            //===================== 此处的信号发送限制条件有待优化=========================
                            // 这样会导致有些线程错过发送信号的情况
                            //while (*this->urgentMutex) {
                            while (false == *this->urgentMutex) {
                                ;
                            }
                                *this->urgentMutex = false;
                                emit this->SendUrgentMail_Signal(this->riskLevel + 1, this->threadID);
                            //}
                            //===================== 此处的信号发送限制条件有待优化=========================
                            // 一个小时后提升风险等级为 2，（900 * 1+ 150 * 6 = 1800, 经过时间(s) = 1800 * 2 = 3600s）
                            if (this->riskCount == 1800) {
                            //if (this->riskCount == 300) { //##DEBUG##//
                                this->riskLevel = 2;
                            }
                        }
                        else if (2 == this->riskLevel) {
                            qDebug() << "thread[" << this->threadID << "]: " << this->riskCount << "s" << "emit PowerDownMail_Signal\n";
                            // 发送关机信号
                            //===================== 此处的信号发送限制条件有待优化=========================
                            // 这样会导致有些线程错过发送信号的情况
                            //while (*this->urgentMutex) {
                            while (false == *this->urgentMutex) {
                                ;
                            }
                                *this->urgentMutex = false;
                                // 改变为常规显示状态
                                emit this->SafeDisplayMode_Signal(this->threadID);

                                this->isRisk = false;   // 解除风险状态
                                this->serverDetail->powerStatus = false;    // 系统电源关闭
                                this->riskCount = 0;    // 解除风险状态
                                // TODO：向 sokcet 写入 poweroff 指令+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                emit this->PowerDownMail_Signal();
                                this->riskLevel = 0;    // 解除风险状态
                            //}
                            //===================== 此处的信号发送限制条件有待优化=========================


                        }
                    } else {
                        if (this->isRiskDisplay) {
                            // 发送信号通知主进程，让其改变 QLabel 显示字体颜色为黑色
                            while(false == *this->displayMutex) {
                                ;
                            }
                            *this->displayMutex = false;
                            emit this->SafeDisplayMode_Signal(this->threadID);
                        }
                        this->isRiskDisplay = false;
                    }
                }
                // 未接收到新消息不做动作
                // ;;;;;;
                // 未接收到新消息判断机器是否异常关机
                // ;;;;;;
                else {
                    // 状态未改变计数，用于检测服务器异常关机
                    if (this->serverDetail->powerStatus) {
                        if (0 == this->lastTemperature) {
                            this->lastTemperature = this->serverDetail->serverState.cpuTemperature;
                            this->noChangeCountor = 0;
                        }
                        if (this->lastTemperature == this->serverDetail->serverState.cpuTemperature) {
                            this->noChangeCountor++;
                        } else {
                            this->lastTemperature = this->serverDetail->serverState.cpuTemperature;
                            this->noChangeCountor = 0;
                        }

                        if (20 == this->noChangeCountor) {
                            this->noChangeCountor = 0;
                            this->serverDetail->serverState.cpuTemperature = 0;
                            this->serverDetail->powerStatus = false;
                            this->serverDetail->serverState.tcpConnectStatus = false;
                            this->socket->disconnect();
                            this->socket->waitForDisconnected(500);
                        }
                    }

                    msleep(500);
                }
            }
            // 显示服务器已关机
            else {
                this->displayLab->setText("服务器: " + serverDetail->hostName + "    状态: 已关机"
                                          + "    用户: " + serverDetail->userName);
            }
        }
        // 服务器掉线状态
        else {

            //qDebug() << "MonitorThread[" << this->threadID << "]:" << "Reconnecting...\n";
            this->displayLab->setText("服务器: " + serverDetail->hostName + "    状态: 失去连接，请及时联系管理员..."
                                      + "    用户: " + serverDetail->userName);
            /*
            this->socket->disconnectFromHost();
            this->socket->waitForDisconnected(200);
            */
            // TODO: 实现断线重连
            /*
            this->socket->connectToHost(QHostAddress(serverDetail->tcpIPv4), serverDetail->tcpPort.toInt());
            this->serverDetail->serverState.tcpConnectStatus = this->socket->waitForConnected(500);
            */

        }

        sleep(1);
    }

    this->socket->disconnect();

    return ;
}

void MonitorThread_IM::RecvDataFromServerAndDisplay()
{
    // 处理服务端发来的数据
    if (this->messageInit) {
        this->messageInit = false;
        // 初次信息的处理 (Core 数量，Mem 总大小)
        QByteArray recvData = this->socket->readAll();
        //char ** serverDataArray = (char **)malloc();
        QString strData = recvData;
        bool isRamData = false;
        QString coreNumber = "", ramSize = "";
        //qDebug() << "thread[" << this->threadID << "]: " << strData << "\n";
        //qDebug() << "thread[" << this->threadID << "]: " << strData.length() << "\n";
        for (int i = 0; i < strData.length(); i++) {
            if (isRamData) {
                if (strData.at(i) != '\n') {
                    ramSize += strData.at(i);
                } else {
                    break;
                }
            } else {
                if (strData.at(i) != '\n') {
                    coreNumber += strData.at(i);
                } else {
                    isRamData = true;
                }
            }
        }
        this->serverDetail->serverState.coreCount = coreNumber.toUInt();
        this->serverDetail->serverState.ramSize = ramSize.toInt();
        qDebug() << "thread[" << this->threadID << "]: " << "CoreNumber =" << this->serverDetail->serverState.coreCount << "RamSize =" << this->serverDetail->serverState.ramSize << "\n";
    } else {
        // TODO: 非初次信息的处理 (各 Core 的温度)
        QByteArray recvData = this->socket->readAll();
        QString strData = recvData;
        //bool isRamData = false;
        QString coreTempature = "", ramUseRate = "";
        double value = 0;
        //qDebug() << "thread[" << this->threadID << "]: " << strData << "\n";        //----------------------------
        int strData_i = 0, value_i = 0;

        // 每次读取前清空一次链表内的数据
        this->serverDetail->serverState.cpuCore_currentTemperature.clear();

        for (strData_i = 0; strData_i < strData.length(); strData_i++) {
            if (value_i == this->serverDetail->serverState.coreCount) {
                // 处理最后一个数据(内存使用率)
                for(; strData.at(strData_i) != '\n'; strData_i++) {
                    ramUseRate += strData.at(strData_i);
                }
                value = ramUseRate.toDouble();
                this->serverDetail->serverState.ramOccupancyRate = value;   // 将数据添加进服务器状态表中
                ramUseRate.clear();
            } else {
                // 处理各核心温度
                value_i++;  // 单次处理一个数据，最后一个数据即为内存使用率
                for(; strData.at(strData_i) != '\n'; strData_i++) {
                    coreTempature += strData.at(strData_i);
                }
                value = coreTempature.toDouble();
                this->serverDetail->serverState.cpuCore_currentTemperature.append(value);   // 将数据添加进服务器状态表中
                coreTempature.clear();
            }
        }

        /*
        qDebug() << "thread[" << this->threadID << "]: " << "CoreTempature:\n";
        for (int i = 0; i < this->serverDetail->serverState.cpuCore_currentTemperature.size(); i++) {
            qDebug() << this->serverDetail->serverState.cpuCore_currentTemperature.at(i) << "℃";
        }
        qDebug() << "\n" << this->serverDetail->serverState.ramOccupancyRate << "%";
        */


        this->messageChange = true; // 接收到新消息（并处理完成）
        // 写入应答消息
        this->socket->write(QString(ACKSERVER_CMD).toUtf8().data());
    }

    return ;
}

void MonitorThread_IM::ConnectedSuccessful()
{
    qDebug() << "MonitorThread[" << this->threadID << "]:" << "Connected to Server!\n";

    this->serverDetail->serverState.tcpConnectStatus = true;
    this->serverDetail->powerStatus = true;     // 连接成功，显示机器为运行状态（监控软件）
    this->messageInit = true;

    this->socket->write(QString(INITSERVER_CMD).toUtf8().data());
    return ;
}

void MonitorThread_IM::LossConnectionAndRetry()
{
    this->serverDetail->serverState.tcpConnectStatus = false;   // 与服务主机失去连接
    this->serverDetail->powerStatus = false;    // 服务器关机
    this->messageInit = true;   // 失去连接后恢复初始化命令
    qDebug() << "loss connection...\n";
}
