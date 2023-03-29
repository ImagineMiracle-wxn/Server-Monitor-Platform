#include "mimeinlinefile.h"

/* [1] Constructors and Destructors */

MimeInlineFile::MimeInlineFile(QFile *f)
    : MimeFile(f)
{
    addHeaderLine("Content-Disposition: inline");
}

MimeInlineFile::~MimeInlineFile()
{}

/* [1] --- */


/* [2] Getters and Setters */

/* [2] --- */


/* [3] Protected methods */

/* [3] --- */



