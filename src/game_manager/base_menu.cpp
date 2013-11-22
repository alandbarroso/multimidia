#include <stdio.h>

#include <QPainter>
#include <QImage>
#include <QMapIterator>

#include "base_menu.h"
#include "main_menu.h"

BaseMenu::BaseMenu(GameManager::StateType type)
	: GameState(type),
	cursor()
{
	for(int i = 0; i < 256; i++) color_table.push_back(qRgb(i,i,i));
}

void BaseMenu::update()
{
	QMapIterator<QString, MenuButton*> i(buttons);
	while (i.hasNext()) {
		i.next();
		
		MenuButton* b = i.value();

		b->set_hovered(this->cursor);
	}
}

void BaseMenu::paint_screen_camera(QWidget* screen, QImage* camera_image)
{
	QPainter painter(screen);

	QImage aux_image = camera_image->rgbSwapped().mirrored(true, false).convertToFormat(QImage::Format_Indexed8);
	aux_image.setColorTable(color_table);

	painter.drawImage(0, 0, aux_image);	
}

void BaseMenu::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	QMapIterator<QString, MenuButton*> i(buttons);
	while (i.hasNext()) {
		i.next();
		
		MenuButton* b = i.value();

		painter.drawImage(b->get_rect(), b->get_button(), b->get_source_rect());
	}

	painter.drawImage(cursor.get_rect(), cursor.get_cursor(), cursor.get_source_rect());
}

void BaseMenu::position(int id, int x, int y, int z)
{
	int width = game_manager->get_width();
	
	cursor.set_center(width - x, y);
}

void BaseMenu::move_button_down(int id)
{

}

void BaseMenu::square_button_down(int id)
{

}

void BaseMenu::triangle_button_down(int id)
{

}

void BaseMenu::circle_button_down(int id)
{

}

void BaseMenu::cross_button_down(int id)
{

}

void BaseMenu::select_button_down(int id)
{

}

void BaseMenu::start_button_down(int id)
{

}

void BaseMenu::move_button_pressed(int id)
{

}

void BaseMenu::square_button_pressed(int id)
{

}

void BaseMenu::triangle_button_pressed(int id)
{

}

void BaseMenu::circle_button_pressed(int id)
{

}

void BaseMenu::cross_button_pressed(int id)
{

}

void BaseMenu::select_button_pressed(int id)
{

}

void BaseMenu::start_button_pressed(int id)
{

}

void BaseMenu::move_button_up(int id)
{

}

void BaseMenu::square_button_up(int id)
{

}

void BaseMenu::triangle_button_up(int id)
{

}

void BaseMenu::circle_button_up(int id)
{
	MainMenu *main_menu = new MainMenu();

	emit change_state(main_menu);

	return;

}

void BaseMenu::cross_button_up(int id)
{

}

void BaseMenu::select_button_up(int id)
{

}

void BaseMenu::start_button_up(int id)
{

}

void BaseMenu::trigger_pressed(int id, qreal trigger)
{

}