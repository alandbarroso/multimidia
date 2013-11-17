#include <QApplication>
#include <QThread>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "psmove_controller_thread.h"

#include "psmove.h"
#include "psmove_tracker.h"

PSMoveControllerThread::PSMoveControllerThread() : QThread() 
{
    quit = 0;

	tracker = psmove_tracker_new();
}

void PSMoveControllerThread::get_size(int &width, int &height) 
{
	psmove_tracker_update_image(tracker);
	psmove_tracker_get_size(tracker, &width, &height);
}

void PSMoveControllerThread::run()
{
    int i;
    int count = psmove_count_connected();

    PSMove **moves = (PSMove**)calloc(count, sizeof(PSMove*));

    for (i=0; i<count; i++) {
        moves[i] = psmove_connect_by_id(i);
        assert(moves[i] != NULL);
    }

    for (i=0; i<count; i++) {
        while (psmove_tracker_enable(tracker, moves[i])
                != Tracker_CALIBRATED) {
            // Wait until calibration is done
        }
    }

    emit calibration_finished();

    while (!quit) {
        int again;

        do {
            again = 0;

            for (i=0; i<count; i++) {
                PSMove *move = moves[i];

                int res = psmove_poll(move);

                if (!res) {
                    continue;
                }

                again++;

                if (psmove_get_buttons(move) & Btn_PS) {
                    quit = 1;
                    break;
                }

                if (psmove_get_buttons(move) & Btn_SELECT) {
                    emit select_button(i);
                }

                if (psmove_get_buttons(move) & Btn_START) {
                    emit start_button(i);
                }

                if (psmove_get_buttons(move) & Btn_MOVE) {
                    emit move_button(i);
                }

                if (psmove_get_buttons(move) & Btn_CROSS) {
                    emit cross_button(i);
                }

                if (psmove_get_buttons(move) & Btn_SQUARE) {
                    emit square_button(i);
                }

                if (psmove_get_buttons(move) & Btn_TRIANGLE) {
                    emit triangle_button(i);
                }

                if (psmove_get_buttons(move) & Btn_CIRCLE) {
                    emit circle_button(i);
                }

                float x, y, radius;
                psmove_tracker_get_position(tracker, move, &x, &y, &radius);
                emit position(i, x, y, 0);
            }
        } while (again);

        psmove_tracker_update_image(tracker);
        psmove_tracker_update(tracker, NULL);
        emit image(psmove_tracker_get_frame(tracker));

        emit update_screen();
    }

    psmove_tracker_free(tracker);

    for (i=0; i<count; i++) {
        psmove_disconnect(moves[i]);
    }

    QApplication::quit();
}

void PSMoveControllerThread::exit_signal()
{
    quit = 1;
}