/****************************************************************************
** Meta object code from reading C++ file 'browser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../browser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "adjustLocation"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "changeLocation"
QT_MOC_LITERAL(4, 42, 15), // "changeLocation2"
QT_MOC_LITERAL(5, 58, 11), // "adjustTitle"
QT_MOC_LITERAL(6, 70, 11), // "setProgress"
QT_MOC_LITERAL(7, 82, 1), // "p"
QT_MOC_LITERAL(8, 84, 13), // "finishLoading"
QT_MOC_LITERAL(9, 98, 10), // "viewSource"
QT_MOC_LITERAL(10, 109, 17), // "highlightAllLinks"
QT_MOC_LITERAL(11, 127, 12), // "rotateImages"
QT_MOC_LITERAL(12, 140, 6), // "invert"
QT_MOC_LITERAL(13, 147, 15), // "removeGifImages"
QT_MOC_LITERAL(14, 163, 18), // "removeInlineFrames"
QT_MOC_LITERAL(15, 182, 20), // "removeObjectElements"
QT_MOC_LITERAL(16, 203, 22), // "removeEmbeddedElements"
QT_MOC_LITERAL(17, 226, 7), // "giftPOP"
QT_MOC_LITERAL(18, 234, 12), // "createWindow"
QT_MOC_LITERAL(19, 247, 14) // "addMarkWindowx"

    },
    "MainWindow\0adjustLocation\0\0changeLocation\0"
    "changeLocation2\0adjustTitle\0setProgress\0"
    "p\0finishLoading\0viewSource\0highlightAllLinks\0"
    "rotateImages\0invert\0removeGifImages\0"
    "removeInlineFrames\0removeObjectElements\0"
    "removeEmbeddedElements\0giftPOP\0"
    "createWindow\0addMarkWindowx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x09 /* Protected */,
       3,    0,   95,    2, 0x09 /* Protected */,
       4,    0,   96,    2, 0x09 /* Protected */,
       5,    0,   97,    2, 0x09 /* Protected */,
       6,    1,   98,    2, 0x09 /* Protected */,
       8,    1,  101,    2, 0x09 /* Protected */,
       9,    0,  104,    2, 0x09 /* Protected */,
      10,    0,  105,    2, 0x09 /* Protected */,
      11,    1,  106,    2, 0x09 /* Protected */,
      13,    0,  109,    2, 0x09 /* Protected */,
      14,    0,  110,    2, 0x09 /* Protected */,
      15,    0,  111,    2, 0x09 /* Protected */,
      16,    0,  112,    2, 0x09 /* Protected */,
      17,    0,  113,    2, 0x09 /* Protected */,
      18,    0,  114,    2, 0x09 /* Protected */,
      19,    0,  115,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->adjustLocation(); break;
        case 1: _t->changeLocation(); break;
        case 2: _t->changeLocation2(); break;
        case 3: _t->adjustTitle(); break;
        case 4: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->finishLoading((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->viewSource(); break;
        case 7: _t->highlightAllLinks(); break;
        case 8: _t->rotateImages((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->removeGifImages(); break;
        case 10: _t->removeInlineFrames(); break;
        case 11: _t->removeObjectElements(); break;
        case 12: _t->removeEmbeddedElements(); break;
        case 13: _t->giftPOP(); break;
        case 14: _t->createWindow(); break;
        case 15: _t->addMarkWindowx(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
