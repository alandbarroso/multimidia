#ifndef CURSOR_H
#define CURSOR_H

#include <QImage>
#include <QRectF>
#include <QString>

class Cursor
{
private:
	QImage cursor;

	QRectF source_rect;
	QRectF hit_box;

	int hovered;
public:
	Cursor(int width, int height);

	// Set where the cursor is located => The upper left point of the cursor
	void set_center(int x, int y);

	// Get the rectangle of the cursor
	QRectF get_rect();

	// Get the entire rectangle of the cursor
	QRectF get_source_rect();

	// Get the image to be printed
	QImage get_cursor();
};

#endif