/****************************************************************************
** Meta object code from reading C++ file 'paintview.h'
**
** Created: Fri Nov 8 01:12:56 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "paintview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PaintView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   11,   10,   10, 0x0a,
      73,   10,   10,   10, 0x0a,
      88,   10,   10,   10, 0x0a,
     113,  104,   10,   10, 0x0a,
     145,  139,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PaintView[] = {
    "PaintView\0\0id,scale,x,y,trigger\0"
    "newposition(int,qreal,qreal,qreal,qreal)\0"
    "backup_frame()\0restore_frame()\0id,r,g,b\0"
    "newcolor(int,int,int,int)\0image\0"
    "newimage(void*)\0"
};

void PaintView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PaintView *_t = static_cast<PaintView *>(_o);
        switch (_id) {
        case 0: _t->newposition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 1: _t->backup_frame(); break;
        case 2: _t->restore_frame(); break;
        case 3: _t->newcolor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->newimage((*reinterpret_cast< void*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PaintView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PaintView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PaintView,
      qt_meta_data_PaintView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PaintView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PaintView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PaintView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PaintView))
        return static_cast<void*>(const_cast< PaintView*>(this));
    return QWidget::qt_metacast(_clname);
}

int PaintView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
