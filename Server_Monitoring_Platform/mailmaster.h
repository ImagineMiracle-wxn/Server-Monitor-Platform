#ifndef MAILMASTER_H
#define MAILMASTER_H

#include <QWidget>
#include "smtp_im.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MailMaster; }
QT_END_NAMESPACE

class MailMaster : public QWidget
{
    Q_OBJECT

public:
    MailMaster(QWidget *parent = nullptr);
    ~MailMaster();

private:
    Ui::MailMaster *ui;

    Smtp_IM *smtp;
};
#endif // MAILMASTER_H
