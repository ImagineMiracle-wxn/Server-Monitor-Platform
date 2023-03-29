#include "mimefile.h"
#include <QFileInfo>

/* [1] Constructors and Destructors */

MimeFile::MimeFile(QFile *file)
{
    this->file = file;
    this->cType = "application/octet-stream";
    this->cName = QFileInfo(*file).fileName();
    this->cEncoding = Base64;
}

MimeFile::~MimeFile()
{
}

/* [1] --- */


/* [2] Getters and setters */

/* [2] --- */


/* [3] Protected methods */


void MimeFile::writeContent(QIODevice &device) const {
    file->open(QIODevice::ReadOnly);    
    const QByteArray &fileContent = file->readAll();
    file->close();

    MimePart::writeContent(device, fileContent);
}

/* [3] --- */

