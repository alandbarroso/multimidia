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
        void newposition(int id, qreal scale, qreal x, qreal y, qreal trigger);
        void newcolor(int id, int r, int g, int b);
        void newimage(void *image);
        void backup_frame();
        void restore_frame();

    private:
        PSMoveTracker *tracker;

    public:
        PSMoveControllerThread();

        void get_size(int &width, int &height);

        void run();
};

#endif