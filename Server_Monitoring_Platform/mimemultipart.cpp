#include "mimemultipart.h"
#include <QIODevice>
#include <QTime>
#include <QCryptographicHash>
#include <QRandomGenerator>

const QString MULTI_PART_NAMES[] = {
    "multipart/mixed",         //    Mixed
    "multipart/digest",        //    Digest
    "multipart/alternative",   //    Alternative
    "multipart/related",       //    Related
    "multipart/report",        //    Report
    "multipart/signed",        //    Signed
    "multipart/encrypted"      //    Encrypted
};

MimeMultiPart::MimeMultiPart(MultiPartType type)
{
    this->type = type;
    this->cType = MULTI_PART_NAMES[this->type];
    this->cEncoding = _8Bit;

    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(QByteArray().append(QRandomGenerator::global()->generate64()));
    cBoundary = md5.result().toHex();
}

MimeMultiPart::~MimeMultiPart() {
    foreach (MimePart *part, parts) {
        delete part;
    }
}

void MimeMultiPart::addPart(MimePart *part) {
    parts.clear();      // Add by wxn 2023/03/17
    parts.append(part);
}

const QList<MimePart*> & MimeMultiPart::getParts() const {
    return parts;
}

void MimeMultiPart::writeContent(QIODevice &device) const {
    QList<MimePart*>::const_iterator it;

    for (it = parts.constBegin(); it != parts.constEnd(); it++) {
        device.write("--" );
        device.write(cBoundary.toLatin1());
        device.write("\r\n");
        (*it)->writeToDevice(device);
    };

    device.write("--");
    device.write(cBoundary.toLatin1());
    device.write("--\r\n");
}

void MimeMultiPart::ClearBuf_IM()
{
    this->parts.clear();
}


void MimeMultiPart::setMimeType(const MultiPartType type) {
    this->type = type;
    this->cType = MULTI_PART_NAMES[type];
}

MimeMultiPart::MultiPartType MimeMultiPart::getMimeType() const {
    return type;
}
