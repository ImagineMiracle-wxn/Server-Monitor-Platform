#ifndef MIMEPART_H
#define MIMEPART_H

#include "smtp_im_global.h"
#include <QByteArray>
#include <QString>

class QIODevice;

class SMTP_MIME_EXPORT MimePart
{
public:

    /* [0] Enumerations */
    enum Encoding {        
        _7Bit,
        _8Bit,
        Base64,
        QuotedPrintable
    };


    /* [0] --- */


    /* [1] Constructors and Destructors */

    MimePart();
    virtual ~MimePart();

    /* [1] --- */


    /* [2] Getters and Setters */

    void setContent(const QByteArray & content);
    QByteArray getContent() const;

    void setHeader(const QString & headerLines);
    QString getHeader() const;

    void addHeaderLine(const QString & line);

    void setContentId(const QString & cId);
    QString getContentId() const;

    void setContentName(const QString & cName);
    QString getContentName() const;

    void setContentType(const QString & cType);
    QString getContentType() const;

    void setCharset(const QString & charset);
    QString getCharset() const;

    void setEncoding(Encoding enc);
    Encoding getEncoding() const;

    void setMaxLineLength(const int length);
    int getMaxLineLength() const;

    /* [2] --- */


    /* [3] Public methods */

    virtual QString toString() const;
    void writeToDevice(QIODevice &device) const;

    /* [3] --- */

protected:

    /* [4] Protected members */

    QString headerLines;
    QByteArray content;

    QString cId;
    QString cName;
    QString cType;
    QString cCharset;
    QString cBoundary;
    Encoding cEncoding;

    int maxLineLength;

    QString mimeString;
    bool prepared;

    /* [4] --- */

    virtual void writeContent(QIODevice &device) const;
    void writeContent(QIODevice &device, const QByteArray &content) const;
};

#endif // MIMEPART_H
