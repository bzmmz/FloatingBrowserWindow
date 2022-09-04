/****************************************************************************
** Meta object code from reading C++ file 'InnerBrowser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../HeaderFiles/InnerBrowser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InnerBrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InnerBrowser_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InnerBrowser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InnerBrowser_t qt_meta_stringdata_InnerBrowser = {
    {
QT_MOC_LITERAL(0, 0, 12), // "InnerBrowser"
QT_MOC_LITERAL(1, 13, 21), // "MainWindowCloseSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 14), // "SetWindowTitle"
QT_MOC_LITERAL(4, 51, 5), // "title"
QT_MOC_LITERAL(5, 57, 11), // "IconClicked"
QT_MOC_LITERAL(6, 69, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(7, 103, 6) // "reason"

    },
    "InnerBrowser\0MainWindowCloseSignal\0\0"
    "SetWindowTitle\0title\0IconClicked\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InnerBrowser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   30,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void InnerBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InnerBrowser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MainWindowCloseSignal(); break;
        case 1: _t->SetWindowTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->IconClicked((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InnerBrowser::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InnerBrowser::MainWindowCloseSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InnerBrowser::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_InnerBrowser.data,
    qt_meta_data_InnerBrowser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InnerBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InnerBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InnerBrowser.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InnerBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void InnerBrowser::MainWindowCloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
