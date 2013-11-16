/****************************************************************************
** Meta object code from reading C++ file 'game_state.h'
**
** Created: Sat Nov 16 17:29:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/game_state.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_state.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameState[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      42,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   56,   10,   10, 0x0a,
      94,   91,   10,   10, 0x0a,
     111,   91,   10,   10, 0x0a,
     130,   91,   10,   10, 0x0a,
     151,   91,   10,   10, 0x0a,
     170,   91,   10,   10, 0x0a,
     188,   91,   10,   10, 0x0a,
     207,   91,   10,   10, 0x0a,
     236,  225,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameState[] = {
    "GameState\0\0state\0change_state(GameState*)\0"
    "exit_signal()\0id,x,y,z\0position(int,int,int,int)\0"
    "id\0move_button(int)\0square_button(int)\0"
    "triangle_button(int)\0circle_button(int)\0"
    "cross_button(int)\0select_button(int)\0"
    "start_button(int)\0id,trigger\0"
    "trigger_pressed(int,qreal)\0"
};

void GameState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameState *_t = static_cast<GameState *>(_o);
        switch (_id) {
        case 0: _t->change_state((*reinterpret_cast< GameState*(*)>(_a[1]))); break;
        case 1: _t->exit_signal(); break;
        case 2: _t->position((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->move_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->square_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->triangle_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->circle_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->cross_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->select_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->start_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->trigger_pressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameState::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameState,
      qt_meta_data_GameState, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameState::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameState))
        return static_cast<void*>(const_cast< GameState*>(this));
    return QObject::qt_metacast(_clname);
}

int GameState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GameState::change_state(GameState * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameState::exit_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
