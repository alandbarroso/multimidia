#ifndef SINGLEPLAYER_MENU_H
#define SINGLEPLAYER_MENU_H

#include <QRectF>
#include <QVector>
#include <QRgb>

#include "base_menu.h"
#include "menu_button.h"
#include "cursor.h"

/************************************************
*	Class										*
*************************************************/

//! SinglePlayerMenu Class.
/*!
	Singleplayer menu. Can choose the game mode.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class SinglePlayerMenu : public BaseMenu
{
	Q_OBJECT
private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Classic mode MenuButton.
	MenuButton classic_mode_button;
	//! Dynamic mode MenuButton.
	MenuButton time_attack_button;

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
	SinglePlayerMenu();

	/*!
		Change the state of the game based on what button was hovered.
	*/
	void move_button_up(int id);
};

#endif