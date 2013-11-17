#ifndef CALIBRATION_STATE_H
#define CALIBRATION_STATE_H

#include "game_state.h"

/************************************************
*	Class										*
*************************************************/

//! CalibrationState Class.
/*!
	Initial state. Asks the user to wait while the controller is being calibrated.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class CalibrationState : public GameState
{
	Q_OBJECT

private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Balck screen to fill all the image.
	QImage black_screen;

	//! Calibration text. Asks the user to wait
	QImage calibrating_text;

	//! Rectangle with the orignal size of the message
	QRectF source_rect;

	//! Rectangle with the target size and position of the message
	QRectF target_rect;

	/************************************************
	*	Methods										*
	*************************************************/

public:
	/************************************************
	*	Attributes									*
	*************************************************/

	/************************************************
	*	Methods										*
	*************************************************/

	/*!
		Basic constructor, initiates the images.
	*/
	CalibrationState();

	//! Dummy - does nothing
	void update();

	/*!
		Paints the screen on black.
		\sa GameState::paint_screen_camera()
	*/
	void paint_screen_camera(QWidget* screen, QImage* camera_image);

	/*!
		Paints the calibration message on the screen.
		\sa GameState::paint_screen()
	*/
	void paint_screen(QWidget* screen);

public slots:
	/************************************************
	*	Slots										*
	*************************************************/
	
	/*!
		Change to the MainMenu.
	*/
	void calibration_finished();
};

#endif