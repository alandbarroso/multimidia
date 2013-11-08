#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#include <QImage>
#include <QRectF>
#include <QPoint>
#include <QString>

class MenuButton
{
private:
	QImage normal;
	QImage selected;

	QPoint point;

	QRectF hit_box;

	int hovered;
public:
	MenuButton(QString name);

	// Set where the button is located => The upper left point of the button
	void set_position(int x, int y);

	// Get the position of the button
	QPoint get_position();

	// Get the image to be printed
	QImage get_button();
};

#endif