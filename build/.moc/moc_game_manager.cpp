/****************************************************************************
** Meta object code from reading C++ file 'game_manager.h'
**
** Created: Sat Nov 16 17:29:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/game_manager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x0a,
      50,   44,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameManager[] = {
    "GameManager\0\0state\0change_state(GameState*)\0"
    "image\0image(void*)\0"
};

void GameManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameManager *_t = static_cast<GameManager *>(_o);
        switch (_id) {
        case 0: _t->change_state((*reinterpret_cast< GameState*(*)>(_a[1]))); break;
        case 1: _t->image((*reinterpret_cast< void*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameManager,
      qt_meta_data_GameManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameManager))
        return static_cast<void*>(const_cast< GameManager*>(this));
    return QObject::qt_metacast(_clname);
}

int GameManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
