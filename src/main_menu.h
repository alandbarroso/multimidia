#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QRectF>
#include <QVector>
#include <QRgb>

#include "game_state.h"
#include "menu_button.h"
#include "cursor.h"

class MainMenu : public GameState
{
	Q_OBJECT
private:
	MenuButton singleplayer_button;
	MenuButton multiplayer_button;
	MenuButton options_button;
	MenuButton quit_button;

	Cursor cursor;

	QVector<QRgb> color_table;

public:
	MainMenu(int width, int height);

	// Update
	void update();

	// Paint the screen
	void paint_screen(QWidget *screen);


public slots:
	// Position changed
	void position(int id, int x, int y, int z);
};

#endif