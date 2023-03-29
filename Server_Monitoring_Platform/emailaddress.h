#ifndef EMAILADDRESS_H
#define EMAILADDRESS_H

#include "smtp_im_global.h"
#include <QString>

class SMTP_MIME_EXPORT EmailAddress
{
public:
    // Constructs and Destructors
    EmailAddress(const QString &address = "", const QString &name = "");
    ~EmailAddress();

    // Getters and Setters
    QString getAddress() const;
    QString getName() const;

private:

    QString address;
    QString name;
};

#endif // EMAILADDRESS_H
