#ifndef OPTIONS_H
#define OPTIONS_H

#include <QMap>

#include "game_manager.h"
#include "base_menu.h"
#include "menu_button.h"
#include "cursor.h"

/************************************************
*	Class										*
*************************************************/

//! OptionsMenu Class.
/*!
	Options screen. Gives the options to change the game options.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class OptionsMenu : public BaseMenu
{
	Q_OBJECT
private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Easy mode MenuButton.
	MenuButton easy_button;
	//! Medium mode MenuButton. 
	MenuButton medium_button;
	//! Hard mode MenuButton.
	MenuButton hard_button;

	//! Nomal option MenuButton.
	MenuButton normal_option_button;
	//! Handicap option MenuButton.
	MenuButton handicap_option_button;

	//! 2m size option MenuButton.
	MenuButton size_2m_button;
	//! 3m size option MenuButton.
	MenuButton size_3m_button;
	//! 4m size option MenuButton.
	MenuButton size_4m_button;

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
	OptionsMenu();

	/*!
		Change the state of the game based on what button was hovered.
	*/
	void move_button(int id);
};

#endif