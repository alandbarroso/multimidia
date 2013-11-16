#include <stdio.h>

#include <QPainter>
#include <QImage>

#include "main_menu.h"
#include "single_player_menu.h"

MainMenu::MainMenu(int width, int height)
	: GameState(width, height, "Main Menu"),
	singleplayer_button("button_single_player"),
	multiplayer_button("button_multiplayer"),
	options_button("button_options"),
	quit_button("button_quit"),
	cursor(width, height)
{
	qreal step = 0.15;
	qreal first_button = 0.4;

	singleplayer_button.set_center(width/2, (first_button + 0*step)*height);
	multiplayer_button.set_center(width/2, (first_button + 1*step)*height);
	options_button.set_center(width/2, (first_button + 2*step)*height);
	quit_button.set_center(width/2, (first_button + 3*step)*height);

	for(int i = 0; i < 256; i++) color_table.push_back(qRgb(i,i,i));
}

void MainMenu::update()
{
	singleplayer_button.set_hovered(this->cursor);
	multiplayer_button.set_hovered(this->cursor);
	options_button.set_hovered(this->cursor);
	quit_button.set_hovered(this->cursor);
}

void MainMenu::paint_screen_camera(QWidget* screen, QImage* camera_image)
{
	QPainter painter(screen);

	QImage aux_image = camera_image->rgbSwapped().mirrored(true, false).convertToFormat(QImage::Format_Indexed8);
	aux_image.setColorTable(color_table);

	painter.drawImage(0, 0, aux_image);	
}

void MainMenu::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	painter.drawImage(singleplayer_button.get_rect(), singleplayer_button.get_button(), singleplayer_button.get_source_rect());
	painter.drawImage(multiplayer_button.get_rect(), multiplayer_button.get_button(), multiplayer_button.get_source_rect());
	painter.drawImage(options_button.get_rect(), options_button.get_button(), options_button.get_source_rect());
	painter.drawImage(quit_button.get_rect(), quit_button.get_button(), quit_button.get_source_rect());

	painter.drawImage(cursor.get_rect(), cursor.get_cursor(), cursor.get_source_rect());
}

void MainMenu::position(int id, int x, int y, int z)
{
	cursor.set_center(this->width - x, y);
}

void MainMenu::move_button(int id)
{
	if(singleplayer_button.get_hovered())
	{
		SinglePlayerMenu *singleplayer = new SinglePlayerMenu(width, height);

		emit change_state(singleplayer);

		return;
	}
	else if(multiplayer_button.get_hovered())
	{
		return;
	}
	else if(options_button.get_hovered())
	{
		return;
	}
	else if(quit_button.get_hovered())
	{
		emit exit_signal();

		return;
	}
}