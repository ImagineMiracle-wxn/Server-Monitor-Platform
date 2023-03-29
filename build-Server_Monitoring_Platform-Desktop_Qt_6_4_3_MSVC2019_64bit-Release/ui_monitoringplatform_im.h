/********************************************************************************
** Form generated from reading UI file 'monitoringplatform_im.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITORINGPLATFORM_IM_H
#define UI_MONITORINGPLATFORM_IM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MonitoringPlatform_IM
{
public:
    QLCDNumber *LcdNum_DateTime;
    QLabel *Lab_SystemRunTime;
    QCheckBox *CheckBox_Email_En;

    void setupUi(QWidget *MonitoringPlatform_IM)
    {
        if (MonitoringPlatform_IM->objectName().isEmpty())
            MonitoringPlatform_IM->setObjectName("MonitoringPlatform_IM");
        MonitoringPlatform_IM->resize(800, 600);
        LcdNum_DateTime = new QLCDNumber(MonitoringPlatform_IM);
        LcdNum_DateTime->setObjectName("LcdNum_DateTime");
        LcdNum_DateTime->setGeometry(QRect(330, 549, 461, 41));
        LcdNum_DateTime->setDigitCount(25);
        Lab_SystemRunTime = new QLabel(MonitoringPlatform_IM);
        Lab_SystemRunTime->setObjectName("Lab_SystemRunTime");
        Lab_SystemRunTime->setGeometry(QRect(460, 500, 261, 41));
        QFont font;
        font.setPointSize(12);
        Lab_SystemRunTime->setFont(font);
        Lab_SystemRunTime->setLayoutDirection(Qt::LeftToRight);
        Lab_SystemRunTime->setAlignment(Qt::AlignCenter);
        CheckBox_Email_En = new QCheckBox(MonitoringPlatform_IM);
        CheckBox_Email_En->setObjectName("CheckBox_Email_En");
        CheckBox_Email_En->setGeometry(QRect(20, 560, 80, 20));

        retranslateUi(MonitoringPlatform_IM);

        QMetaObject::connectSlotsByName(MonitoringPlatform_IM);
    } // setupUi

    void retranslateUi(QWidget *MonitoringPlatform_IM)
    {
        MonitoringPlatform_IM->setWindowTitle(QCoreApplication::translate("MonitoringPlatform_IM", "MonitoringPlatform_IM", nullptr));
        Lab_SystemRunTime->setText(QCoreApplication::translate("MonitoringPlatform_IM", "\347\250\213\345\272\217\345\267\262\350\277\220\350\241\21488\345\244\25188\345\260\217\346\227\26688\345\210\206", nullptr));
        CheckBox_Email_En->setText(QCoreApplication::translate("MonitoringPlatform_IM", "\351\202\256\344\273\266\351\200\232\347\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MonitoringPlatform_IM: public Ui_MonitoringPlatform_IM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITORINGPLATFORM_IM_H
