#include "emailconfigure.h"
#include "ui_emailconfigure.h"

EmailConfigure::EmailConfigure(QWidget *parent) :
    QWidget(parent), ui(new Ui::EmailConfigure), recvEmailList(nullptr), configureOK(false)
{
    ui->setupUi(this);
    this->setWindowTitle("Email 服务设置");
    this->Init_UI();        // 初始化界面
    this->Init_Parameters();    // 初始化成员参数
}

EmailConfigure::~EmailConfigure()
{
    delete ui;
}

void EmailConfigure::Init_UI()
{
    this->ui->CheckBox_EmailTencent->setTristate(false);    // 设置复选框只有两种状态
    this->ui->CheckBox_EmailOutlook->setTristate(false);    // 设置复选框只有两种状态
    this->ui->LEdit_MasterEmailAddress->setPlaceholderText(QString("请输入主机邮箱地址"));
    this->ui->LEdit_MasterEmailPasswd->setPlaceholderText(QString("请输入主机邮箱密码"));
    this->ui->LEdit_MasterEmailName->setPlaceholderText(QString("该名称将作为邮件发送人昵称"));
    this->ui->LEdit_RecvEmailAddress->setPlaceholderText(QString("请输入收件人邮箱"));

    this->ui->Lab_Tips->setText(QString("[提示]：此版本无校验纠错功能，\n请确保输入信息完整且正确！"));
    this->ui->Lab_Tips->setStyleSheet("color:#C40509;");

    this->ui->Btn_AddEmail->setText("");
    this->ui->Btn_DelEmail->setText("");
    this->ui->Btn_AddEmail->setIcon(QIcon(":/ico/ico/add.ico"));
    this->ui->Btn_DelEmail->setIcon(QIcon(":/ico/ico/del.ico"));

}

void EmailConfigure::Init_Parameters()
{
    this->recvEmailList = new QList<QString>;
}

void EmailConfigure::GabageCollection()
{
    if (this->recvEmailList) {
        delete this->recvEmailList;
    }
}

bool EmailConfigure::CheckConfigure()
{
    return this->configureOK;
}

QString EmailConfigure::GetMasterEmailAddress()
{
    return this->masterEmailAddress;
}

QString EmailConfigure::GetMasterEmailPasswd()
{
    return this->masterEmailPasswd;
}

QString EmailConfigure::GetMasterEmailName()
{
    return this->masterName;
}

EmailType EmailConfigure::GetMasterEmailType()
{
    return this->emailType;
}

QList<QString> *EmailConfigure::GetRecvEmailList()
{
    return this->recvEmailList;
}

bool EmailConfigure::CheckFirstNotice()
{
    return this->ui->CheckBox_FirstNotice->isChecked();
}

void EmailConfigure::on_CheckBox_EmailOutlook_stateChanged(int arg1)
{
    if (this->ui->CheckBox_EmailOutlook->checkState()) {
        this->ui->CheckBox_EmailTencent->setChecked(false);

        this->emailType = OUTLOOK;
    }

    return;
}


void EmailConfigure::on_CheckBox_EmailTencent_stateChanged(int arg1)
{
    if (this->ui->CheckBox_EmailTencent->checkState()) {
        this->ui->CheckBox_EmailOutlook->setChecked(false);

        this->emailType = TENCENT;
    }

    return;
}


void EmailConfigure::on_Btn_Enter_clicked()
{
    if (this->ui->LEdit_MasterEmailAddress->text() == "" ||
            this->ui->LEdit_MasterEmailPasswd->text() == "" ||
            this->ui->LEdit_MasterEmailName->text() == "" ||
            this->ui->ComBox_RecvEmailList->currentText() == "" ||
            (this->ui->CheckBox_EmailOutlook->checkState() == false && this->ui->CheckBox_EmailTencent->checkState() == false)) {
        QMessageBox::critical(this, tr("信息错误"), tr("该配置不满足启动系统。\n请确保信息填写完整及正确！"), QMessageBox::Ok, QMessageBox::Ok);
        return ;
    }

    this->masterEmailAddress = this->ui->LEdit_MasterEmailAddress->text();
    this->masterEmailPasswd = this->ui->LEdit_MasterEmailPasswd->text();
    this->masterName = this->ui->LEdit_MasterEmailName->text();

    qDebug() << "master email:" << this->masterEmailAddress << "\n";
    qDebug() << "master email passwd:" << this->masterEmailPasswd << "\n";
    qDebug() << "master email name:" << this->masterName << "\n";
    qDebug() << "master email type:" << (this->emailType == OUTLOOK ? "outlook" : "tencent") << "\n";

    for (int i = 0; i < this->recvEmailList->size(); i++) {
        qDebug() << "recv email:[" << i << "]" << this->recvEmailList->at(i) << "\n";
    }

    this->configureOK = true;

    this->hide();

    return;
}


void EmailConfigure::on_Btn_AddEmail_clicked()
{
    QString emailAddress = this->ui->LEdit_RecvEmailAddress->text().simplified();
    if (emailAddress != "") {
        if (this->recvEmailList) {
            for (int i = 0; i < this->recvEmailList->size(); i++) {
                if (emailAddress == this->recvEmailList->at(i)) {
                    // 信息已录入，无需多做动作
                    return;
                }
            }
            this->ui->ComBox_RecvEmailList->addItem(emailAddress);
            this->recvEmailList->append(emailAddress);
            this->ui->ComBox_RecvEmailList->setCurrentIndex(this->ui->ComBox_RecvEmailList->count() - 1);
        }
    }

    return;
}


void EmailConfigure::on_Btn_DelEmail_clicked()
{
    QString emailAddress = this->ui->ComBox_RecvEmailList->currentText();
    if (emailAddress != "") {
        if (this->recvEmailList) {
            for (int i = 0; i < this->recvEmailList->size(); i++) {
                if (emailAddress == this->recvEmailList->at(i)) {
                    // 信息已录入，无需多做动作
                    this->recvEmailList->removeAt(i);
                    break;
                }
            }
            this->ui->ComBox_RecvEmailList->removeItem(this->ui->ComBox_RecvEmailList->currentIndex());
            this->ui->ComBox_RecvEmailList->setCurrentIndex(this->ui->ComBox_RecvEmailList->count() - 1);
        }
    }

    return ;
}


void EmailConfigure::on_Btn_Cancel_clicked()
{
    this->hide();
}

