#include <QPainter>
#include <QImage>

#include "main_menu.h"
#include "single_player_menu.h"

SinglePlayerMenu::SinglePlayerMenu(int width, int height)
	: GameState(width, height, "SinglePLayerMenu"),
	classic_mode_button("button_base"),
	dynamic_mode_button("button_base"),
	barrier_mode_button("button_base"),
	cursor(width, height)
{
	qreal step = 0.15;
	qreal first_button = 0.4;

	classic_mode_button.set_center(width/2, (first_button + 0*step)*height);
	dynamic_mode_button.set_center(width/2, (first_button + 1*step)*height);
	barrier_mode_button.set_center(width/2, (first_button + 2*step)*height);

	for(int i = 0; i < 256; i++) color_table.push_back(qRgb(i,i,i));
}

void SinglePlayerMenu::update()
{
	classic_mode_button.set_hovered(this->cursor);
	dynamic_mode_button.set_hovered(this->cursor);
	barrier_mode_button.set_hovered(this->cursor);
}

void SinglePlayerMenu::paint_screen_camera(QWidget* screen, QImage* camera_image)
{
	QPainter painter(screen);

	QImage aux_image = camera_image->rgbSwapped().mirrored(true, false).convertToFormat(QImage::Format_Indexed8);
	aux_image.setColorTable(color_table);

	painter.drawImage(0, 0, aux_image);	
}

void SinglePlayerMenu::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	painter.drawImage(classic_mode_button.get_rect(), classic_mode_button.get_button(), classic_mode_button.get_source_rect());
	painter.drawImage(dynamic_mode_button.get_rect(), dynamic_mode_button.get_button(), dynamic_mode_button.get_source_rect());
	painter.drawImage(barrier_mode_button.get_rect(), barrier_mode_button.get_button(), barrier_mode_button.get_source_rect());

	painter.drawImage(cursor.get_rect(), cursor.get_cursor(), cursor.get_source_rect());
}

void SinglePlayerMenu::position(int id, int x, int y, int z)
{
	cursor.set_center(this->width - x, y);
}

void SinglePlayerMenu::move_button(int id)
{
	if(classic_mode_button.get_hovered())
	{
		return;
	}
	else if(dynamic_mode_button.get_hovered())
	{
		return;
	}
	else if(barrier_mode_button.get_hovered())
	{
		return;
	}
}

void SinglePlayerMenu::circle_button(int id)
{
	MainMenu *main_menu = new MainMenu(width, height);

	emit change_state(main_menu);

	return;
}