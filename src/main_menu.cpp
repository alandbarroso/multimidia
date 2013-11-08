#include <QPainter>
#include <QImage>

#include "main_menu.h"

MainMenu::MainMenu(int width, int height)
	: GameState(width, height, "Main Menu"),
	singleplayer_button("button_base"),
	multiplayer_button("button_base"),
	options_button("button_base"),
	quit_button("button_base"),
	cursor(width, height)
{
	singleplayer_button.set_center(width/2, 0.4*height);
	multiplayer_button.set_center(width/2, 0.55*height);
	options_button.set_center(width/2, 0.70*height);
	quit_button.set_center(width/2, 0.85*height);

	for(int i = 0; i < 256; i++) color_table.push_back(qRgb(i,i,i));
}

void MainMenu::update()
{
	singleplayer_button.set_hovered(this->cursor);
	multiplayer_button.set_hovered(this->cursor);
	options_button.set_hovered(this->cursor);
	quit_button.set_hovered(this->cursor);
}

void MainMenu::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	if (camera_image) {
		QImage aux_image = camera_image->rgbSwapped().mirrored(true, false).convertToFormat(QImage::Format_Indexed8);
		aux_image.setColorTable(color_table);

		painter.drawImage(0, 0, aux_image);
	}

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