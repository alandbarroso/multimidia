#include <QImage>
#include <QPoint>
#include <QString>
#include <QRectF>

#include "menu_button.h"

MenuButton::MenuButton(QString name)
{
	QString dir = "../assets/";
	dir.append(name);

	QString base_name(dir);
	QString selected_name(dir);

	base_name.append(".png");
	selected_name.append("_selected.png");

	this->normal = QImage(base_name);
	this->selected = QImage(selected_name);

	this->source_rect = QRectF(0, 0, this->normal.width(), this->normal.height());

	qreal scale_factor = 0.6;
	this->hit_box = QRectF(0, 0, scale_factor*this->normal.width(), scale_factor*this->normal.height());

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

void MenuButton::set_hovered(Cursor cursor)
{
	this->hovered = this->hit_box.intersects(cursor.get_rect());
}

int MenuButton::get_hovered()
{
	return hovered;
}