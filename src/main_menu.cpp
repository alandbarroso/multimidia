#include <stdlib.h>

#include <QPainter>

#include "main_menu.h"

MainMenu::MainMenu(int width, int height)
	: GameState(width, height, "Main Menu"),
	singleplayer_button("button_base"),
	multiplayer_button("button_base"),
	options_button("button_base"),
	quit_button("button_base")
{
	singleplayer_button.set_center(width/2, 0.4*height);
	multiplayer_button.set_center(width/2, 0.55*height);
	options_button.set_center(width/2, 0.70*height);
	quit_button.set_center(width/2, 0.85*height);
}

void MainMenu::update()
{

}

void MainMenu::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	painter.drawImage(singleplayer_button.get_rect(), singleplayer_button.get_button(), singleplayer_button.get_source_rect());
	painter.drawImage(multiplayer_button.get_rect(), multiplayer_button.get_button(), multiplayer_button.get_source_rect());
	painter.drawImage(options_button.get_rect(), options_button.get_button(), options_button.get_source_rect());
	painter.drawImage(quit_button.get_rect(), quit_button.get_button(), quit_button.get_source_rect());
}