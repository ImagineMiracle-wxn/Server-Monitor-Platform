#ifndef MIMEMESSAGE_H
#define MIMEMESSAGE_H

#include <QObject>
#include <QStringList>
#include <QTextStream>

#include "smtp_im_global.h"
#include "mimepart.h"
#include "mimemultipart.h"
#include "emailaddress.h"

class SMTP_MIME_EXPORT MimeMessage : public QObject
{
public:

    enum RecipientType {
        To,                 // primary
        Cc,                 // carbon copy
        Bcc                 // blind carbon copy
    };

    /* [1] Constructors and Destructors */

    MimeMessage(bool createAutoMimeContent = true);
    ~MimeMessage();

    /* [1] --- */


    /* [2] Getters and Setters */

    void setSender(const EmailAddress &sndr);
    void addRecipient(const EmailAddress &rcpt, RecipientType type = To);
    void addTo(const EmailAddress &rcpt);
    void addCc(const EmailAddress &rcpt);
    void addBcc(const EmailAddress &rcpt);
    void addCustomHeader(const QString &hdr);
    void setSubject(const QString &subject);
    void addPart(MimePart* part);

    void setHeaderEncoding(MimePart::Encoding);

    EmailAddress getSender() const;
    const QList<EmailAddress> &getRecipients(RecipientType type = To) const;
    QString getSubject() const;
    const QStringList &getCustomHeaders() const;
    const QList<MimePart*> & getParts() const;

    MimePart& getContent();
    void setContent(MimePart *content);
    /* [2] --- */


    /* [3] Public methods */

    virtual QString toString() const;
    void writeToDevice(QIODevice &device) const;

    /* [3] --- */

    /* Add by wxn 2023/03/17
     * Function: 清除单次发送后的数据（需要多次发送但不叠加时使用）
     */
    void ClearBuf_IM(void);

protected:

    /* [4] Protected members */

    EmailAddress sender;
    QList<EmailAddress> recipientsTo, recipientsCc, recipientsBcc;
    QString subject;
    QStringList customHeaders;
    MimePart *content;

    MimePart::Encoding hEncoding;

    static QByteArray format(const QString &text, MimePart::Encoding encoding);
    static QByteArray formatAddress(const EmailAddress &address, MimePart::Encoding encoding);

    /* [4] --- */


};

#endif // MIMEMESSAGE_H
