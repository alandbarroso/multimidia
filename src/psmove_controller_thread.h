#ifndef PSMOVE_CONTROLLER_THREAD_H
#define PSMOVE_CONTROLLER_THREAD_H

#include <QApplication>
#include <QThread>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "psmove.h"
#include "psmove_tracker.h"

class PSMoveControllerThread : public QThread
{
Q_OBJECT

signals:
    // Position changed
    void position(int id, int x, int y, int z);

    // Button signals
    void move_button(int id);
    void square_button(int id);
    void triangle_button(int id);
    void circle_button(int id);
    void cross_button(int id);
    void select_button(int id);
    void start_button(int id);

    // Trigger
    void trigger_pressed(int id, qreal trigger);

    // The camera image
    void image(void* image);

    void update_screen();

private:
    PSMoveTracker *tracker;

    int quit;

public:
    PSMoveControllerThread();

    void get_size(int &width, int &height);

    void run();

public slots:
    // The exit signal
    void exit_signal();
};

#endif