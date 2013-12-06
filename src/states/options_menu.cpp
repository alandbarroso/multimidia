#include <stdio.h>

#include "options_menu.h"

OptionsMenu::OptionsMenu()
	: BaseMenu(GameManager::OPTIONS_MENU),
	easy_button(),
	medium_button(),
	hard_button(),
	normal_option_button(),
	handicap_option_button(),
	size_2m_button(),
	size_3m_button(),
	size_4m_button()

{
	int width = game_manager->get_width(); 
	int height = game_manager->get_height();

	qreal step = 0.15;
	qreal first_button = 0.4;

	easy_button.set_center(width/2, (first_button + 0*step)*height);
	medium_button.set_center(width/2, (first_button + 0*step)*height);
	hard_button.set_center(width/2, (first_button + 0*step)*height);

	normal_option_button.set_center(width/2, (first_button + 1*step)*height);
	handicap_option_button.set_center(width/2, (first_button + 1*step)*height);

	size_2m_button.set_center(width/2, (first_button + 2*step)*height);
	size_3m_button.set_center(width/2, (first_button + 2*step)*height);
	size_4m_button.set_center(width/2, (first_button + 2*step)*height);

	difficulty_buttons[GameManager::EASY] = &easy_button;
	difficulty_buttons[GameManager::MEDIUM] = &medium_button;
	difficulty_buttons[GameManager::HARD] = &hard_button;

	handicap_buttons[GameManager::NO_HANDICAP] = &normal_option_button;
	handicap_buttons[GameManager::HANDICAPED] = &handicap_option_button;

	size_buttons[GameManager::MODE_2M] = &size_2m_button;
	size_buttons[GameManager::MODE_3M] = &size_3m_button;
	size_buttons[GameManager::MODE_4M] = &size_4m_button;

	buttons["difficulty_buttons"] = difficulty_buttons[game_manager->get_game_difficulty()];
	buttons["handicap_buttons"] = handicap_buttons[game_manager->get_handicap_mode_type()];
	buttons["size_buttons"] = size_buttons[game_manager->get_game_size()];

	printf("Option menu initiated!\n");
}

void OptionsMenu::update()
{
	buttons["difficulty_buttons"] = difficulty_buttons[game_manager->get_game_difficulty()];
	buttons["handicap_buttons"] = handicap_buttons[game_manager->get_handicap_mode_type()];
	buttons["size_buttons"] = size_buttons[game_manager->get_game_size()];	

	BaseMenu::update(); // Calls super function
}

void OptionsMenu::move_button_up(int id)
{
	if(buttons["difficulty_buttons"]->get_hovered())
	{
		GameManager::Difficulty difficulty;

		difficulty = get_next_difficulty(game_manager->get_game_difficulty());

		printf("Difficulty changed: %d\n", difficulty);

		emit change_difficulty(difficulty);

		return;
	}
	else if(buttons["handicap_buttons"]->get_hovered())
	{
		GameManager::HandicapModeType handicap_mode;

		handicap_mode = get_next_handicap_mode(game_manager->get_handicap_mode_type());

		printf("Handicap changed: %d\n", handicap_mode);

		emit change_handicap_mode(handicap_mode);

		return;
	}
	else if(buttons["size_buttons"]->get_hovered())
	{
		GameManager::Game_Size game_size;

		game_size = get_next_game_size(game_manager->get_game_size());

		printf("Size changed: %d\n", game_size);

		emit change_game_size(game_size);

		return;
	}
}

GameManager::Difficulty OptionsMenu::get_next_difficulty(GameManager::Difficulty difficulty)
{
	switch(difficulty)
	{
		case GameManager::EASY:
			return GameManager::MEDIUM;
			break;
		case GameManager::MEDIUM:
			return GameManager::HARD;
			break;
		case GameManager::HARD:
			return GameManager::EASY;
			break;
	}
}

GameManager::HandicapModeType OptionsMenu::get_next_handicap_mode(GameManager::HandicapModeType handicap_mode)
{
	switch(handicap_mode)
	{
		case GameManager::NO_HANDICAP:
			return GameManager::HANDICAPED;
			break;
		case GameManager::HANDICAPED:
			return GameManager::NO_HANDICAP;
			break;
	}
}

GameManager::Game_Size OptionsMenu::get_next_game_size(GameManager::Game_Size game_size)
{
	switch(game_size)
	{
		case GameManager::MODE_2M:
			return GameManager::MODE_3M;
			break;
		case GameManager::MODE_3M:
			return GameManager::MODE_4M;
			break;
		case GameManager::MODE_4M:
			return GameManager::MODE_2M;
			break;
	}
}