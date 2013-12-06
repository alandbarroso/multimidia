#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <QObject>

#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>

#include "psmove_controller_thread.h"

class GameState;

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
public:
	/************************************************
	*	Enums										*
	*************************************************/

	enum StateType
	{
		DEFAULT,
		CALIBRATION,
		MAIN_MENU,
		SINGLE_PLAYER_MENU,
		OPTIONS_MENU,
		SINGLE_CLASSIC_MODE,
		SINGEL_TIME_ATTACK,
		CONGRATULATIONS
	};

	enum Difficulty
	{
		EASY,
		MEDIUM,
		HARD
	};

	enum HandicapModeType
	{
		NO_HANDICAP,
		HANDICAPED
	};

	enum Game_Size
	{
		MODE_2M,
		MODE_3M,
		MODE_4M
	};

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

	//! The difficulty set for the game
	Difficulty difficulty;

	//! The mode set for the game
	HandicapModeType handicap_mode_type;

	//! The size set for the game
	Game_Size game_size;

	//! Media object used to play sounds
	Phonon::MediaObject *mediaObject;

	//! Audio output
	Phonon::AudioOutput *audioOutput;

	//! If true, sets the music loop
	int music_loop;

	//! Sets the music that should loop
	QString music_to_loop;

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

	/*!
		\return The current game difficulty
	*/
	Difficulty get_game_difficulty();

	/*!
		\return The current handicap mode
	*/
	HandicapModeType get_handicap_mode_type();

	/*!
		\return The current game size
	*/
	Game_Size get_game_size();

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

	/*!
		Change the difficulty of the game
		\param	difficulty 	The new difficulty
	*/
	void change_difficulty(GameManager::Difficulty difficulty);

	/*!
		Change the mode of the game
		\param	handicap_mode_type 	The new handicap mode type
	*/
	void change_handicap_mode(GameManager::HandicapModeType handicap_mode_type);

	/*!
		Change the size of the game
		\param	game_size 	The new size of the game
	*/
	void change_game_size(GameManager::Game_Size game_size);

	/*!
		Request to play music
	*/
	void play_music();

	/*!
		Request to stop music
	*/
	void stop_music();

	/*!
		Repeats the music
	*/
	void repeat_music();

	/*!
		Plays beep
	*/
	void play_beep();

	/*!
		Plays winning sound - when found
	*/
	void play_winning();

	/*!
		Plays cheering sound - when ended
	*/
	void play_cheering();

	/*!
		Plays damage sound
	*/
	void play_damage();

	/*!
		Plays damage sound
	*/
	void play_time_attack();

	/*!
		Change the sound volume
		\param	volume 	The sound volume to be set
	*/
	void change_sound_volume(qreal volume);
};

/************************************************
*	Global Variables							*
*************************************************/

/*!
	Global variable to reference the single instance of the GameManager
*/
extern GameManager* game_manager;

#endif