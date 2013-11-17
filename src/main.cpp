#include <QtGui>

#include "treasure_hunter_widget.h"
#include "psmove_controller_thread.h"
#include "game_manager.h"

//! Main function
/*!
    Initiates all the objects and start the game
*/
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    PSMoveControllerThread controller;
    controller.start();

    int width, height;
    controller.get_size(width, height);

    TreasureHunterWidget view(NULL, width, height, &controller);
    
    QObject::connect(&controller, SIGNAL(update_screen()),
            &view, SLOT(update_screen()));

    view.show();

    return app.exec();
}

