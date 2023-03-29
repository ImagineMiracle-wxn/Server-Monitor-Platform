#ifndef QUOTEDPRINTABLE_H
#define QUOTEDPRINTABLE_H

#include <QByteArray>
#include <QString>
#include "smtp_im_global.h"

namespace QuotedPrintable {
    SMTP_MIME_EXPORT QString encode(const QByteArray &input);
    SMTP_MIME_EXPORT QByteArray decode(const QString &input);
}

#endif // QUOTEDPRINTABLE_H
