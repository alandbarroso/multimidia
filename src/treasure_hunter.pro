
TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

SOURCES += main.cpp

SOURCES += paintview.cpp
HEADERS += paintview.h

SOURCES += psmove_controller_thread.cpp
HEADERS += psmove_controller_thread.h

SOURCES += menu_button.cpp
HEADERS += menu_button.h

SOURCES += main_menu.cpp
HEADERS += main_menu.h

SOURCES += game_state.cpp
HEADERS += game_state.h

SOURCES += game_manager.cpp
HEADERS += game_manager.h

DEPENDPATH += psmove_includes
INCLUDEPATH += psmove_includes

LIBS += -lpsmoveapi -lpsmoveapi_tracker

DESTDIR = ../build