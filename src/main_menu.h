#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QRectF>
#include <QVector>
#include <QRgb>

#include "base_menu.h"
#include "menu_button.h"
#include "cursor.h"

class MainMenu : public BaseMenu
{
	Q_OBJECT
private:
	MenuButton singleplayer_button;
	MenuButton multiplayer_button;
	MenuButton options_button;
	MenuButton quit_button;

public:
	MainMenu(int width, int height);

	// Move button pressed
	void move_button(int id);
};

#endif