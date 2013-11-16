/****************************************************************************
** Meta object code from reading C++ file 'single_player_menu.h'
**
** Created: Sat Nov 16 16:06:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/single_player_menu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'single_player_menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SinglePlayerMenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   18,   17,   17, 0x0a,
      56,   53,   17,   17, 0x0a,
      73,   53,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SinglePlayerMenu[] = {
    "SinglePlayerMenu\0\0id,x,y,z\0"
    "position(int,int,int,int)\0id\0"
    "move_button(int)\0circle_button(int)\0"
};

void SinglePlayerMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SinglePlayerMenu *_t = static_cast<SinglePlayerMenu *>(_o);
        switch (_id) {
        case 0: _t->position((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->move_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->circle_button((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SinglePlayerMenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SinglePlayerMenu::staticMetaObject = {
    { &GameState::staticMetaObject, qt_meta_stringdata_SinglePlayerMenu,
      qt_meta_data_SinglePlayerMenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SinglePlayerMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SinglePlayerMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SinglePlayerMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SinglePlayerMenu))
        return static_cast<void*>(const_cast< SinglePlayerMenu*>(this));
    return GameState::qt_metacast(_clname);
}

int SinglePlayerMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GameState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
