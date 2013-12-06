#ifndef PSMOVE_CONTROLLER_THREAD_H
#define PSMOVE_CONTROLLER_THREAD_H

#include <QApplication>
#include <QThread>
#include <QTime>

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

    //! If true, the color should change.
    int change_color;

    //! If true, the controller should vibrate.
    int change_vibration;

    //! The color to blink.
    struct color
    {
        int r;
        int g;
        int b;
    } move_color;

    //! The intensio of the vibration
    int vibration_intensity;

    //! Stores the last coordinates of the controller
    struct coordinates
    {
        float x;
        float y;
        float z;
    } last_position;

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

    /***************** Button Down *****************/

    /*! 
        Sent when the move button goes down.
        \param  id  Id of the PSMove controller.
    */
    void move_button_down(int id);

    /*! 
        Sent when the square button goes down.
        \param  id  Id of the PSMove controller.
    */
    void square_button_down(int id);

    /*! 
        Sent when the triangle button goes down.
        \param  id  Id of the PSMove controller.
    */
    void triangle_button_down(int id);

    /*! 
        Sent when the circle button goes down.
        \param  id  Id of the PSMove controller.
    */
    void circle_button_down(int id);

    /*! 
        Sent when the cross button goes down.
        \param  id  Id of the PSMove controller.
    */
    void cross_button_down(int id);

    /*! 
        Sent when the select button goes down.
        \param  id  Id of the PSMove controller.
    */
    void select_button_down(int id);

    /*! 
        Sent when the start button goes down.
        \param  id  Id of the PSMove controller.
    */
    void start_button_down(int id);

    /*************** Button Pressed ***************/

    /*! 
        Sent when the move button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void move_button_pressed(int id);

    /*! 
        Sent when the square button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void square_button_pressed(int id);

    /*! 
        Sent when the triangle button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void triangle_button_pressed(int id);

    /*! 
        Sent when the circle button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void circle_button_pressed(int id);

    /*! 
        Sent when the cross button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void cross_button_pressed(int id);

    /*! 
        Sent when the select button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void select_button_pressed(int id);

    /*! 
        Sent when the start button is pressed.
        \param  id  Id of the PSMove controller.
    */
    void start_button_pressed(int id);

    /***************** Button Up *****************/

    /*! 
        Sent when the move button goes up.
        \param  id  Id of the PSMove controller.
    */
    void move_button_up(int id);

    /*! 
        Sent when the square button goes up.
        \param  id  Id of the PSMove controller.
    */
    void square_button_up(int id);

    /*! 
        Sent when the triangle button goes up.
        \param  id  Id of the PSMove controller.
    */
    void triangle_button_up(int id);

    /*! 
        Sent when the circle button goes up.
        \param  id  Id of the PSMove controller.
    */
    void circle_button_up(int id);

    /*! 
        Sent when the cross button goes up.
        \param  id  Id of the PSMove controller.
    */
    void cross_button_up(int id);

    /*! 
        Sent when the select button goes up.
        \param  id  Id of the PSMove controller.
    */
    void select_button_up(int id);

    /*! 
        Sent when the start button goes up.
        \param  id  Id of the PSMove controller.
    */
    void start_button_up(int id);

    /****************** Trigger ******************/

    /*! 
        Sent when the trigger is pressed.
        \param  id      Id of the PSMove controller.
        \param trigger  Value of the trigger.
    */
    void trigger_pressed(int id, qreal trigger);

    /****************** Image ******************/

    /*! 
        Send the camera image.
        \param  image   The image received from the controller
    */
    void image(void* image);

    /****************** Update ******************/
    
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

    /*!
        When called, set if the tracker should change color
    */
    void set_change_color(int change);

    /*!
        Set the color of that should be used
    */
    void set_color(int r, int g, int b);

    /*!
        When called, set if the tracker should vibrate
    */
    void set_change_vibration(int change);

    /*!
        Set the intension of the vibration
    */
    void set_vibration(int intensity);
};

#endif