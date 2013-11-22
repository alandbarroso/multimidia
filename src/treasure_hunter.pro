
TEMPLATE = app

DEPENDPATH += utils
INCLUDEPATH += utils

SOURCES += cursor.cpp
HEADERS += cursor.h

SOURCES += menu_button.cpp
HEADERS += menu_button.h

DEPENDPATH += states
INCLUDEPATH += states

SOURCES += main_menu.cpp
HEADERS += main_menu.h

SOURCES += single_player_menu.cpp
HEADERS += single_player_menu.h

SOURCES += calibration_state.cpp
HEADERS += calibration_state.h

SOURCES += options_menu.cpp
HEADERS += options_menu.h

DEPENDPATH += game_manager
INCLUDEPATH += game_manager

SOURCES += base_menu.cpp
HEADERS += base_menu.h

SOURCES += game_state.cpp
HEADERS += game_state.h

SOURCES += game_manager.cpp
HEADERS += game_manager.h

DEPENDPATH += psmove_includes
INCLUDEPATH += psmove_includes

DEPENDPATH += .
INCLUDEPATH += .

SOURCES += main.cpp

SOURCES += treasure_hunter_widget.cpp
HEADERS += treasure_hunter_widget.h

SOURCES += psmove_controller_thread.cpp
HEADERS += psmove_controller_thread.h

RESOURCES = treasure_hunter.qrc

LIBS += -lpsmoveapi -lpsmoveapi_tracker

DESTDIR = ../build
OBJECTS_DIR = ../build/.obj
MOC_DIR = ../build/.moc
RCC_DIR = ../build/.rcc
UI_DIR = ../build/.ui