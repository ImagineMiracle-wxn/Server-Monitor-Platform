#include "emailaddress.h"

EmailAddress::EmailAddress(const QString &address, const QString &name)
    : address(address), name(name)
{
    return ;
}

EmailAddress::~EmailAddress()
{
    return;
}

QString EmailAddress::getAddress() const
{
    return this->address;
}

QString EmailAddress::getName() const
{
    return this->name;
}


