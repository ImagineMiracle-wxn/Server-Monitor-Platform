#include "mimetext.h"

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QStringEncoder>
#else
#include <QTextEncoder>
#endif

/* [1] Constructors and Destructors */

MimeText::MimeText(const QString &txt)
{
    this->text = txt;
    this->cType = "text/plain";
    this->cCharset = "utf-8";
    this->cEncoding = _8Bit;
}

MimeText::~MimeText() { }

/* [1] --- */


/* [2] Getters and Setters */

void MimeText::setText(const QString & text)
{
    this->text = text;
}

const QString & MimeText::getText() const
{
    return text;
}

/* [2] --- */


/* [3] Protected Methods */

void MimeText::writeContent(QIODevice &device) const {
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    MimePart::writeContent(device, QStringEncoder(this->cCharset.toStdString().c_str()).encode(text));
#else
    MimePart::writeContent(device, QTextEncoder(QTextCodec::codecForName(this->cCharset.toStdString().c_str())).fromUnicode(text));
#endif
}

/* [3] --- */
