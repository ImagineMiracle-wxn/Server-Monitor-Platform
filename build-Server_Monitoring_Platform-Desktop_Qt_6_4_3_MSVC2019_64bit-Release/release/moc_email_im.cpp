/****************************************************************************
** Meta object code from reading C++ file 'email_im.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Server_Monitoring_Platform/email_im.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'email_im.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Email_IM_t {
    uint offsetsAndSizes[34];
    char stringdata0[9];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[15];
    char stringdata5[18];
    char stringdata6[10];
    char stringdata7[5];
    char stringdata8[5];
    char stringdata9[3];
    char stringdata10[8];
    char stringdata11[8];
    char stringdata12[10];
    char stringdata13[4];
    char stringdata14[25];
    char stringdata15[8];
    char stringdata16[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Email_IM_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Email_IM_t qt_meta_stringdata_Email_IM = {
    {
        QT_MOC_LITERAL(0, 8),  // "Email_IM"
        QT_MOC_LITERAL(9, 22),  // "ClearTextEditor_Signal"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 12),  // "MailSendSlot"
        QT_MOC_LITERAL(46, 14),  // "SendUrgentMail"
        QT_MOC_LITERAL(61, 17),  // "SendPowerDownMail"
        QT_MOC_LITERAL(79, 9),  // "InitEmail"
        QT_MOC_LITERAL(89, 4),  // "from"
        QT_MOC_LITERAL(94, 4),  // "name"
        QT_MOC_LITERAL(99, 2),  // "to"
        QT_MOC_LITERAL(102, 7),  // "to_name"
        QT_MOC_LITERAL(110, 7),  // "subject"
        QT_MOC_LITERAL(118, 9),  // "SendEmail"
        QT_MOC_LITERAL(128, 3),  // "msg"
        QT_MOC_LITERAL(132, 24),  // "GabageCollectionForEmail"
        QT_MOC_LITERAL(157, 7),  // "Smtp_IM"
        QT_MOC_LITERAL(165, 7)   // "contact"
    },
    "Email_IM",
    "ClearTextEditor_Signal",
    "",
    "MailSendSlot",
    "SendUrgentMail",
    "SendPowerDownMail",
    "InitEmail",
    "from",
    "name",
    "to",
    "to_name",
    "subject",
    "SendEmail",
    "msg",
    "GabageCollectionForEmail",
    "Smtp_IM",
    "contact"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Email_IM[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    2,   64,    2, 0x0a,    3 /* Public */,
       5,    0,   69,    2, 0x0a,    6 /* Public */,
       6,    5,   70,    2, 0x0a,    7 /* Public */,
      12,    1,   81,    2, 0x0a,   13 /* Public */,
      14,    0,   84,    2, 0x0a,   15 /* Public */,
      15,    4,   85,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,    9,   10,   11,
    QMetaType::Bool, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   13,    8,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject Email_IM::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Email_IM.offsetsAndSizes,
    qt_meta_data_Email_IM,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Email_IM_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Email_IM, std::true_type>,
        // method 'ClearTextEditor_Signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'MailSendSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'SendUrgentMail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SendPowerDownMail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'InitEmail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'SendEmail'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'GabageCollectionForEmail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Smtp_IM'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Email_IM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Email_IM *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ClearTextEditor_Signal(); break;
        case 1: _t->MailSendSlot(); break;
        case 2: _t->SendUrgentMail((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->SendPowerDownMail(); break;
        case 4: _t->InitEmail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 5: { bool _r = _t->SendEmail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->GabageCollectionForEmail(); break;
        case 7: { bool _r = _t->Smtp_IM((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Email_IM::*)();
            if (_t _q_method = &Email_IM::ClearTextEditor_Signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Email_IM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Email_IM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Email_IM.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Email_IM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Email_IM::ClearTextEditor_Signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
