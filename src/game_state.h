#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <QObject>
#include <QWidget>
#include <QString>

class GameState : public QObject
{
	 Q_OBJECT
private:
	static int n;

	void set_name(QString name);

protected:
	QString name; // The name of the state 

public:
	// Simple constructor
	GameState();

	// Constructor with name
	GameState(QString name);

	// Update the game logic 
	virtual void update() = 0;

	// Paint the screen
	virtual void paint_screen(QWidget* screen) = 0;

// Signal to change the current state
signals:
	void change_state(GameState* state);


// The slots are all virtual, can be implemented on each specific state
public slots:
	// Position changed
	virtual void position(int id, int x, int y, int z);

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

	// The camera image
	virtual void image(void* image);
};

#endif