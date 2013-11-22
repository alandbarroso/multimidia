/****************************************************************************
** Meta object code from reading C++ file 'game_state.h'
**
** Created: Fri Nov 22 07:20:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/game_manager/game_state.h"
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
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      42,   10,   10,   10, 0x05,
      67,   56,   10,   10, 0x05,
     129,  110,   10,   10, 0x05,
     191,  181,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     232,   10,   10,   10, 0x0a,
     264,  255,   10,   10, 0x0a,
     293,  290,   10,   10, 0x0a,
     315,  290,   10,   10, 0x0a,
     339,  290,   10,   10, 0x0a,
     365,  290,   10,   10, 0x0a,
     389,  290,   10,   10, 0x0a,
     412,  290,   10,   10, 0x0a,
     436,  290,   10,   10, 0x0a,
     459,  290,   10,   10, 0x0a,
     484,  290,   10,   10, 0x0a,
     511,  290,   10,   10, 0x0a,
     540,  290,   10,   10, 0x0a,
     567,  290,   10,   10, 0x0a,
     593,  290,   10,   10, 0x0a,
     620,  290,   10,   10, 0x0a,
     646,  290,   10,   10, 0x0a,
     666,  290,   10,   10, 0x0a,
     688,  290,   10,   10, 0x0a,
     712,  290,   10,   10, 0x0a,
     734,  290,   10,   10, 0x0a,
     755,  290,   10,   10, 0x0a,
     777,  290,   10,   10, 0x0a,
     809,  798,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameState[] = {
    "GameState\0\0state\0change_state(GameState*)\0"
    "exit_signal()\0difficulty\0"
    "change_difficulty(GameManager::Difficulty)\0"
    "handicap_mode_type\0"
    "change_handicap_mode(GameManager::HandicapModeType)\0"
    "game_size\0change_game_size(GameManager::Game_Size)\0"
    "calibration_finished()\0id,x,y,z\0"
    "position(int,int,int,int)\0id\0"
    "move_button_down(int)\0square_button_down(int)\0"
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
};

void GameState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameState *_t = static_cast<GameState *>(_o);
        switch (_id) {
        case 0: _t->change_state((*reinterpret_cast< GameState*(*)>(_a[1]))); break;
        case 1: _t->exit_signal(); break;
        case 2: _t->change_difficulty((*reinterpret_cast< GameManager::Difficulty(*)>(_a[1]))); break;
        case 3: _t->change_handicap_mode((*reinterpret_cast< GameManager::HandicapModeType(*)>(_a[1]))); break;
        case 4: _t->change_game_size((*reinterpret_cast< GameManager::Game_Size(*)>(_a[1]))); break;
        case 5: _t->calibration_finished(); break;
        case 6: _t->position((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: _t->move_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->square_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->triangle_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->circle_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->cross_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->select_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->start_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->move_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->square_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->triangle_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->circle_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->cross_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->select_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->start_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->move_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->square_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->triangle_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->circle_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->cross_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->select_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->start_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->trigger_pressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
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
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
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

// SIGNAL 2
void GameState::change_difficulty(GameManager::Difficulty _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameState::change_handicap_mode(GameManager::HandicapModeType _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameState::change_game_size(GameManager::Game_Size _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
