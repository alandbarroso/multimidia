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

/************************************************
*   Class                                       *
*************************************************/

//! PSMoveTracker Class.
/*!
    Control the singals from PSMove controller.
    \author     Alan Barroso
    \author     Ricardo Dall'Olio
    \author     Eduardo Cominetti
    \version    1.0
    \date       2013
*/
class PSMoveControllerThread : public QThread
{
Q_OBJECT

private:
    /************************************************
    *   Attributes                                  *
    *************************************************/

    //! The tracker.
    PSMoveTracker *tracker;

    //! If true, the application should quit.
    int quit;

    /************************************************
    *   Methods                                     *
    *************************************************/

public:
    /************************************************
    *   Attributes                                  *
    *************************************************/

    /************************************************
    *   Methods                                     *
    *************************************************/

    //! Basic constructor - initiates the tracker.
    PSMoveControllerThread();

    /*!
        Returns the width and the size of the capture camera screen.
        \param  width   Address to the width.
        \param  height  Address to the height.
    */
    void get_size(int &width, int &height);

    /*!
        Inherited method. Check the controller signals.
    */
    void run();

signals:
    /************************************************
    *   Signals                                     *
    *************************************************/

    //! Sent when calibration finishes
    void calibration_finished();

    /*! 
        Sent when the position changes.
        \param  id  Id of the PSMove controller that moved.
        \param  x   X coordinate of the controller.
        \param  y   Y coordinate of the controller.
        \param  z   Z coordinate of the controller.
    */
    void position(int id, int x, int y, int z);

    /*! 
        Sent when the move button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void move_button(int id);

    /*! 
        Sent when the square button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void square_button(int id);

    /*! 
        Sent when the triangle button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void triangle_button(int id);

    /*! 
        Sent when the circle button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void circle_button(int id);

    /*! 
        Sent when the cross button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void cross_button(int id);

    /*! 
        Sent when the select button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void select_button(int id);

    /*! 
        Sent when the start button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void start_button(int id);

    /*! 
        Sent when the trigger is pressed.
        \param  id      Id of the PSMove controller.
        \param trigger  Value of the trigger.
    */
    void trigger_pressed(int id, qreal trigger);

    /*! 
        Send the camera image.
        \param  image   The image received from the controller
    */
    void image(void* image);

    
    /*!
        Send the signal to update the screen.
    */
    void update_screen();

public slots:
    /************************************************
    *   Slots                                       *
    *************************************************/

    //! When received, make the application quit.
    void exit_signal();
};

#endif