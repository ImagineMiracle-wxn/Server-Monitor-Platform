#ifndef MIMEHTML_H
#define MIMEHTML_H

#include "smtp_im_global.h"
#include "mimetext.h"

class SMTP_MIME_EXPORT MimeHtml : public MimeText
{
public:

    /* [1] Constructors and Destructors */

    MimeHtml(const QString &html = "");
    ~MimeHtml();

    /* [1] --- */


    /* [2] Getters and Setters */

    void setHtml(const QString & html);

    QString getHtml() const;

    /* [2] --- */

protected:

    /* [3] Protected members */

    /* [3] --- */


    /* [4] Protected methods */

    /* [4] --- */
};

#endif // MIMEHTML_H
