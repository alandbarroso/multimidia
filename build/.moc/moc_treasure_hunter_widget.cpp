/****************************************************************************
** Meta object code from reading C++ file 'treasure_hunter_widget.h'
**
** Created: Sat Nov 16 16:06:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/treasure_hunter_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'treasure_hunter_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TreasureHunterWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TreasureHunterWidget[] = {
    "TreasureHunterWidget\0\0update_screen()\0"
};

void TreasureHunterWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TreasureHunterWidget *_t = static_cast<TreasureHunterWidget *>(_o);
        switch (_id) {
        case 0: _t->update_screen(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TreasureHunterWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TreasureHunterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TreasureHunterWidget,
      qt_meta_data_TreasureHunterWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TreasureHunterWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TreasureHunterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TreasureHunterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TreasureHunterWidget))
        return static_cast<void*>(const_cast< TreasureHunterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TreasureHunterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE