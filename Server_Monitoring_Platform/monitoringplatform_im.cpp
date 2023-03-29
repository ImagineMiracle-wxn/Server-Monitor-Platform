#include "monitoringplatform_im.h"
#include "ui_monitoringplatform_im.h"

MonitoringPlatform_IM::MonitoringPlatform_IM(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MonitoringPlatform_IM), timeThread(nullptr), eMail_IM(nullptr), emailConfigure(nullptr), masterMenuBar(nullptr), aboutIM(nullptr)
{
    ui->setupUi(this);   

    this->Init_EmailTime();
    this->Init_Parameters();     // 初始化成员变量
    this->Init_EmailConfigure(); // 添加初始化邮件配置类成员
    this->Init_AboutIM();        // 初始化关于类
    this->Init_Ui();             // 初始化主界面各控件
    this->Init_MenuBar();        // 初始化菜单栏
    this->Init_TimeThread();
    /*
    this->Init_Email_IM();
    this->ConnectSignalToSlot();
    */
    this->Init_MonitorThread();


    //Test OK.
    //this->ShowThreadNode_ByID(this->threadList.size() - 1);

    this->StartThreads();
    //this->ShowEmailConfigure();
}

MonitoringPlatform_IM::~MonitoringPlatform_IM()
{   
    delete ui;
    this->GabageCollection();
}

void MonitoringPlatform_IM::Init_EmailTime()
{
    this->EmailTime.clear();


    this->EmailTime.append(6);
    this->EmailTime.append(12);
    this->EmailTime.append(19);
    this->EmailTime.append(23);


/*
    this->EmailTime.append(10);
    this->EmailTime.append(11);
    this->EmailTime.append(12);
    this->EmailTime.append(13);
*/


    return ;
}

void MonitoringPlatform_IM::Init_Parameters()
{
    //this->timeThread = nullptr;
    //this->eMail_IM = nullptr;
    this->urgentMutex = new bool;
    *this->urgentMutex = true;      // 初始开锁
    this->displayMutex = new bool;
    *this->displayMutex = true;     // 初始开锁
    this->eMailSend_EN = new bool;
    *this->eMailSend_EN = this->ui->CheckBox_Email_En->checkState();
    this->eMailSevice_EN = new bool;
    *this->eMailSevice_EN = false;     // 初始锁定
    this->textEditor = new QTextEdit;

    //this->emailConfigure = nullptr;
}

void MonitoringPlatform_IM::Init_EmailConfigure()
{
    this->emailConfigure = new EmailConfigure();
}

void MonitoringPlatform_IM::Init_AboutIM()
{
    this->aboutIM = new About_IM();
}

void MonitoringPlatform_IM::Init_Ui()
{

    this->setWindowTitle(QString(APPVERSION));
    this->setWindowIcon(QIcon(":/ico/ico/Server_MonitoringPlatform.ico"));
    // 窗口居中跳出
    this->setGeometry(QGuiApplication::primaryScreen()->availableGeometry().width() / 2 - 400, QGuiApplication::primaryScreen()->availableGeometry().height() / 2 - 300, 800, 600);
    this->ui->LcdNum_DateTime->setStyleSheet("border: 1px solid #F0F0F0; color: black; background: #F0F0F0;");
    this->ui->CheckBox_Email_En->setText("邮件通知");
    this->ui->CheckBox_Email_En->setTristate(false);
}

void MonitoringPlatform_IM::Init_MenuBar()
{
    this->masterMenuBar = new QMenuBar(this);
    this->masterMenuBar->resize(this->width(), this->masterMenuBar->height());

    MainMenuModule *menuModule = new MainMenuModule;
    menuModule->name = "设置";
    menuModule->menu = this->masterMenuBar->addMenu(menuModule->name);  // 添加子菜单并保存菜单地址

    // 在这里添加“设置”菜单行为列表
    this->NewActionForMainMenu(menuModule, "Email设置", &MonitoringPlatform_IM::ShowEmailConfigure, QString(":/ico/ico/email.ico"));
    this->mainMenuList.append(menuModule);


    /*
    // 在这里绑定“设置”菜单行为列表++++++++++++++++++++++++++++++
    for (int menu_i = 0; menu_i < this->mainMenuList.size(); menu_i++) {
        if (this->mainMenuList.at(menu_i)->menu) {
            for (int action_i = 0; action_i < this->mainMenuList.at(menu_i)->actionList.size(); action_i++) {
                if (this->mainMenuList.at(menu_i)->actionList.at(action_i).func) {
                    qDebug() << "[Init_MenuBar]:" << this->mainMenuList.at(menu_i)->actionList.at(action_i).name << "to func\b";
                    QObject::connect(this->mainMenuList.at(menu_i)->actionList.at(action_i).action, &QAction::triggered, this, this->mainMenuList.at(menu_i)->actionList.at(action_i).func);
                }
            }
        }
    }
    */

    menuModule = new MainMenuModule;
    menuModule->name = "启动";
    menuModule->menu = this->masterMenuBar->addMenu(menuModule->name);  // 添加子菜单并保存菜单地址

    // TODO: 在这里添加“启动”菜单行为列表++++++++++++++++++++++++++++++
    //this->NewActionForMainMenu(menuModule, "启动监测系统", &MonitoringPlatform_IM::ShowEmailConfigure);
    this->mainMenuList.append(menuModule);

    menuModule = new MainMenuModule;
    menuModule->name = "工具";
    menuModule->menu = this->masterMenuBar->addMenu(menuModule->name);  // 添加子菜单并保存菜单地址

    // TODO: 添加“帮助”菜单行为列表++++++++++++++++++++++++++++++
    this->NewActionForMainMenu(menuModule, "重连", &MonitoringPlatform_IM::MonitorThreadReConnect, QString(":/ico/ico/Link.ico"));
    this->mainMenuList.append(menuModule);


    menuModule = new MainMenuModule;
    menuModule->name = "帮助";
    menuModule->menu = this->masterMenuBar->addMenu(menuModule->name);  // 添加子菜单并保存菜单地址

    // TODO: 添加“帮助”菜单行为列表++++++++++++++++++++++++++++++
    this->NewActionForMainMenu(menuModule, "关于", &MonitoringPlatform_IM::ShowAboutIM, QString(":/ico/ico/about.ico"));
    this->mainMenuList.append(menuModule);

    // 在这里绑定所有菜单行为列表++++++++++++++++++++++++++++++
    for (int menu_i = 0; menu_i < this->mainMenuList.size(); menu_i++) {
        if (this->mainMenuList.at(menu_i)->menu) {
            for (int action_i = 0; action_i < this->mainMenuList.at(menu_i)->actionList.size(); action_i++) {
                if (this->mainMenuList.at(menu_i)->actionList.at(action_i).func) {
                    qDebug() << "[Init_MenuBar]:" << this->mainMenuList.at(menu_i)->actionList.at(action_i).name << "to func\b";
                    QObject::connect(this->mainMenuList.at(menu_i)->actionList.at(action_i).action, &QAction::triggered, this, this->mainMenuList.at(menu_i)->actionList.at(action_i).func);
                }
            }
        }
    }


    this->masterMenuBar->setStyleSheet("QMenuBar.item{background-color:#E0E0E0;}QMenuBar{background-color:#E0E0E0;}");

}

void MonitoringPlatform_IM::Init_TimeThread()
{
    qDebug() << "[MonitoringPlatform]:" << "ThreadList Count=" << this->threadList.count() << "\n";
    this->timeThread = new TimeThread_IM(this->threadList.count(), true, &this->EmailTime, this->ui->Lab_SystemRunTime, this->ui->LcdNum_DateTime, this->eMailSend_EN);
    QObject::connect(this->timeThread, SIGNAL(ToFlushMainWindow()), this, SLOT(FlushMainWindow()));
    Thread_ListNode * node = new Thread_ListNode;
    node->id = this->threadList.count();
    node->type = ThreadType::TimeThread;
    node->threadPoint = this->timeThread;

    this->threadList.append(node);
    qDebug() << "[MonitoringPlatform]:" << "ThreadList Count=" << this->threadList.count() << "\n";

}

void MonitoringPlatform_IM::Init_Email_IM()
{
    this->eMail_IM = new Email_IM(&this->serverDetailList, this->urgentMutex, this->emailConfigure->GetMasterEmailAddress(), this->emailConfigure->GetMasterEmailPasswd(), this->emailConfigure->GetMasterEmailName(), this->emailConfigure->GetMasterEmailType(), this->emailConfigure->GetRecvEmailList(), this->textEditor);

}

void MonitoringPlatform_IM::Init_MonitorThread()
{
    //************************待监测服务器信息添加处********************************
    this->AddServerToList("10.1.3.120", "苏小轼", "凌云霄", "Server30-120");
    this->AddServerToList("10.1.3.121", "李小白", "凌云霄", "Server30-121");
    this->AddServerToList("10.1.3.122", "杜小甫", "凌云霄", "Server30-122");
    this->AddServerToList("10.1.3.123", "苏小辙", "凌云霄", "Server30-123");
    this->AddServerToList("10.1.3.124", "韩小愈", "凌云霄", "Server30-124");
    this->AddServerToList("10.1.3.125", "苏小洵", "凌云霄", "Server30-125");
    this->AddServerToList("10.1.3.126", "曾小巩", "凌云霄", "Server30-126");
    /*
    // 初始化监控线程
    qDebug() << "[MonitoringPlatform]:" << "ThreadList Count=" << this->threadList.count() << "\n";

    for (int i = 0; i < this->serverDetailList.size(); i++) {
        Thread_ListNode *node = new Thread_ListNode;
        node->id = this->threadList.size();
        node->type = ThreadType::MonitorThread;
        QLabel *lab = new QLabel(this);             // new Qlabel
        this->displayLabelMap.insert(node->id, lab);    //  将 qlabel 插入 map 保存

        MonitorThread_IM * monitorThread = new MonitorThread_IM(node->id, true, &this->EmailTime, this->serverDetailList.at(i), lab, this->urgentMutex, this->displayMutex);
        QObject::connect(monitorThread, SIGNAL(RiskDisplayMode_Signal(int)), this, SLOT(RiskDisplayMode_Slot(int)));
        QObject::connect(monitorThread, SIGNAL(SafeDisplayMode_Signal(int)), this, SLOT(SafeDisplayMode_Slot(int)));

        node->threadPoint = monitorThread;

        qDebug() << "[MonitoringPlatform]:" << "emit Qlabel." << node->id << "\n";
        this->threadList.append(node);
    }

    qDebug() << "[MonitoringPlatform]:" << "ThreadList Count=" << this->threadList.count() << "\n";

}

void MonitoringPlatform_IM::AddServerToList(QString ip, QString username, QString admin, QString hostname)
{
    ServerDetail_IM * serverDetail = new ServerDetail_IM;
    serverDetail->tcpIPv4 = ip;
    serverDetail->tcpPort = SERVER_TCP_PORT;
    serverDetail->userName = username;
    serverDetail->admin = admin;
    serverDetail->hostName = hostname;

    this->serverDetailList.append(serverDetail);
}

void MonitoringPlatform_IM::ConnectSignalToEmailSlot()
{
    // 绑定邮件相关信号和槽函数
    QObject::connect(this->timeThread, SIGNAL(MailSendSignal()), this->eMail_IM, SLOT(MailSendSlot()), Qt::DirectConnection);   // 日常邮件发送
    QObject::connect(this->eMail_IM, SIGNAL(ClearTextEditor_Signal()), this, SLOT(ClearTextEditor_Slot()));

    for (int i = 1; i < this->threadList.size(); i++) {
        QObject::connect((MonitorThread_IM *)this->threadList.at(i)->threadPoint, SIGNAL(SendUrgentMail_Signal(int, int)), this->eMail_IM, SLOT(SendUrgentMail(int, int)));
        QObject::connect((MonitorThread_IM *)this->threadList.at(i)->threadPoint, SIGNAL(PowerDownMail_Signal()), this->eMail_IM, SLOT(SendPowerDownMail()));
    }
    //QObject::connect(this, SIGNAL(EmailSendEn_Signal(bool)), this->timeThread, SLOT(EmailSendEn_Slot(bool))); // 已失效

}

void MonitoringPlatform_IM::StartThreads()
{
    for (int i = 0; i < this->threadList.size(); i++) {
        this->ShowThreadNode_ByID(i);

        switch(this->threadList.at(i)->type) {
        case(ThreadType::TimeThread): {
            ((TimeThread_IM *)(this->threadList.at(i)->threadPoint))->start();
            break;
        }
        case(ThreadType::MonitorThread): {
            ((MonitorThread_IM *)(this->threadList.at(i)->threadPoint))->start();
            break;
        }
        default:
            qDebug() << "[MonitoringPlatform]:" << "StartThreads: Error! No such is type.\n";
            break;
        }
        qDebug() << "[MonitoringPlatform]:" << "Thread id:" << i << "start...\n";
        QThread::msleep(100);
    }
}

void MonitoringPlatform_IM::ShowThreadNode_ByID(int id)
{
    if (id > this->threadList.size() || id < 0) {
        qDebug() << "[MonitoringPlatform]:" << "Error, this id out of range.\n";
        return ;
    }

    qDebug() << "[MonitoringPlatform]:" << "Thread id:" << this->threadList.at(id)->id << "\n";

    switch(this->threadList.at(id)->type) {
    case(ThreadType::TimeThread): {
        qDebug() << "[MonitoringPlatform]:" << "Thread type:" << "TimeThread" << "\n";
        qDebug() << "[MonitoringPlatform]:" << "Thread GetID:" << ((TimeThread_IM *)(this->threadList.at(id)->threadPoint))->GetThreadID() << "\n";
        break;
    }
    case(ThreadType::MonitorThread): {
        qDebug() << "[MonitoringPlatform]:" << "Thread type:" << "MonitorThread" << "\n";
        qDebug() << "[MonitoringPlatform]:" << "Thread GetID:" << ((MonitorThread_IM *)(this->threadList.at(id)->threadPoint))->GetThreadID() << "\n";
        break;
    }
    default:
        qDebug() << "[MonitoringPlatform]:" << "ShowThreadNode_ByID: Error! No such is type.\n";
        break;
    }

}

// 垃圾回收函数，在进程结束时销毁所有线程并释放所有内存资源
void MonitoringPlatform_IM::GabageCollection()
{
    Thread_ListNode *node = nullptr;
    qDebug() << "[MonitoringPlatform]:" << "Gabage:list_num=" << this->threadList.size() << "\n";
    for (int i = this->threadList.size() - 1; i >= 0; i--) {

        node = this->threadList.at(i);
        this->threadList.removeAt(i);   // [注]：此行后不可再使用 this->threadList.at(i)

        //int waitTime = 2;   // 等待线程自行退出

        switch(node->type) {
        case(ThreadType::TimeThread): {
            ((TimeThread_IM *)(node->threadPoint))->ToDead();       // 结束时间线程运行
            ((TimeThread_IM *)(node->threadPoint))->quit();
            ((TimeThread_IM *)(node->threadPoint))->wait();
            //QThread::sleep(waitTime);
            delete (TimeThread_IM *)(node->threadPoint);
            this->timeThread = nullptr; // 此例只有一个时间线程，释放后不可重复释放或使用
            break;
        }
        case(ThreadType::MonitorThread): {
            ((MonitorThread_IM *)(node->threadPoint))->ToDead();                // 结束监控线程运行
            ((MonitorThread_IM *)(node->threadPoint))->quit();
            ((MonitorThread_IM *)(node->threadPoint))->wait();
            //QThread::sleep(waitTime);
            // 查找对应的 qlabel 并释放内存
            QLabel *lab = this->displayLabelMap.value(((MonitorThread_IM *)(node->threadPoint))->GetThreadID());
            this->displayLabelMap.remove(((MonitorThread_IM *)(node->threadPoint))->GetThreadID());
            delete lab;
            delete ((MonitorThread_IM *)(node->threadPoint));                   // 销毁监控线程本身
            break;
        }
        default:
            qDebug() << "[MonitoringPlatform]:" << "Gabage: Error! No such is type.\n";
            break;
        }
        delete node;
    }

    qDebug() << "[MonitoringPlatform]:" << "Gabage:list_num=" << this->threadList.size() << "\n";

    // 销毁邮件类对象
    if (this->eMail_IM) {
        delete this->eMail_IM;
    }

    // 销毁邮件配置类对象
    if (this->emailConfigure) {
        delete this->emailConfigure;
    }

    // 销毁
    if (this->aboutIM) {
        delete this->aboutIM;
    }

    if (this->urgentMutex) {
        delete this->urgentMutex;
    }

    if (this->displayMutex) {
        delete this->displayMutex;
    }

    if (this->eMailSevice_EN) {
        delete this->eMailSevice_EN;
    }

    if (this->textEditor) {
        this->textEditor->clear();
        delete this->textEditor;
    }

    // 清理菜单栏内存
    if (this->masterMenuBar) {
        this->masterMenuBar->clear();
        for (int i = 0; i < this->mainMenuList.size(); i++) {
            MainMenuModule *menuModule = this->mainMenuList.at(i);
            this->mainMenuList.removeAt(i);
            delete menuModule;
        }
        this->mainMenuList.clear();
        delete this->masterMenuBar;
    }
}

void MonitoringPlatform_IM::NewActionForMainMenu(MainMenuModule *mainMenu, QString actionName, void (MonitoringPlatform_IM::*func)(), QString icoPath)
{
    if (mainMenu) {
        MainMenuActionModeule actionModule;

        actionModule.name = actionName;
        actionModule.action = mainMenu->menu->addAction(actionModule.name);
        actionModule.func = func;

        if (icoPath != "") {
            actionModule.action->setIcon(QIcon(icoPath));
        }

        mainMenu->actionList.append(actionModule);
    }
}

void MonitoringPlatform_IM::ShowEmailConfigure()
{
    if (this->emailConfigure) {
        this->emailConfigure->show();
    }
}

void MonitoringPlatform_IM::EmailServiceStart()
{
    /*
    if (this->emailConfigure->CheckConfigure()) {
        QMessageBox::critical(this, tr("信息不足"), tr("前请先配置邮件服务！\n请确保信息填写完整及正确！"), QMessageBox::Ok, QMessageBox::Ok);
    }
    */
    // -TODO: 启动邮件服务++++++++++++++++++++++++++++++++++++++
    this->Init_Email_IM();
    this->ConnectSignalToEmailSlot();
    *this->eMailSevice_EN = true;
    QString message = "        尊贵的订阅用户您好！欢迎使用“IM服务器监测软件”,收到此封邮件则表示您已加入服务器状态的通知名单。您将在每天 06点、12点、19点、23点整收到被监测服务器的实时状态。当服务器存在风险时（服务器温度超过 65℃），您将会收到及时通知邮件，即时请视情况处理。若您超时未能处理，本软件将会在风险等级达到最高时强制服务器关机，同时您将收到风险解除通知，因此您可不必为无法及时处理而担心。";
    QDateTime datetime = QDateTime::currentDateTime();
    message += "<br><br>" + datetime.toString("yyyy-MM-dd HH:mm:ss");

    if (this->emailConfigure->CheckFirstNotice()) {
        if (this->emailConfigure->GetRecvEmailList()) {
            for (int i = 0; i < this->emailConfigure->GetRecvEmailList()->size(); i++) {
                this->eMail_IM->Smtp_IM(this->emailConfigure->GetRecvEmailList()->at(i), message, QString("尊贵的订阅用户"), QString("欢迎"));
            }
        }
    } else {
        this->eMail_IM->Smtp_IM(this->emailConfigure->GetMasterEmailAddress(), QString("您的软件已被正常启动，请安心正常使用。"), QString("尊贵的订阅用户"), QString("欢迎"));
    }

}

void MonitoringPlatform_IM::MonitorThreadReConnect()
{
    for (int i = 0; i < this->serverDetailList.size(); i++) {
        if (this->serverDetailList.at(i)->serverState.tcpConnectStatus == false || this->serverDetailList.at(i)->powerStatus == false) {
            ((MonitorThread_IM *)this->threadList.at(i + 1)->threadPoint)->ReConnectToHost();
        }
    }
}

void MonitoringPlatform_IM::ShowAboutIM()
{
    if (this->aboutIM) {
        this->aboutIM->show();
    }
}

void MonitoringPlatform_IM::RiskDisplayMode_Slot(int threadID)
{
    this->displayLabelMap.value(threadID)->setStyleSheet("color:#D90000;");
    *this->displayMutex = true;
}

void MonitoringPlatform_IM::SafeDisplayMode_Slot(int threadID)
{
    this->displayLabelMap.value(threadID)->setStyleSheet("color:#000000;");
    *this->displayMutex = true;
}

void MonitoringPlatform_IM::FlushMainWindow()
{
    //qDebug() << "界面刷新\n";
    //this->repaint();        // 刷新主界面
    this->update();   // 刷新主界面
    return;
}

void MonitoringPlatform_IM::ClearTextEditor_Slot()
{
    if (this->textEditor) {
        this->textEditor->clear();
    }

    return ;
}

void MonitoringPlatform_IM::changeEvent(QEvent *event)
{
    //Qt::WindowMaximized 为最大化时触发，Qt::WindowMinimized 是最小化时触发

    if (this->windowState() == Qt::WindowMaximized) {

        this->ui->Lab_SystemRunTime->setGeometry(1400, 950, 500, 50);
        this->ui->LcdNum_DateTime->setGeometry(1120, 1000, 900, 50);
        this->ui->CheckBox_Email_En->setGeometry(20, 1000, 80, 20);
        this->ui->Lab_SystemRunTime->setFont(QFont("Microsoft YaHei UI", 18));


        for (int i = 1; i < this->threadList.size(); i++) {
            this->displayLabelMap.value(i)->setGeometry(30, (i) * 40 - 30 + 10, 1500, 40);
            this->displayLabelMap.value(i)->setFont(QFont("Microsoft YaHei UI", 16));
        }

        if (this->masterMenuBar) {
            this->masterMenuBar->resize(this->width(), this->masterMenuBar->height());
        }

        return;
    }

    if (this->windowState() != Qt::WindowMinimized) {

        this->ui->Lab_SystemRunTime->setGeometry(500, 500, 261, 41);
        this->ui->LcdNum_DateTime->setGeometry(330, 549, 461, 41);
        this->ui->CheckBox_Email_En->setGeometry(20, 560, 80, 20);
        this->ui->Lab_SystemRunTime->setFont(QFont("Microsoft YaHei UI", 12));


        for (int i = 1; i < this->threadList.size(); i++) {
            this->displayLabelMap.value(i)->setGeometry(30, (i) * 20 - 10 + 10, 720, 20);
            this->displayLabelMap.value(i)->setFont(QFont("Microsoft YaHei UI", 9));
        }


        if (this->masterMenuBar) {
            this->masterMenuBar->resize(this->width(), this->masterMenuBar->height());
        }

        return ;
    }

    return;
}


void MonitoringPlatform_IM::on_CheckBox_Email_En_stateChanged(int arg1)
{
    // 若邮件服务系统开启，将不会关闭，只能通过该信号选择是否使用邮件服务
    if (*this->eMailSevice_EN) {
        *this->eMailSend_EN = this->ui->CheckBox_Email_En->checkState();
        qDebug() << "[MonitoringPlatform]:" << "CheckBox_Email_En:" << (this->ui->CheckBox_Email_En->checkState() ? "true" : "false") << "\n";

        return;
    }

    // -TODO: 初始化邮件服务

    if (this->emailConfigure->CheckConfigure()) {
        this->EmailServiceStart();
    } else {
        this->ui->CheckBox_Email_En->setChecked(false);
        QMessageBox::critical(this, tr("信息不足"), tr("前请先配置邮件服务！\n请确保信息填写完整及正确！"), QMessageBox::Ok, QMessageBox::Ok);
    }
}


void MonitoringPlatform_IM::on_CheckBox_Email_En_clicked()
{
    this->on_CheckBox_Email_En_stateChanged(1);
}

