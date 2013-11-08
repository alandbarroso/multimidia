#ifndef MAIN_MENU_H
#define MAIN_MENU_H

 #include <QRectF>

#include "game_state.h"
#include "menu_button.h"

class MainMenu : public GameState
{
	Q_OBJECT
private:
	MenuButton singleplayer_button;
	MenuButton multiplayer_button;
	MenuButton options_button;
	MenuButton quit_button;

public:
	MainMenu(int width, int height);

	// Update
	void update();

	// Paint the screen
	void paint_screen(QWidget *screen);
};

#endif