/********************************************************************************
** Form generated from reading UI file 'emailconfigure.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILCONFIGURE_H
#define UI_EMAILCONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmailConfigure
{
public:
    QGroupBox *GBox_MasterEmail;
    QLabel *Lab_MasterEmailAddress;
    QLineEdit *LEdit_MasterEmailAddress;
    QLabel *Lab_MasterEmailPasswd;
    QLineEdit *LEdit_MasterEmailPasswd;
    QLabel *Lab_MasterEmailName;
    QLineEdit *LEdit_MasterEmailName;
    QLabel *Lab_MasterEmailType;
    QCheckBox *CheckBox_EmailOutlook;
    QCheckBox *CheckBox_EmailTencent;
    QGroupBox *GBox_RecvEmail;
    QLabel *Lab_RecvEmailAddress;
    QLineEdit *LEdit_RecvEmailAddress;
    QPushButton *Btn_AddEmail;
    QPushButton *Btn_DelEmail;
    QComboBox *ComBox_RecvEmailList;
    QLabel *Lab_RecvEmailList;
    QCheckBox *CheckBox_FirstNotice;
    QPushButton *Btn_Enter;
    QPushButton *Btn_Cancel;
    QLabel *Lab_Tips;

    void setupUi(QWidget *EmailConfigure)
    {
        if (EmailConfigure->objectName().isEmpty())
            EmailConfigure->setObjectName("EmailConfigure");
        EmailConfigure->resize(400, 300);
        GBox_MasterEmail = new QGroupBox(EmailConfigure);
        GBox_MasterEmail->setObjectName("GBox_MasterEmail");
        GBox_MasterEmail->setGeometry(QRect(10, 10, 380, 140));
        Lab_MasterEmailAddress = new QLabel(GBox_MasterEmail);
        Lab_MasterEmailAddress->setObjectName("Lab_MasterEmailAddress");
        Lab_MasterEmailAddress->setGeometry(QRect(32, 20, 55, 20));
        LEdit_MasterEmailAddress = new QLineEdit(GBox_MasterEmail);
        LEdit_MasterEmailAddress->setObjectName("LEdit_MasterEmailAddress");
        LEdit_MasterEmailAddress->setGeometry(QRect(90, 19, 260, 22));
        Lab_MasterEmailPasswd = new QLabel(GBox_MasterEmail);
        Lab_MasterEmailPasswd->setObjectName("Lab_MasterEmailPasswd");
        Lab_MasterEmailPasswd->setGeometry(QRect(8, 50, 80, 20));
        LEdit_MasterEmailPasswd = new QLineEdit(GBox_MasterEmail);
        LEdit_MasterEmailPasswd->setObjectName("LEdit_MasterEmailPasswd");
        LEdit_MasterEmailPasswd->setGeometry(QRect(90, 49, 260, 22));
        LEdit_MasterEmailPasswd->setEchoMode(QLineEdit::Password);
        Lab_MasterEmailName = new QLabel(GBox_MasterEmail);
        Lab_MasterEmailName->setObjectName("Lab_MasterEmailName");
        Lab_MasterEmailName->setGeometry(QRect(19, 80, 65, 20));
        LEdit_MasterEmailName = new QLineEdit(GBox_MasterEmail);
        LEdit_MasterEmailName->setObjectName("LEdit_MasterEmailName");
        LEdit_MasterEmailName->setGeometry(QRect(90, 79, 260, 22));
        Lab_MasterEmailType = new QLabel(GBox_MasterEmail);
        Lab_MasterEmailType->setObjectName("Lab_MasterEmailType");
        Lab_MasterEmailType->setGeometry(QRect(8, 110, 80, 20));
        CheckBox_EmailOutlook = new QCheckBox(GBox_MasterEmail);
        CheckBox_EmailOutlook->setObjectName("CheckBox_EmailOutlook");
        CheckBox_EmailOutlook->setGeometry(QRect(130, 109, 80, 22));
        CheckBox_EmailTencent = new QCheckBox(GBox_MasterEmail);
        CheckBox_EmailTencent->setObjectName("CheckBox_EmailTencent");
        CheckBox_EmailTencent->setGeometry(QRect(240, 109, 80, 22));
        GBox_RecvEmail = new QGroupBox(EmailConfigure);
        GBox_RecvEmail->setObjectName("GBox_RecvEmail");
        GBox_RecvEmail->setGeometry(QRect(10, 160, 380, 101));
        Lab_RecvEmailAddress = new QLabel(GBox_RecvEmail);
        Lab_RecvEmailAddress->setObjectName("Lab_RecvEmailAddress");
        Lab_RecvEmailAddress->setGeometry(QRect(10, 20, 65, 20));
        LEdit_RecvEmailAddress = new QLineEdit(GBox_RecvEmail);
        LEdit_RecvEmailAddress->setObjectName("LEdit_RecvEmailAddress");
        LEdit_RecvEmailAddress->setGeometry(QRect(80, 20, 260, 22));
        Btn_AddEmail = new QPushButton(GBox_RecvEmail);
        Btn_AddEmail->setObjectName("Btn_AddEmail");
        Btn_AddEmail->setGeometry(QRect(345, 19, 25, 25));
        Btn_DelEmail = new QPushButton(GBox_RecvEmail);
        Btn_DelEmail->setObjectName("Btn_DelEmail");
        Btn_DelEmail->setGeometry(QRect(345, 48, 25, 25));
        ComBox_RecvEmailList = new QComboBox(GBox_RecvEmail);
        ComBox_RecvEmailList->setObjectName("ComBox_RecvEmailList");
        ComBox_RecvEmailList->setGeometry(QRect(80, 49, 260, 22));
        Lab_RecvEmailList = new QLabel(GBox_RecvEmail);
        Lab_RecvEmailList->setObjectName("Lab_RecvEmailList");
        Lab_RecvEmailList->setGeometry(QRect(10, 50, 65, 20));
        CheckBox_FirstNotice = new QCheckBox(GBox_RecvEmail);
        CheckBox_FirstNotice->setObjectName("CheckBox_FirstNotice");
        CheckBox_FirstNotice->setGeometry(QRect(10, 75, 70, 22));
        Btn_Enter = new QPushButton(EmailConfigure);
        Btn_Enter->setObjectName("Btn_Enter");
        Btn_Enter->setGeometry(QRect(220, 270, 75, 25));
        Btn_Cancel = new QPushButton(EmailConfigure);
        Btn_Cancel->setObjectName("Btn_Cancel");
        Btn_Cancel->setGeometry(QRect(310, 270, 75, 25));
        Lab_Tips = new QLabel(EmailConfigure);
        Lab_Tips->setObjectName("Lab_Tips");
        Lab_Tips->setGeometry(QRect(10, 260, 191, 31));

        retranslateUi(EmailConfigure);

        QMetaObject::connectSlotsByName(EmailConfigure);
    } // setupUi

    void retranslateUi(QWidget *EmailConfigure)
    {
        EmailConfigure->setWindowTitle(QCoreApplication::translate("EmailConfigure", "Form", nullptr));
        GBox_MasterEmail->setTitle(QCoreApplication::translate("EmailConfigure", "\344\270\273\346\234\272\351\202\256\347\256\261\351\205\215\347\275\256", nullptr));
        Lab_MasterEmailAddress->setText(QCoreApplication::translate("EmailConfigure", "\344\270\273\346\234\272\351\202\256\347\256\261:", nullptr));
        LEdit_MasterEmailAddress->setText(QString());
        Lab_MasterEmailPasswd->setText(QCoreApplication::translate("EmailConfigure", "\344\270\273\346\234\272\351\202\256\347\256\261\345\257\206\347\240\201: ", nullptr));
        LEdit_MasterEmailPasswd->setText(QString());
        Lab_MasterEmailName->setText(QCoreApplication::translate("EmailConfigure", "\351\202\256\344\273\266\345\217\221\351\200\201\344\272\272: ", nullptr));
        LEdit_MasterEmailName->setText(QString());
        Lab_MasterEmailType->setText(QCoreApplication::translate("EmailConfigure", "\344\270\273\346\234\272\351\202\256\347\256\261\347\261\273\345\236\213: ", nullptr));
        CheckBox_EmailOutlook->setText(QCoreApplication::translate("EmailConfigure", "Outlook", nullptr));
        CheckBox_EmailTencent->setText(QCoreApplication::translate("EmailConfigure", "Tencent", nullptr));
        GBox_RecvEmail->setTitle(QCoreApplication::translate("EmailConfigure", "\346\224\266\344\273\266\344\272\272\351\205\215\347\275\256", nullptr));
        Lab_RecvEmailAddress->setText(QCoreApplication::translate("EmailConfigure", "\346\224\266\344\273\266\344\272\272\351\202\256\347\256\261:", nullptr));
        LEdit_RecvEmailAddress->setText(QString());
        Btn_AddEmail->setText(QCoreApplication::translate("EmailConfigure", "\357\274\213", nullptr));
        Btn_DelEmail->setText(QCoreApplication::translate("EmailConfigure", "-", nullptr));
        Lab_RecvEmailList->setText(QCoreApplication::translate("EmailConfigure", "\346\224\266\344\273\266\344\272\272\345\210\227\350\241\250:", nullptr));
        CheckBox_FirstNotice->setText(QCoreApplication::translate("EmailConfigure", "\345\210\235\346\254\241\351\200\232\347\237\245", nullptr));
        Btn_Enter->setText(QCoreApplication::translate("EmailConfigure", "\346\217\220\344\272\244", nullptr));
        Btn_Cancel->setText(QCoreApplication::translate("EmailConfigure", "\345\217\226\346\266\210", nullptr));
        Lab_Tips->setText(QCoreApplication::translate("EmailConfigure", "[\346\217\220\347\244\272]\357\274\232\345\275\223\345\211\215\347\211\210\346\234\254\345\271\266\346\262\241\346\234\211\346\240\241\351\252\214\347\272\240\351\224\231\345\212\237\350\203\275\357\274\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmailConfigure: public Ui_EmailConfigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILCONFIGURE_H
