#include <stdio.h>

#include <QPainter>
#include <QImage>

#include "main_menu.h"
#include "single_player_menu.h"

MainMenu::MainMenu(int width, int height)
	: BaseMenu(width, height, "Main Menu"),
	singleplayer_button("button_single_player"),
	multiplayer_button("button_multi_player"),
	options_button("button_options"),
	quit_button("button_quit")
{
	qreal step = 0.15;
	qreal first_button = 0.4;

	singleplayer_button.set_center(width/2, (first_button + 0*step)*height);
	multiplayer_button.set_center(width/2, (first_button + 1*step)*height);
	options_button.set_center(width/2, (first_button + 2*step)*height);
	quit_button.set_center(width/2, (first_button + 3*step)*height);

	buttons["singleplayer"] = &singleplayer_button;
	buttons["multiplayer"] = &multiplayer_button;
	buttons["options"] = &options_button;
	buttons["quit"] = &quit_button;
}

void MainMenu::move_button(int id)
{
	if(buttons["singleplayer"]->get_hovered())
	{
		SinglePlayerMenu *singleplayer = new SinglePlayerMenu(width, height);

		emit change_state(singleplayer);

		return;
	}
	else if(buttons["multiplayer"]->get_hovered())
	{
		return;
	}
	else if(buttons["options"]->get_hovered())
	{
		return;
	}
	else if(buttons["quit"]->get_hovered())
	{
		emit exit_signal();

		return;
	}
}