/****************************************************************************
** Meta object code from reading C++ file 'monitorthread_im.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Server_Monitoring_Platform/monitorthread_im.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitorthread_im.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MonitorThread_IM_t {
    uint offsetsAndSizes[26];
    char stringdata0[17];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[23];
    char stringdata5[23];
    char stringdata6[22];
    char stringdata7[6];
    char stringdata8[3];
    char stringdata9[21];
    char stringdata10[29];
    char stringdata11[20];
    char stringdata12[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MonitorThread_IM_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MonitorThread_IM_t qt_meta_stringdata_MonitorThread_IM = {
    {
        QT_MOC_LITERAL(0, 16),  // "MonitorThread_IM"
        QT_MOC_LITERAL(17, 11),  // "test_signal"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 10),  // "RiskSignal"
        QT_MOC_LITERAL(41, 22),  // "RiskDisplayMode_Signal"
        QT_MOC_LITERAL(64, 22),  // "SafeDisplayMode_Signal"
        QT_MOC_LITERAL(87, 21),  // "SendUrgentMail_Signal"
        QT_MOC_LITERAL(109, 5),  // "level"
        QT_MOC_LITERAL(115, 2),  // "id"
        QT_MOC_LITERAL(118, 20),  // "PowerDownMail_Signal"
        QT_MOC_LITERAL(139, 28),  // "RecvDataFromServerAndDisplay"
        QT_MOC_LITERAL(168, 19),  // "ConnectedSuccessful"
        QT_MOC_LITERAL(188, 22)   // "LossConnectionAndRetry"
    },
    "MonitorThread_IM",
    "test_signal",
    "",
    "RiskSignal",
    "RiskDisplayMode_Signal",
    "SafeDisplayMode_Signal",
    "SendUrgentMail_Signal",
    "level",
    "id",
    "PowerDownMail_Signal",
    "RecvDataFromServerAndDisplay",
    "ConnectedSuccessful",
    "LossConnectionAndRetry"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MonitorThread_IM[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       3,    0,   71,    2, 0x06,    3 /* Public */,
       4,    1,   72,    2, 0x06,    4 /* Public */,
       5,    1,   75,    2, 0x06,    6 /* Public */,
       6,    2,   78,    2, 0x06,    8 /* Public */,
       9,    0,   83,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   84,    2, 0x08,   12 /* Private */,
      11,    0,   85,    2, 0x08,   13 /* Private */,
      12,    0,   86,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MonitorThread_IM::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_MonitorThread_IM.offsetsAndSizes,
    qt_meta_data_MonitorThread_IM,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MonitorThread_IM_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MonitorThread_IM, std::true_type>,
        // method 'test_signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'RiskSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RiskDisplayMode_Signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SafeDisplayMode_Signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SendUrgentMail_Signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'PowerDownMail_Signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RecvDataFromServerAndDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ConnectedSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'LossConnectionAndRetry'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MonitorThread_IM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonitorThread_IM *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->test_signal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->RiskSignal(); break;
        case 2: _t->RiskDisplayMode_Signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->SafeDisplayMode_Signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->SendUrgentMail_Signal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->PowerDownMail_Signal(); break;
        case 6: _t->RecvDataFromServerAndDisplay(); break;
        case 7: _t->ConnectedSuccessful(); break;
        case 8: _t->LossConnectionAndRetry(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MonitorThread_IM::*)(QString );
            if (_t _q_method = &MonitorThread_IM::test_signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MonitorThread_IM::*)();
            if (_t _q_method = &MonitorThread_IM::RiskSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MonitorThread_IM::*)(int );
            if (_t _q_method = &MonitorThread_IM::RiskDisplayMode_Signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MonitorThread_IM::*)(int );
            if (_t _q_method = &MonitorThread_IM::SafeDisplayMode_Signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MonitorThread_IM::*)(int , int );
            if (_t _q_method = &MonitorThread_IM::SendUrgentMail_Signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MonitorThread_IM::*)();
            if (_t _q_method = &MonitorThread_IM::PowerDownMail_Signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *MonitorThread_IM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonitorThread_IM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonitorThread_IM.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MonitorThread_IM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MonitorThread_IM::test_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MonitorThread_IM::RiskSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MonitorThread_IM::RiskDisplayMode_Signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MonitorThread_IM::SafeDisplayMode_Signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MonitorThread_IM::SendUrgentMail_Signal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MonitorThread_IM::PowerDownMail_Signal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
