#include <QImage>
#include <QPoint>
#include <QString>
#include <QRectF>

#include "menu_button.h"

MenuButton::MenuButton(QString name)
{
	QString dir = "../assets/";

	QString base_name = dir.append(name.append(".png"));
	QString selected_name = dir.append(name.append("_selected.png"));

	this->normal = QImage(base_name);
	this->selected = QImage(selected_name);

	hovered = 0;
}

QImage MenuButton::get_button()
{
	if(hovered)
	{
		return this->selected;
	}
	else
	{
		return this->normal;
	}
}

void MenuButton::set_position(int x, int y)
{
	this->point = QPoint(x, y);

	this->hit_box = QRectF(x, y, this->normal.width(), this->normal.height());
}

QPoint MenuButton::get_position()
{
	return this->point;
}