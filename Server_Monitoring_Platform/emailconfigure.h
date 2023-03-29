#ifndef EMAILCONFIGURE_H
#define EMAILCONFIGURE_H

#include "typelist.h"

#include <QWidget>
#include <QString>
#include <QList>
#include <QMessageBox>

namespace Ui {
class EmailConfigure;
}

class EmailConfigure : public QWidget
{
    Q_OBJECT

public:
    explicit EmailConfigure(QWidget *parent = nullptr);
    ~EmailConfigure();

    void Init_UI(void); // 初始化 UI 界面

    void Init_Parameters(void); // 初始化成员变量

    void GabageCollection(void);  // 内存回收函数，释放所有动态申请的内存空间

    bool CheckConfigure(void);  // 查看配置是否完成

    QString GetMasterEmailAddress(void);
    QString GetMasterEmailPasswd(void);
    QString GetMasterEmailName(void);
    EmailType GetMasterEmailType(void);

    QList<QString> * GetRecvEmailList(void);

    bool CheckFirstNotice(void);    // 检查是否需要首次通知

private slots:
    void on_CheckBox_EmailOutlook_stateChanged(int arg1);

    void on_CheckBox_EmailTencent_stateChanged(int arg1);

    void on_Btn_Enter_clicked();

    void on_Btn_AddEmail_clicked();

    void on_Btn_DelEmail_clicked();

    void on_Btn_Cancel_clicked();

private:
    Ui::EmailConfigure *ui;
    QString masterEmailAddress;     // 主机邮箱地址
    QString masterEmailPasswd;      // 主机邮箱密码
    QString masterName;             // 邮箱名
    EmailType   emailType;          // 邮件类型 outlook 或者 tencent

    QList<QString> *recvEmailList;   // 收件人列表

    bool configureOK;       // 配置是否完成
};

#endif // EMAILCONFIGURE_H
