/****************************************************************************
** Meta object code from reading C++ file 'psmove_controller_thread.h'
**
** Created: Wed Nov 6 22:25:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "psmove_controller_thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'psmove_controller_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PSMoveControllerThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      45,   24,   23,   23, 0x05,
      95,   86,   23,   23, 0x05,
     127,  121,   23,   23, 0x05,
     143,   23,   23,   23, 0x05,
     158,   23,   23,   23, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PSMoveControllerThread[] = {
    "PSMoveControllerThread\0\0id,scale,x,y,trigger\0"
    "newposition(int,qreal,qreal,qreal,qreal)\0"
    "id,r,g,b\0newcolor(int,int,int,int)\0"
    "image\0newimage(void*)\0backup_frame()\0"
    "restore_frame()\0"
};

void PSMoveControllerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PSMoveControllerThread *_t = static_cast<PSMoveControllerThread *>(_o);
        switch (_id) {
        case 0: _t->newposition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 1: _t->newcolor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->newimage((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 3: _t->backup_frame(); break;
        case 4: _t->restore_frame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PSMoveControllerThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PSMoveControllerThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PSMoveControllerThread,
      qt_meta_data_PSMoveControllerThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PSMoveControllerThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PSMoveControllerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PSMoveControllerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PSMoveControllerThread))
        return static_cast<void*>(const_cast< PSMoveControllerThread*>(this));
    return QThread::qt_metacast(_clname);
}

int PSMoveControllerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PSMoveControllerThread::newposition(int _t1, qreal _t2, qreal _t3, qreal _t4, qreal _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PSMoveControllerThread::newcolor(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PSMoveControllerThread::newimage(void * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PSMoveControllerThread::backup_frame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void PSMoveControllerThread::restore_frame()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
