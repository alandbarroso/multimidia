/****************************************************************************
** Meta object code from reading C++ file 'psmove_controller_thread.h'
**
** Created: Thu Dec 5 21:14:44 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/psmove_controller_thread.h"
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
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      26,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,
      56,   47,   23,   23, 0x05,
      85,   82,   23,   23, 0x05,
     107,   82,   23,   23, 0x05,
     131,   82,   23,   23, 0x05,
     157,   82,   23,   23, 0x05,
     181,   82,   23,   23, 0x05,
     204,   82,   23,   23, 0x05,
     228,   82,   23,   23, 0x05,
     251,   82,   23,   23, 0x05,
     276,   82,   23,   23, 0x05,
     303,   82,   23,   23, 0x05,
     332,   82,   23,   23, 0x05,
     359,   82,   23,   23, 0x05,
     385,   82,   23,   23, 0x05,
     412,   82,   23,   23, 0x05,
     438,   82,   23,   23, 0x05,
     458,   82,   23,   23, 0x05,
     480,   82,   23,   23, 0x05,
     504,   82,   23,   23, 0x05,
     526,   82,   23,   23, 0x05,
     547,   82,   23,   23, 0x05,
     569,   82,   23,   23, 0x05,
     601,  590,   23,   23, 0x05,
     634,  628,   23,   23, 0x05,
     647,   23,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
     663,   23,   23,   23, 0x0a,
     684,  677,   23,   23, 0x0a,
     712,  706,   23,   23, 0x0a,
     735,  677,   23,   23, 0x0a,
     771,  761,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PSMoveControllerThread[] = {
    "PSMoveControllerThread\0\0calibration_finished()\0"
    "id,x,y,z\0position(int,int,int,int)\0"
    "id\0move_button_down(int)\0"
    "square_button_down(int)\0"
    "triangle_button_down(int)\0"
    "circle_button_down(int)\0cross_button_down(int)\0"
    "select_button_down(int)\0start_button_down(int)\0"
    "move_button_pressed(int)\0"
    "square_button_pressed(int)\0"
    "triangle_button_pressed(int)\0"
    "circle_button_pressed(int)\0"
    "cross_button_pressed(int)\0"
    "select_button_pressed(int)\0"
    "start_button_pressed(int)\0move_button_up(int)\0"
    "square_button_up(int)\0triangle_button_up(int)\0"
    "circle_button_up(int)\0cross_button_up(int)\0"
    "select_button_up(int)\0start_button_up(int)\0"
    "id,trigger\0trigger_pressed(int,qreal)\0"
    "image\0image(void*)\0update_screen()\0"
    "exit_signal()\0change\0set_change_color(int)\0"
    "r,g,b\0set_color(int,int,int)\0"
    "set_change_vibration(int)\0intensity\0"
    "set_vibration(int)\0"
};

void PSMoveControllerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PSMoveControllerThread *_t = static_cast<PSMoveControllerThread *>(_o);
        switch (_id) {
        case 0: _t->calibration_finished(); break;
        case 1: _t->position((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->move_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->square_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->triangle_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->circle_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->cross_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->select_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->start_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->move_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->square_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->triangle_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->circle_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->cross_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->select_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->start_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->move_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->square_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->triangle_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->circle_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->cross_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->select_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->start_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->trigger_pressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 24: _t->image((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 25: _t->update_screen(); break;
        case 26: _t->exit_signal(); break;
        case 27: _t->set_change_color((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->set_color((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 29: _t->set_change_vibration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->set_vibration((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void PSMoveControllerThread::calibration_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PSMoveControllerThread::position(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PSMoveControllerThread::move_button_down(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PSMoveControllerThread::square_button_down(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PSMoveControllerThread::triangle_button_down(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PSMoveControllerThread::circle_button_down(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PSMoveControllerThread::cross_button_down(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PSMoveControllerThread::select_button_down(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PSMoveControllerThread::start_button_down(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PSMoveControllerThread::move_button_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PSMoveControllerThread::square_button_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PSMoveControllerThread::triangle_button_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PSMoveControllerThread::circle_button_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void PSMoveControllerThread::cross_button_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void PSMoveControllerThread::select_button_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void PSMoveControllerThread::start_button_pressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void PSMoveControllerThread::move_button_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void PSMoveControllerThread::square_button_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void PSMoveControllerThread::triangle_button_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void PSMoveControllerThread::circle_button_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void PSMoveControllerThread::cross_button_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void PSMoveControllerThread::select_button_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void PSMoveControllerThread::start_button_up(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void PSMoveControllerThread::trigger_pressed(int _t1, qreal _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void PSMoveControllerThread::image(void * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void PSMoveControllerThread::update_screen()
{
    QMetaObject::activate(this, &staticMetaObject, 25, 0);
}
QT_END_MOC_NAMESPACE
