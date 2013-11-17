#include <stdio.h>

#include "options_menu.h"

OptionsMenu::OptionsMenu()
	: BaseMenu("OptionsMenu"),
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

	difficulties[GameManager::EASY] = &easy_button;
	difficulties[GameManager::MEDIUM] = &medium_button;
	difficulties[GameManager::HARD] = &hard_button;
}

void OptionsMenu::move_button(int id)
{

}