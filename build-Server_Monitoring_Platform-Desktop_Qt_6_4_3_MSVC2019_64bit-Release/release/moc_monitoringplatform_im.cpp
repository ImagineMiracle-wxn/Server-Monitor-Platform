/****************************************************************************
** Meta object code from reading C++ file 'monitoringplatform_im.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Server_Monitoring_Platform/monitoringplatform_im.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitoringplatform_im.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MonitoringPlatform_IM_t {
    uint offsetsAndSizes[22];
    char stringdata0[22];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[21];
    char stringdata5[21];
    char stringdata6[16];
    char stringdata7[21];
    char stringdata8[34];
    char stringdata9[5];
    char stringdata10[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MonitoringPlatform_IM_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MonitoringPlatform_IM_t qt_meta_stringdata_MonitoringPlatform_IM = {
    {
        QT_MOC_LITERAL(0, 21),  // "MonitoringPlatform_IM"
        QT_MOC_LITERAL(22, 18),  // "EmailSendEn_Signal"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 3),  // "sig"
        QT_MOC_LITERAL(46, 20),  // "RiskDisplayMode_Slot"
        QT_MOC_LITERAL(67, 20),  // "SafeDisplayMode_Slot"
        QT_MOC_LITERAL(88, 15),  // "FlushMainWindow"
        QT_MOC_LITERAL(104, 20),  // "ClearTextEditor_Slot"
        QT_MOC_LITERAL(125, 33),  // "on_CheckBox_Email_En_stateCha..."
        QT_MOC_LITERAL(159, 4),  // "arg1"
        QT_MOC_LITERAL(164, 28)   // "on_CheckBox_Email_En_clicked"
    },
    "MonitoringPlatform_IM",
    "EmailSendEn_Signal",
    "",
    "sig",
    "RiskDisplayMode_Slot",
    "SafeDisplayMode_Slot",
    "FlushMainWindow",
    "ClearTextEditor_Slot",
    "on_CheckBox_Email_En_stateChanged",
    "arg1",
    "on_CheckBox_Email_En_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MonitoringPlatform_IM[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   59,    2, 0x0a,    3 /* Public */,
       5,    1,   62,    2, 0x0a,    5 /* Public */,
       6,    0,   65,    2, 0x0a,    7 /* Public */,
       7,    0,   66,    2, 0x0a,    8 /* Public */,
       8,    1,   67,    2, 0x08,    9 /* Private */,
      10,    0,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MonitoringPlatform_IM::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MonitoringPlatform_IM.offsetsAndSizes,
    qt_meta_data_MonitoringPlatform_IM,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MonitoringPlatform_IM_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MonitoringPlatform_IM, std::true_type>,
        // method 'EmailSendEn_Signal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'RiskDisplayMode_Slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SafeDisplayMode_Slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'FlushMainWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ClearTextEditor_Slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CheckBox_Email_En_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_CheckBox_Email_En_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MonitoringPlatform_IM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonitoringPlatform_IM *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->EmailSendEn_Signal((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->RiskDisplayMode_Slot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->SafeDisplayMode_Slot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->FlushMainWindow(); break;
        case 4: _t->ClearTextEditor_Slot(); break;
        case 5: _t->on_CheckBox_Email_En_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_CheckBox_Email_En_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MonitoringPlatform_IM::*)(bool );
            if (_t _q_method = &MonitoringPlatform_IM::EmailSendEn_Signal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MonitoringPlatform_IM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonitoringPlatform_IM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonitoringPlatform_IM.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MonitoringPlatform_IM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MonitoringPlatform_IM::EmailSendEn_Signal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
