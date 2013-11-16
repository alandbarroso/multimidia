#ifndef BASE_MENU_H
#define BASE_MENU_H

#include <QRectF>
#include <QMap>
#include <QVector>
#include <QRgb>

#include "game_state.h"
#include "menu_button.h"
#include "cursor.h"

class BaseMenu : public GameState
{
	Q_OBJECT
private:
	Cursor cursor;

	QVector<QRgb> color_table;

protected:
	QMap<QString, MenuButton*> buttons;

public:
	BaseMenu(int width, int height, QString name);

	// Update
	void update();

	// Paint the screen with the camera image
	void paint_screen_camera(QWidget* screen, QImage* camera_image);

	// Paint the screen
	void paint_screen(QWidget *screen);

	// Position changed
	void position(int id, int x, int y, int z);

	// Buttons
	virtual void move_button(int id);
	virtual void square_button(int id);
	virtual void triangle_button(int id);
	virtual void circle_button(int id);
	virtual void cross_button(int id);
	virtual void select_button(int id);
	virtual void start_button(int id);

	// Trigger
	virtual void trigger_pressed(int id, qreal trigger);
};

#endif