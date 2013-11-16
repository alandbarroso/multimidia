#include <QImage>
#include <QPoint>
#include <QString>
#include <QRectF>

#include "cursor.h"

Cursor::Cursor(int width, int height)
{
	QString file_name = ":/assets/cursor.png";

	this->cursor = QImage(file_name);

	this->source_rect = QRectF(0, 0, this->cursor.width(), this->cursor.height());

	int initial_x = -50;
	int initial_y = -50;

	qreal screen_height_scale = 0.07;
	qreal scale_factor = screen_height_scale*height/this->cursor.height();
	this->hit_box = QRectF(0, 0, scale_factor*this->cursor.width(), screen_height_scale*height);

	this->set_center(initial_x, initial_y);

	hovered = 0;
}

QImage Cursor::get_cursor()
{
	return cursor;
}

void Cursor::set_center(int x, int y)
{
	QPoint p(x, y);

	hit_box.moveCenter(p);
}

QRectF Cursor::get_rect()
{
	return this->hit_box;
}

QRectF Cursor::get_source_rect()
{
	return this->source_rect;
}