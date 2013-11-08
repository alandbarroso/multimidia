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

	this->source_rect = QRectF(0, 0, this->normal.width(), this->normal.height());

	this->hit_box = QRectF(0, 0, 0.75*this->normal.width(), 0.75*this->normal.height());

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

void MenuButton::set_center(int x, int y)
{
	QPoint p(x, y);

	hit_box.moveCenter(p);
}

QRectF MenuButton::get_rect()
{
	return this->hit_box;
}

QRectF MenuButton::get_source_rect()
{
	return this->source_rect;
}