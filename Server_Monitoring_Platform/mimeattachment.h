#ifndef MIMEATTACHMENT_H
#define MIMEATTACHMENT_H


#include "smtp_im_global.h"
#include "mimepart.h"
#include "mimefile.h"

class SMTP_MIME_EXPORT MimeAttachment : public MimeFile
{
public:

    /* [1] Constructors and Destructors */

    MimeAttachment(QFile* file);
    ~MimeAttachment();

    /* [1] --- */

protected:

    /* [2] Protected methods */
    /* [2] --- */
};

#endif // MIMEATTACHMENT_H
