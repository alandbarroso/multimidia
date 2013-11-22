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

	//! Mapping the difficulty buttons with the current difficulty.
	QMap<GameManager::Difficulty, MenuButton*> difficulty_buttons;

	//! Mapping the handicap buttons with the current mode.
	QMap<GameManager::HandicapModeType, MenuButton*> handicap_buttons;

	//! Mapping the size buttons with the current mode.
	QMap<GameManager::Game_Size, MenuButton*> size_buttons;

	/************************************************
	*	Methods										*
	*************************************************/

	/*!
		\return 	If easy, returns medium. If medium, returns hard. If hard, returns easy.
	*/
	GameManager::Difficulty get_next_difficulty(GameManager::Difficulty difficulty);

	/*!
		\return 	If no handicap, returns handicap. If handicap, returns no handicap.
	*/
	GameManager::HandicapModeType get_next_handicap_mode(GameManager::HandicapModeType handicap_mode);

	/*!
		\return 	If 2m, returns 3m. If 3m, returns 4m. If 4m, returns 2m
	*/
	GameManager::Game_Size get_next_game_size(GameManager::Game_Size game_size);

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
		Calls the super function and then update the buttons that shall be painted
	*/
	void update();

	/*!
		Change the state of the game based on what button was hovered.
	*/
	void move_button_up(int id);
};

#endif