#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <QImage>
#include <QRectF>
#include <QString>

#include "cursor.h"

/************************************************
*	Class										*
*************************************************/

//! MenuButton Class.
/*!
	Menu button representation.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class MenuButton
{
private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Image of the not-selected button.
	QImage normal;

	//! Image of the selected button.
	QImage selected;

	//! Rectangle with the original image size.
	QRectF source_rect;

	//! Hit box and target rectangle image size.
	QRectF hit_box;

	//! True if the button is hovered.
	int hovered;

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
		Basic constructor, initalizes the button with the base button image.
	*/
	MenuButton();

	/*!
		Initializes the button with the given name image.
	*/
	MenuButton(QString name);

	/*!
		Set the center of the cursor.
		\param 	x 	X coordinate of the cursor.
		\param 	y 	Y coordinate of the cursor.
	*/
	void set_center(int x, int y);

	/*!
		Verify if the button is being hovered by the cursor.
		\param 	cursor 	The cursor to be checked.
	*/
	void set_hovered(Cursor cursor);

	/*!
		\return The value of hovered.
	*/
	int get_hovered();

	/*!
		\return The hit box rectangle of the button.
	*/
	QRectF get_rect();

	/*!
		\return The original rectangle with size of the button.
	*/
	QRectF get_source_rect();

	/*!
		\return Button image: if hovered, return select, else normal.
	*/
	QImage get_button();
};

#endif