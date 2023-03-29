#ifndef MIMEFILE_H
#define MIMEFILE_H

#include "mimepart.h"
#include "smtp_im_global.h"

class QFile;

class SMTP_MIME_EXPORT MimeFile : public MimePart
{
public:

    /* [1] Constructors and Destructors */

    MimeFile(QFile *f);
    ~MimeFile();

    /* [1] --- */


    /* [2] Getters and Setters */

    /* [2] --- */

protected:

    /* [3] Protected members */

    QFile* file;

    /* [3] --- */


    /* [4] Protected methods */

    void writeContent(QIODevice &device) const;


    /* [4] --- */

};

#endif // MIMEFILE_H
