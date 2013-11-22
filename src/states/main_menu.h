#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QRectF>
#include <QVector>
#include <QRgb>

#include "base_menu.h"
#include "menu_button.h"
#include "cursor.h"

/************************************************
*	Class										*
*************************************************/

//! MainMenu Class.
/*!
	Main menu screen.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class MainMenu : public BaseMenu
{
	Q_OBJECT
private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Singleplayer MenuButton.
	MenuButton singleplayer_button;

	//! Multiplayer MenuButton.
	MenuButton multiplayer_button;

	//! Options MenuButton.
	MenuButton options_button;

	//! Quit MenuButton.
	MenuButton quit_button;

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
		Basic constructor, initalizes the buttons and put then on their places.
	*/
	MainMenu();

	/*!
		Nullifies tha circle button action from the BaseMenu class
	*/
	void circle_button_up(int id);

	/*!
		Change the state of the game based on what button was hovered.
	*/
	void move_button_up(int id);
};

#endif