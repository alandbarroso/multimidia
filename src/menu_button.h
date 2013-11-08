#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <QImage>
#include <QRectF>
#include <QString>

class MenuButton
{
private:
	QImage normal;
	QImage selected;

	QRectF source_rect;
	QRectF hit_box;

	int hovered;
public:
	MenuButton(QString name);

	// Set where the button is located => The upper left point of the button
	void set_center(int x, int y);

	// Get the rectangle of the button
	QRectF get_rect();

	// Get the entire rectangle of the button
	QRectF get_source_rect();

	// Get the image to be printed
	QImage get_button();
};

#endif