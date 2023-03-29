#ifndef MIMETEXT_H
#define MIMETEXT_H

#include "smtp_im_global.h"
#include "mimepart.h"

class SMTP_MIME_EXPORT MimeText : public MimePart
{
public:

    /* [1] Constructors and Destructors */

    MimeText(const QString &text = "");
    ~MimeText();

    /* [1] --- */


    /* [2] Getters and Setters*/

    void setText(const QString & text);

    const QString & getText() const;

    /* [2] --- */

protected:

    /* [3] Protected members */

    QString text;
    /* [3] --- */


    /* [4] Protected methods */

    void writeContent(QIODevice &device) const;

    /* [4] --- */

};

#endif // MIMETEXT_H
