#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <QObject>

#include "game_state.h"
#include "psmove_controller_thread.h"

class GameManager : public QObject
{
	 Q_OBJECT
private:
	// The current state of the game
	GameState* current_state;

	// The thread that get the ps move controllers
	PSMoveControllerThread* psmove_thread;

	// Width and Height of the screen
	int width;
	int height;

	// The image from the camera
	QImage *camera_image;

	// Connects the slots and signals to the current state
	void connect_signals();

	// Disconnect all the slots and signals from the current state
	void disconnect_signals();

public:
	// The constructor to create the states and initiate the game
	GameManager(int width, int height, PSMoveControllerThread* psmove_thread);
	~GameManager();

	// Called to update the game state
	void update();

	// Called to paint the screen
	void paint_screen(QWidget* screen);

public slots:
	// Change to new state
	void change_state(GameState* state);

	// The camera image
	void image(void* image);
};

#endif