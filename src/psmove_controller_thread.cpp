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

    int quit = 0;

    for (i=0; i<count; i++) {
        while (psmove_tracker_enable(tracker, moves[i])
                != Tracker_CALIBRATED) {
            // Wait until calibration is done
        }
    }

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
                    emit backup_frame();

                    emit select_button(i);
                }

                if (psmove_get_buttons(move) & Btn_START) {
                    emit restore_frame();

                    emit start_button(i);
                }

                if (psmove_get_buttons(move) & Btn_MOVE) {
                    psmove_set_leds(move, 255, 255, 255);
                    psmove_update_leds(move);
                    emit newcolor(i, 255, 255, 255);

                    emit move_button(i);
                }

                if (psmove_get_buttons(move) & Btn_CROSS) {
                    psmove_set_leds(move, 0, 0, 255);
                    psmove_update_leds(move);
                    emit newcolor(i, 0, 0, 255);

                    emit cross_button(i);
                }

                if (psmove_get_buttons(move) & Btn_SQUARE) {
                    psmove_set_leds(move, 255, 255, 0);
                    psmove_update_leds(move);
                    emit newcolor(i, 255, 255, 0);

                    emit square_button(i);
                }

                if (psmove_get_buttons(move) & Btn_TRIANGLE) {
                    psmove_set_leds(move, 0, 255, 0);
                    psmove_update_leds(move);
                    emit newcolor(i, 0, 255, 0);

                    emit triangle_button(i);
                }

                if (psmove_get_buttons(move) & Btn_CIRCLE) {
                    psmove_set_leds(move, 255, 0, 0);
                    psmove_update_leds(move);
                    emit newcolor(i, 255, 0, 0);

                    emit circle_button(i);
                }

                float x, y, radius;
                psmove_tracker_get_position(tracker, move, &x, &y, &radius);
                emit newposition(i, radius, x, y,
                        (qreal)psmove_get_trigger(move) / 255.);
            }
        } while (again);

        psmove_tracker_update_image(tracker);
        psmove_tracker_update(tracker, NULL);
        emit newimage(psmove_tracker_get_frame(tracker));
    }

    psmove_tracker_free(tracker);

    for (i=0; i<count; i++) {
        psmove_disconnect(moves[i]);
    }

    QApplication::quit();
}