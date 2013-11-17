#ifndef BASE_MENU_H
#define BASE_MENU_H

#include <QRectF>
#include <QMap>
#include <QVector>
#include <QRgb>

#include "game_state.h"
#include "menu_button.h"
#include "cursor.h"

/************************************************
*	Class										*
*************************************************/

//! BaseMenu Class.
/*!
	The base class to all the menus.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class BaseMenu : public GameState
{
	Q_OBJECT
private:
	/************************************************
	*	Attributes									*
	*************************************************/

	/*!
		The controller cursor on the screen.
		\sa Cursor
	*/
	Cursor cursor;

	//! Color table used to set the camera image black and white.
	QVector<QRgb> color_table;

	/************************************************
	*	Methods										*
	*************************************************/

protected:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Map with all the buttons
	QMap<QString, MenuButton*> buttons;

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
		Simple constructor to the BaseMenu.
		\param 	name 	Name of the menu
	*/
	BaseMenu(QString name);

	/*! 
		Check if the cursor is over the buttons.
	*/
	virtual void update();

	/*!
		Paint the screen black and white.
		\sa GameState::paint_screen_camera()
	*/
	void paint_screen_camera(QWidget* screen, QImage* camera_image);

	/*! 
		Paint the buttons on the screen.
		\sa GameState::paint_screen()
	*/
	void paint_screen(QWidget *screen);

	/*!
		Updates the cursor position.
		\sa GameState::position()
	*/
	void position(int id, int x, int y, int z);

	/*!
		\sa GameState::move_button()
	*/
	virtual void move_button(int id);

	/*!
		\sa GameState::square_button()
	*/
	virtual void square_button(int id);

	/*!
		\sa GameState::triangle_button()
	*/
	virtual void triangle_button(int id);

	/*!
		\sa GameState::circle_button()
	*/
	virtual void circle_button(int id);

	/*!
		\sa GameState::cross_button()
	*/
	virtual void cross_button(int id);

	/*!
		\sa GameState::select_button()
	*/
	virtual void select_button(int id);

	/*!
		\sa GameState::start_button()
	*/
	virtual void start_button(int id);

	/*!
		\sa GameState::trigger_pressed()
	*/
	virtual void trigger_pressed(int id, qreal trigger);
};

#endif