#include <QtGui>

#include "paintview.h"
#include "psmove_controller_thread.h"
#include "game_manager.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    PSMoveControllerThread controller;
    controller.start();

    int width, height;
    controller.get_size(width, height);

    PaintView view(NULL, width, height, &controller);

    QObject::connect(&controller, SIGNAL(newposition(int,qreal,qreal,qreal,qreal)),
            &view, SLOT(newposition(int,qreal,qreal,qreal,qreal)));
    QObject::connect(&controller, SIGNAL(newcolor(int,int,int,int)),
            &view, SLOT(newcolor(int,int,int,int)));
    QObject::connect(&controller, SIGNAL(backup_frame()),
            &view, SLOT(backup_frame()));
    QObject::connect(&controller, SIGNAL(restore_frame()),
            &view, SLOT(restore_frame()));
    QObject::connect(&controller, SIGNAL(newimage(void*)),
            &view, SLOT(newimage(void*)));

    view.show();

    return app.exec();
}

