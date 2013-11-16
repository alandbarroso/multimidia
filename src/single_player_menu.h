#ifndef SINGLEPLAYER_MENU_H
#define SINGLEPLAYER_MENU_H

#include <QRectF>
#include <QVector>
#include <QRgb>

#include "game_state.h"
#include "menu_button.h"
#include "cursor.h"

class SinglePlayerMenu : public GameState
{
	Q_OBJECT
private:
	MenuButton classic_mode_button;
	MenuButton dynamic_mode_button;
	MenuButton barrier_mode_button;

	Cursor cursor;

	QVector<QRgb> color_table;

public:
	SinglePlayerMenu(int width, int height);

	// Update
	void update();

	// Paint the screen with the camera image
	void paint_screen_camera(QWidget* screen, QImage* camera_image);

	// Paint the screen
	void paint_screen(QWidget *screen);


public slots:
	// Position changed
	void position(int id, int x, int y, int z);

	// Move button pressed
	void move_button(int id);

	// Go back
	void circle_button(int id);
};

#endif