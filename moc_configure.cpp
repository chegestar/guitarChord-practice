/****************************************************************************
** Meta object code from reading C++ file 'configure.h'
**
** Created: Thu Feb 16 22:36:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "configure.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configure.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_configure[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      20,   10,   10,   10, 0x08,
      37,   10,   10,   10, 0x08,
      53,   10,   10,   10, 0x08,
      75,   73,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_configure[] = {
    "configure\0\0reload()\0on_Add_clicked()\0"
    "on_OK_clicked()\0on_Delete_clicked()\0"
    ",\0AddDone(QString,QString)\0"
};

const QMetaObject configure::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_configure,
      qt_meta_data_configure, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &configure::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *configure::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *configure::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_configure))
        return static_cast<void*>(const_cast< configure*>(this));
    return QDialog::qt_metacast(_clname);
}

int configure::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: reload(); break;
        case 1: on_Add_clicked(); break;
        case 2: on_OK_clicked(); break;
        case 3: on_Delete_clicked(); break;
        case 4: AddDone((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void configure::reload()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
