#include <stdio.h>

#include <QPainter>
#include <QImage>

#include "base_menu.h"

BaseMenu::BaseMenu(int width, int height, QString name)
	: GameState(width, height, name),
	cursor(width, height)
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
	cursor.set_center(this->width - x, y);
}

void BaseMenu::move_button(int id)
{

}

void BaseMenu::square_button(int id)
{

}

void BaseMenu::triangle_button(int id)
{

}

void BaseMenu::circle_button(int id)
{

}

void BaseMenu::cross_button(int id)
{

}

void BaseMenu::select_button(int id)
{

}

void BaseMenu::start_button(int id)
{

}

void BaseMenu::trigger_pressed(int id, qreal trigger)
{

}