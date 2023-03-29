/****************************************************************************
** Meta object code from reading C++ file 'emailconfigure.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Server_Monitoring_Platform/emailconfigure.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emailconfigure.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_EmailConfigure_t {
    uint offsetsAndSizes[18];
    char stringdata0[15];
    char stringdata1[38];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[38];
    char stringdata5[21];
    char stringdata6[24];
    char stringdata7[24];
    char stringdata8[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_EmailConfigure_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_EmailConfigure_t qt_meta_stringdata_EmailConfigure = {
    {
        QT_MOC_LITERAL(0, 14),  // "EmailConfigure"
        QT_MOC_LITERAL(15, 37),  // "on_CheckBox_EmailOutlook_stat..."
        QT_MOC_LITERAL(53, 0),  // ""
        QT_MOC_LITERAL(54, 4),  // "arg1"
        QT_MOC_LITERAL(59, 37),  // "on_CheckBox_EmailTencent_stat..."
        QT_MOC_LITERAL(97, 20),  // "on_Btn_Enter_clicked"
        QT_MOC_LITERAL(118, 23),  // "on_Btn_AddEmail_clicked"
        QT_MOC_LITERAL(142, 23),  // "on_Btn_DelEmail_clicked"
        QT_MOC_LITERAL(166, 21)   // "on_Btn_Cancel_clicked"
    },
    "EmailConfigure",
    "on_CheckBox_EmailOutlook_stateChanged",
    "",
    "arg1",
    "on_CheckBox_EmailTencent_stateChanged",
    "on_Btn_Enter_clicked",
    "on_Btn_AddEmail_clicked",
    "on_Btn_DelEmail_clicked",
    "on_Btn_Cancel_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_EmailConfigure[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       4,    1,   53,    2, 0x08,    3 /* Private */,
       5,    0,   56,    2, 0x08,    5 /* Private */,
       6,    0,   57,    2, 0x08,    6 /* Private */,
       7,    0,   58,    2, 0x08,    7 /* Private */,
       8,    0,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject EmailConfigure::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_EmailConfigure.offsetsAndSizes,
    qt_meta_data_EmailConfigure,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_EmailConfigure_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EmailConfigure, std::true_type>,
        // method 'on_CheckBox_EmailOutlook_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_CheckBox_EmailTencent_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_Btn_Enter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Btn_AddEmail_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Btn_DelEmail_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Btn_Cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void EmailConfigure::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EmailConfigure *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_CheckBox_EmailOutlook_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_CheckBox_EmailTencent_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_Btn_Enter_clicked(); break;
        case 3: _t->on_Btn_AddEmail_clicked(); break;
        case 4: _t->on_Btn_DelEmail_clicked(); break;
        case 5: _t->on_Btn_Cancel_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *EmailConfigure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmailConfigure::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmailConfigure.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EmailConfigure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
