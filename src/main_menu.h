#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "game_state.h"
#include "menu_button.h"

class MainMenu : public GameState
{
	Q_OBJECT
private:
	MenuButton test;

public:
	MainMenu();

	// Update
	void update();

	// Paint the screen
	void paint_screen(QWidget *screen);
};

#endif