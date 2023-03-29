/********************************************************************************
** Form generated from reading UI file 'about_im.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_IM_H
#define UI_ABOUT_IM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About_IM
{
public:
    QLabel *Lab_Logo;
    QLabel *Lab_AppName;
    QLabel *Lab_AppVersionNumber;
    QLabel *Lab_AppAuthor;
    QLabel *Lab_AppTime;
    QLabel *Lab_AppNote;
    QLabel *Lab_AppNameV;
    QLabel *Lab_AppVersionV;
    QLabel *Lab_AppTimeV;
    QLabel *Lab_AppAuthorV;
    QLabel *Lab_AppNoteV;

    void setupUi(QWidget *About_IM)
    {
        if (About_IM->objectName().isEmpty())
            About_IM->setObjectName("About_IM");
        About_IM->resize(400, 300);
        Lab_Logo = new QLabel(About_IM);
        Lab_Logo->setObjectName("Lab_Logo");
        Lab_Logo->setGeometry(QRect(40, 35, 100, 100));
        Lab_AppName = new QLabel(About_IM);
        Lab_AppName->setObjectName("Lab_AppName");
        Lab_AppName->setGeometry(QRect(170, 30, 52, 22));
        Lab_AppVersionNumber = new QLabel(About_IM);
        Lab_AppVersionNumber->setObjectName("Lab_AppVersionNumber");
        Lab_AppVersionNumber->setGeometry(QRect(170, 60, 52, 22));
        Lab_AppAuthor = new QLabel(About_IM);
        Lab_AppAuthor->setObjectName("Lab_AppAuthor");
        Lab_AppAuthor->setGeometry(QRect(184, 120, 30, 22));
        Lab_AppTime = new QLabel(About_IM);
        Lab_AppTime->setObjectName("Lab_AppTime");
        Lab_AppTime->setGeometry(QRect(160, 90, 52, 22));
        Lab_AppNote = new QLabel(About_IM);
        Lab_AppNote->setObjectName("Lab_AppNote");
        Lab_AppNote->setGeometry(QRect(20, 160, 30, 22));
        Lab_AppNameV = new QLabel(About_IM);
        Lab_AppNameV->setObjectName("Lab_AppNameV");
        Lab_AppNameV->setGeometry(QRect(220, 30, 141, 22));
        Lab_AppVersionV = new QLabel(About_IM);
        Lab_AppVersionV->setObjectName("Lab_AppVersionV");
        Lab_AppVersionV->setGeometry(QRect(220, 60, 170, 22));
        Lab_AppTimeV = new QLabel(About_IM);
        Lab_AppTimeV->setObjectName("Lab_AppTimeV");
        Lab_AppTimeV->setGeometry(QRect(220, 90, 161, 22));
        Lab_AppAuthorV = new QLabel(About_IM);
        Lab_AppAuthorV->setObjectName("Lab_AppAuthorV");
        Lab_AppAuthorV->setGeometry(QRect(220, 120, 111, 22));
        Lab_AppNoteV = new QLabel(About_IM);
        Lab_AppNoteV->setObjectName("Lab_AppNoteV");
        Lab_AppNoteV->setGeometry(QRect(20, 190, 361, 61));
        Lab_AppNoteV->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        retranslateUi(About_IM);

        QMetaObject::connectSlotsByName(About_IM);
    } // setupUi

    void retranslateUi(QWidget *About_IM)
    {
        About_IM->setWindowTitle(QCoreApplication::translate("About_IM", "Form", nullptr));
        Lab_Logo->setText(QCoreApplication::translate("About_IM", "TextLabel", nullptr));
        Lab_AppName->setText(QCoreApplication::translate("About_IM", "\350\275\257\344\273\266\345\220\215\357\274\232", nullptr));
        Lab_AppVersionNumber->setText(QCoreApplication::translate("About_IM", "\347\211\210\346\234\254\345\217\267\357\274\232", nullptr));
        Lab_AppAuthor->setText(QCoreApplication::translate("About_IM", "\344\275\234\350\200\205\357\274\232", nullptr));
        Lab_AppTime->setText(QCoreApplication::translate("About_IM", "\345\217\221\345\270\203\346\227\266\351\227\264\357\274\232", nullptr));
        Lab_AppNote->setText(QCoreApplication::translate("About_IM", "\346\217\217\350\277\260\357\274\232", nullptr));
        Lab_AppNameV->setText(QCoreApplication::translate("About_IM", "\346\234\215\345\212\241\345\231\250\347\212\266\346\200\201\347\233\221\346\265\213\351\200\232\347\237\245\345\212\251\346\211\213", nullptr));
        Lab_AppVersionV->setText(QCoreApplication::translate("About_IM", "V1.4.Release.CN.b*******", nullptr));
        Lab_AppTimeV->setText(QCoreApplication::translate("About_IM", "2023\345\271\264*********", nullptr));
        Lab_AppAuthorV->setText(QCoreApplication::translate("About_IM", "Imagine Miracle", nullptr));
        Lab_AppNoteV->setText(QCoreApplication::translate("About_IM", "Imagine Miracle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About_IM: public Ui_About_IM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_IM_H
