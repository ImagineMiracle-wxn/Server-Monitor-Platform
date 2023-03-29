#ifndef MIMEINLINEFILE_H
#define MIMEINLINEFILE_H

#include "smtp_im_global.h"
#include "mimefile.h"

class SMTP_MIME_EXPORT MimeInlineFile : public MimeFile
{
public:

    /* [1] Constructors and Destructors */

    MimeInlineFile(QFile *f);
    ~MimeInlineFile();

    /* [1] --- */


    /* [2] Getters and Setters */

    /* [2] --- */

protected:

    /* [3] Protected members */

    /* [3] --- */


    /* [4] Protected methods */

    /* [4] --- */
};

#endif // MIMEINLINEFILE_H
