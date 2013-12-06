/****************************************************************************
** Meta object code from reading C++ file 'game_state.h'
**
** Created: Thu Dec 5 21:14:46 2013
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
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      42,   10,   10,   10, 0x05,
      67,   56,   10,   10, 0x05,
     129,  110,   10,   10, 0x05,
     191,  181,   10,   10, 0x05,
     239,  232,   10,   10, 0x05,
     267,  261,   10,   10, 0x05,
     290,  232,   10,   10, 0x05,
     326,  316,   10,   10, 0x05,
     345,   10,   10,   10, 0x05,
     358,   10,   10,   10, 0x05,
     371,   10,   10,   10, 0x05,
     386,   10,   10,   10, 0x05,
     398,   10,   10,   10, 0x05,
     413,   10,   10,   10, 0x05,
     429,   10,   10,   10, 0x05,
     443,   10,   10,   10, 0x05,
     469,  462,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     496,   10,   10,   10, 0x0a,
     528,  519,   10,   10, 0x0a,
     557,  554,   10,   10, 0x0a,
     579,  554,   10,   10, 0x0a,
     603,  554,   10,   10, 0x0a,
     629,  554,   10,   10, 0x0a,
     653,  554,   10,   10, 0x0a,
     676,  554,   10,   10, 0x0a,
     700,  554,   10,   10, 0x0a,
     723,  554,   10,   10, 0x0a,
     748,  554,   10,   10, 0x0a,
     775,  554,   10,   10, 0x0a,
     804,  554,   10,   10, 0x0a,
     831,  554,   10,   10, 0x0a,
     857,  554,   10,   10, 0x0a,
     884,  554,   10,   10, 0x0a,
     910,  554,   10,   10, 0x0a,
     930,  554,   10,   10, 0x0a,
     952,  554,   10,   10, 0x0a,
     976,  554,   10,   10, 0x0a,
     998,  554,   10,   10, 0x0a,
    1019,  554,   10,   10, 0x0a,
    1041,  554,   10,   10, 0x0a,
    1073, 1062,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameState[] = {
    "GameState\0\0state\0change_state(GameState*)\0"
    "exit_signal()\0difficulty\0"
    "change_difficulty(GameManager::Difficulty)\0"
    "handicap_mode_type\0"
    "change_handicap_mode(GameManager::HandicapModeType)\0"
    "game_size\0change_game_size(GameManager::Game_Size)\0"
    "change\0set_change_color(int)\0r,g,b\0"
    "set_color(int,int,int)\0set_change_vibration(int)\0"
    "intensity\0set_vibration(int)\0play_music()\0"
    "stop_music()\0repeat_music()\0play_beep()\0"
    "play_winning()\0play_cheering()\0"
    "play_damage()\0play_time_attack()\0"
    "volume\0change_sound_volume(qreal)\0"
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
        case 5: _t->set_change_color((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->set_color((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->set_change_vibration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->set_vibration((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->play_music(); break;
        case 10: _t->stop_music(); break;
        case 11: _t->repeat_music(); break;
        case 12: _t->play_beep(); break;
        case 13: _t->play_winning(); break;
        case 14: _t->play_cheering(); break;
        case 15: _t->play_damage(); break;
        case 16: _t->play_time_attack(); break;
        case 17: _t->change_sound_volume((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 18: _t->calibration_finished(); break;
        case 19: _t->position((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 20: _t->move_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->square_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->triangle_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->circle_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->cross_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->select_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->start_button_down((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->move_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->square_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->triangle_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->circle_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->cross_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->select_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->start_button_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->move_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->square_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->triangle_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->circle_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->cross_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->select_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->start_button_up((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->trigger_pressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
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
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
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

// SIGNAL 5
void GameState::set_change_color(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GameState::set_color(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GameState::set_change_vibration(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GameState::set_vibration(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GameState::play_music()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void GameState::stop_music()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void GameState::repeat_music()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void GameState::play_beep()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void GameState::play_winning()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void GameState::play_cheering()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void GameState::play_damage()
{
    QMetaObject::activate(this, &staticMetaObject, 15, 0);
}

// SIGNAL 16
void GameState::play_time_attack()
{
    QMetaObject::activate(this, &staticMetaObject, 16, 0);
}

// SIGNAL 17
void GameState::change_sound_volume(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}
QT_END_MOC_NAMESPACE
