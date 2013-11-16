#ifndef SINGLEPLAYER_MENU_H
#define SINGLEPLAYER_MENU_H

#include <QRectF>
#include <QVector>
#include <QRgb>

#include "base_menu.h"
#include "menu_button.h"
#include "cursor.h"

class SinglePlayerMenu : public BaseMenu
{
	Q_OBJECT
private:
	MenuButton classic_mode_button;
	MenuButton dynamic_mode_button;
	MenuButton barrier_mode_button;

public:
	SinglePlayerMenu(int width, int height);

	// Move button pressed
	void move_button(int id);

	// Go back
	void circle_button(int id);
};

#endif