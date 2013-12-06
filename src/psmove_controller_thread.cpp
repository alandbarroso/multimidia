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
    this->quit = 0;

    this->change_color = 0;

    this->move_color.r = 255;
    this->move_color.g = 255;
    this->move_color.b = 255;

	this->tracker = psmove_tracker_new();
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

    /* Indicates if the button was pressed on the last turn */
    int select_move = 0;
    int select_square = 0;
    int select_triangle = 0;
    int select_circle = 0;
    int select_cross = 0;
    int select_pressed = 0;
    int select_start = 0;

    /* Timer to be used when changing colors */
    QTime timer;
    timer.start();

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

    printf("Calibration finished!!\n");
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

                if (psmove_get_buttons(move) & Btn_MOVE) {
                    emit move_button_pressed(i);

                    if(!select_move)
                    {
                        emit move_button_down(i);
                        select_move = 1;
                    }
                }
                else
                {
                    if(select_move)
                    {
                        emit move_button_up(i);
                        select_move = 0;
                    }
                }

                if (psmove_get_buttons(move) & Btn_SQUARE) {
                    emit square_button_pressed(i);

                    if(!select_square)
                    {
                        emit square_button_down(i);
                        select_square = 1;
                    }
                }
                else
                {
                    if(select_square)
                    {
                        emit square_button_up(i);
                        select_square = 0;
                    }
                }

                if (psmove_get_buttons(move) & Btn_TRIANGLE) {
                    emit triangle_button_pressed(i);

                    if(!select_triangle)
                    {
                        emit triangle_button_down(i);
                        select_triangle = 1;
                    }
                }
                else
                {
                    if(select_triangle)
                    {
                        emit triangle_button_up(i);
                        select_triangle = 0;
                    }
                }

                if (psmove_get_buttons(move) & Btn_CIRCLE) {
                    emit circle_button_pressed(i);

                    if(!select_circle)
                    {
                        emit circle_button_down(i);
                        select_circle = 1;
                    }
                }
                else
                {
                    if(select_circle)
                    {
                        emit circle_button_up(i);
                        select_circle = 0;
                    }
                }

                if (psmove_get_buttons(move) & Btn_CROSS) {
                    emit cross_button_pressed(i);

                    if(!select_cross)
                    {
                        emit cross_button_down(i);
                        select_cross = 1;
                    }
                }
                else
                {
                    if(select_cross)
                    {
                        emit cross_button_up(i);
                        select_cross = 0;
                    }
                }

                if (psmove_get_buttons(move) & Btn_SELECT) {
                    emit select_button_pressed(i);

                    if(!select_pressed)
                    {
                        emit select_button_down(i);
                        select_pressed = 1;
                    }
                }
                else
                {
                    if(select_pressed)
                    {
                        emit select_button_up(i);
                        select_pressed = 0;
                    }
                }

                if (psmove_get_buttons(move) & Btn_START) {
                    emit start_button_pressed(i);

                    if(!select_start)
                    {
                        emit start_button_down(i);
                        select_start = 1;
                    }
                }
                else
                {
                    if(select_start)
                    {
                        emit start_button_up(i);
                        select_start = 0;
                    }
                }

                emit trigger_pressed(i, (qreal) psmove_get_trigger(move));

                if(change_color)
                {
                    psmove_set_leds(move, move_color.r, move_color.g, move_color.b);

                    timer.restart();
                }
                else if(timer.elapsed() > 500)
                {
                    float x, y, z, radius;
                    psmove_tracker_get_position(tracker, move, &x, &y, &radius);
                    z = psmove_tracker_distance_from_radius(tracker, radius);
                    emit position(i, x, y, z);

                    last_position.x = x;
                    last_position.y = y;
                    last_position.z = z;
                }

                if(change_vibration)
                {
                    psmove_set_rumble(move, vibration_intensity);
                }
                else
                {
                    psmove_set_rumble(move, 0);
                }

                psmove_update_leds(move);
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
    this->quit = 1;
}

void PSMoveControllerThread::set_change_color(int change)
{
    this->change_color = change;
}

void PSMoveControllerThread::set_color(int r, int g, int b)
{
    this->move_color.r = r;
    this->move_color.g = g;
    this->move_color.b = b;
}

void PSMoveControllerThread::set_change_vibration(int change)
{
    this->change_vibration = change;
}

void PSMoveControllerThread::set_vibration(int intensity)
{
    this->vibration_intensity = intensity;
}