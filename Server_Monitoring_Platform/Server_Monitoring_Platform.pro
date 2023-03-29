QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RC_ICONS += ico/Server_MonitoringPlatform.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about_im.cpp \
    email_im.cpp \
    emailaddress.cpp \
    emailconfigure.cpp \
    main.cpp \
    mimeattachment.cpp \
    mimebase64encoder.cpp \
    mimebase64formatter.cpp \
    mimebytearrayattachment.cpp \
    mimecontentencoder.cpp \
    mimecontentformatter.cpp \
    mimefile.cpp \
    mimehtml.cpp \
    mimeinlinefile.cpp \
    mimemessage.cpp \
    mimemultipart.cpp \
    mimepart.cpp \
    mimeqpencoder.cpp \
    mimeqpformatter.cpp \
    mimetext.cpp \
    monitoringplatform_im.cpp \
    monitorthread_im.cpp \
    quotedprintable.cpp \
    smtpclient.cpp \
    timethread_im.cpp

HEADERS += \
    about_im.h \
    email_im.h \
    emailaddress.h \
    emailconfigure.h \
    headlist.h \
    mimeattachment.h \
    mimebase64encoder.h \
    mimebase64formatter.h \
    mimebytearrayattachment.h \
    mimecontentencoder.h \
    mimecontentformatter.h \
    mimefile.h \
    mimehtml.h \
    mimeinlinefile.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimeqpencoder.h \
    mimeqpformatter.h \
    mimetext.h \
    monitoringplatform_im.h \
    monitorthread_im.h \
    quotedprintable.h \
    smtp_im_global.h \
    smtpclient.h \
    timethread_im.h \
    typelist.h

FORMS += \
    about_im.ui \
    emailconfigure.ui \
    monitoringplatform_im.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    logo.qrc


