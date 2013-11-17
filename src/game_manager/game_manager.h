#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <QObject>

#include "game_state.h"
#include "psmove_controller_thread.h"

/************************************************
*	Class										*
*************************************************/

//! GameManager Class.
/*!
	Singleton class that manage all the game states and options.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class GameManager : public QObject
{
	Q_OBJECT

private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Instance indicator.
	/*! If true, there is already one instance of GameManager created. */
	static bool instance_flag;

	//! The instance of GameManager.
	/*! The single instance of GameManager in the game. */
	static GameManager *single;

	//! The current GameState.
	/*! 
		Pointer to the current game state running.
		\sa GameState
	*/
	GameState* current_state;

	//! The PSMoveControllerThread.
	/*! 
		The thread that capture and send signals to the PSMove controller. 
		\sa PSMoveControllerThread
	*/
	PSMoveControllerThread* psmove_thread;

	/*! Screen width. */
	int width;
	/*! Screen height. */
	int height;

	//! Camera image.
	/*! 
		Stores the camera image sent from the controller thread
		\sa PSMoveControllerThread
	*/
	QImage *camera_image;

	/************************************************
	*	Methods										*
	*************************************************/

	/*! 
		Private constructor so that there is only one istance. 
	*/
	GameManager();	

	/*! 
		Connects the slots and signals to the current state.
	*/
	void connect_signals();

	/*! 
		Disconnect all the slots and signals from the current state.
		\attention	Not used.
	*/
	void disconnect_signals();

public:
	/************************************************
	*	Attributes									*
	*************************************************/

	/************************************************
	*	Methods										*
	*************************************************/

	/*! 
		Set the initial variables.
		\param	width			The screen width
		\param	height			The screen height
		\param	psmove_thread 	The psmove_thread used
	*/
	void init(int width, int height, PSMoveControllerThread* psmove_thread);

	/*! 
		Destructor.
	*/
	~GameManager();

	/*! 
		Get the instance of GameManager.
		\return	The only GameManager instance existing in the game
	*/
	static GameManager* getInstance();

	/*! 
		Called to update the game state.
		\sa GameState::update()
	*/
	void update();

	/*! 
		Called to paint the screen.
		\param	screen 	The screen to be painted
		\sa GameState::update()
	*/
	void paint_screen(QWidget* screen);

	/*!
		\return The game width
	*/
	int get_width();

	/*!
		\return The game width
	*/
	int get_height();

public slots:
	/************************************************
	*	Slots										*
	*************************************************/

	/*! 
		Change to new state.
		\param	state 	The new state to transit
	*/
	void change_state(GameState* state);

	/*! 
		Receive the camera image.
		\param	image 	The image received from the controller
	*/
	void image(void* image);
};

/************************************************
*	Global Variables							*
*************************************************/

/*!
	Global variable to reference the single instance of the GameManager
*/
extern GameManager* game_manager;

#endif