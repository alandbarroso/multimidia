#include <stdio.h>

#include "main_menu.h"
#include "single_player_menu.h"
#include "options_menu.h"

MainMenu::MainMenu()
	: BaseMenu(GameManager::MAIN_MENU),
	singleplayer_button("button_single_player"),
	multiplayer_button("button_multi_player"),
	options_button("button_options"),
	quit_button("button_quit")
{
	int width = game_manager->get_width(); 
	int height = game_manager->get_height();

	qreal step = 0.15;
	qreal first_button = 0.4;

	singleplayer_button.set_center(width/2, (first_button + 0*step)*height);
	multiplayer_button.set_center(width/2, (first_button + 1*step)*height);
	options_button.set_center(width/2, (first_button + 2*step)*height);
	quit_button.set_center(width/2, (first_button + 3*step)*height);

	buttons["singleplayer"] = &singleplayer_button;
	// buttons["multiplayer"] = &multiplayer_button;
	// buttons["options"] = &options_button;
	buttons["quit"] = &quit_button;

	printf("Main menu initiated!\n");
}

void MainMenu::move_button_up(int id)
{
	if(buttons["singleplayer"]->get_hovered())
	{
		SinglePlayerMenu *singleplayer = new SinglePlayerMenu();

		emit change_state(singleplayer);

		return;
	}
	/*else if(buttons["multiplayer"]->get_hovered())
	{
		return;
	}
	else if(buttons["options"]->get_hovered())
	{
		OptionsMenu *options = new OptionsMenu();

		emit change_state(options);

		return;
	}*/
	else if(buttons["quit"]->get_hovered())
	{
		emit exit_signal();

		return;
	}
}

void MainMenu::circle_button_up(int id)
{
	
}