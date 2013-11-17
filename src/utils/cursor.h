#ifndef CURSOR_H
#define CURSOR_H

#include <QImage>
#include <QRectF>
#include <QString>

#include "game_manager.h"

/************************************************
*	Class										*
*************************************************/

//! Cursor Class.
/*!
	Represents the player cursor.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class Cursor
{
private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Cursor image
	QImage cursor;

	//! Rectangle with the original image size.
	QRectF source_rect;

	//! Hit box and target rectangle image size.
	QRectF hit_box;

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
		Basic constructor, initalizes the cursor image.
	*/
	Cursor();

	/*!
		Set the center of the cursor.
		\param 	x 	X coordinate of the cursor.
		\param 	y 	Y coordinate of the cursor.
	*/
	void set_center(int x, int y);

	/*!
		\return The hit box rectangle of the cursor.
	*/
	QRectF get_rect();

	/*!
		\return The original rectangle with size of the cursor.
	*/
	QRectF get_source_rect();

	/*!
		\return Cursor image.
	*/
	QImage get_cursor();
};

#endif