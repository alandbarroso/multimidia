#ifndef CONGRATULATIONS_H
#define CONGRATULATIONS_H

#include "game_state.h"

/************************************************
*	Class										*
*************************************************/

//! Congratulations Class.
/*!
	The congratulations screen, showing the number of points the player got.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class Congratulations : public GameState
{
	Q_OBJECT

private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! The congratulations text
	QImage congratulations;

	//! Rectangle with the orignal size of the message
	QRectF source_rect;

	//! Rectangle with the target size and position of the message
	QRectF target_rect;

	//! Color table used to set the camera image black and white.
	QVector<QRgb> color_table;

	//! The number of points to be shown
	int points;

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
	Congratulations(int points);

	/*!
		Initial configuration.
	*/
	void init();

	/*!
		Prints the distance from the screen.
	*/
	void update();

	/*!
		Paints the camera image.
	*/
	void paint_screen_camera(QWidget* screen, QImage* camera_image);

	/*!
		Paints nothing
	*/
	void paint_screen(QWidget* screen);

	/*! 

	*/
	void move_button_up(int id);
};

#endif