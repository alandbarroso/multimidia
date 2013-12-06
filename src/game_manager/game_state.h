#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <QObject>
#include <QWidget>
#include <QString>

#include "game_manager.h"

/************************************************
*	Class										*
*************************************************/

//! GameState Class.
/*!
	Represents a state in the game.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/

class GameState : public QObject
{
	 Q_OBJECT
private:
	/************************************************
	*	Attributes									*
	*************************************************/

	/************************************************
	*	Methods										*
	*************************************************/

	/*!
		Sets the type of the GameState.
		\param 	type 	The type of the GameState.
	*/
	void set_type(GameManager::StateType type);

protected:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! The type of the state.
	GameManager::StateType type;

	/************************************************
	*	Methods										*
	*************************************************/

public:
	/************************************************
	*	Attributes									*
	*************************************************/

	/************************************************
	*	Methods										*
	*************************************************/

	//! Simple constructor.
	/*!
		Initializes the type with DEFAULT.
	*/
	GameState();

	//! Constructor passing the GameState type.
	GameState(GameManager::StateType type);

	/*!
		\return The type of the state
	*/
	GameManager::StateType get_type();

	//! Run the necessary configurations after being connected
	virtual void init();

	//! Update the game logic.
	/*! 
		Virtual method, to be implemented by derived classes.
		\sa GameManager::update()
	*/ 
	virtual void update() = 0;

	//! Paint the screen with the camera image.
	/*! 
		Virtual method, to be implemented by derived classes.
		\param 	screen 			The target screen.
		\param 	camera_image 	Camera image to be treated if necessary.
		\sa GameManager::paint_screen()
	*/
	virtual void paint_screen_camera(QWidget* screen, QImage* camera_image) = 0;

	//! Paint the screen over the camera image.
	/*! 
		Virtual method, to be implemented by derived classes.
		\param 	screen 			The target screen.
		\sa GameManager::paint_screen()
	*/
	virtual void paint_screen(QWidget* screen) = 0;

signals:
	/************************************************
	*	Signals										*
	*************************************************/

	//! Signal to change the GameState.
	void change_state(GameState* state);

	//! Send a exit signal to the application.
	void exit_signal();

	//! Signal to change the difficulty.
	void change_difficulty(GameManager::Difficulty difficulty);

	//! Signal to change the handicap mode.
	void change_handicap_mode(GameManager::HandicapModeType handicap_mode_type);
	
	//! Signal to change the size of the game.
	void change_game_size(GameManager::Game_Size game_size);

	//! Signal to set the color change
	void set_change_color(int change);

	//! Signal to set the color of the LEDs
	void set_color(int r, int g, int b);

	//! Signal to set the vibration change
	void set_change_vibration(int change);

	//! Signal to set intensity of the vibrations
	void set_vibration(int intensity);

	//!	Request to play music
	void play_music();

	//!	Request to stop music
	void stop_music();

	//! Repeats the music
	void repeat_music();

	//! Plays beep
	void play_beep();

	//! Plays winning sound - when found
	void play_winning();

	//! Plays cheering sound - when ended
	void play_cheering();

	//! Plays damage sound
	void play_damage();

	void play_time_attack();


	//! Change the sound volume
	void change_sound_volume(qreal volume);

public slots:
	/************************************************
	*	Slots										*
	*************************************************/

	//! To be executed when calibration finishes
	virtual void calibration_finished();

	/*! 
		Called when the position changes.
		\param 	id 	Id of the PSMove controller that moved.
		\param 	x 	X coordinate of the controller.
		\param 	y 	Y coordinate of the controller.
		\param 	z 	Z coordinate of the controller.
	*/
	virtual void position(int id, int x, int y, int z);

	/***************** Button Down *****************/

	/*! 
		Called when the move button goes down.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void move_button_down(int id);

	/*! 
		Called when the square button goes down.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void square_button_down(int id);

	/*! 
		Called when the triangle button goes down.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void triangle_button_down(int id);

	/*! 
		Called when the circle button goes down.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void circle_button_down(int id);

	/*! 
		Called when the cross button goes down.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void cross_button_down(int id);

	/*! 
		Called when the select button goes down.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void select_button_down(int id);

	/*! 
		Called when the start button goes down.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void start_button_down(int id);

	/*************** Button Pressed ***************/

	/*! 
		Called when the move button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void move_button_pressed(int id);

	/*! 
		Called when the square button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void square_button_pressed(int id);

	/*! 
		Called when the triangle button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void triangle_button_pressed(int id);

	/*! 
		Called when the circle button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void circle_button_pressed(int id);

	/*! 
		Called when the cross button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void cross_button_pressed(int id);

	/*! 
		Called when the select button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void select_button_pressed(int id);

	/*! 
		Called when the start button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void start_button_pressed(int id);

	/***************** Button Up *****************/

	/*! 
		Called when the move button goes up.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void move_button_up(int id);

	/*! 
		Called when the square button goes up.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void square_button_up(int id);

	/*! 
		Called when the triangle button goes up.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void triangle_button_up(int id);

	/*! 
		Called when the circle button goes up.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void circle_button_up(int id);

	/*! 
		Called when the cross button goes up.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void cross_button_up(int id);

	/*! 
		Called when the select button goes up.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void select_button_up(int id);

	/*! 
		Called when the start button goes up.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void start_button_up(int id);

	/*! 
		Called when the trigger is pressed.
		\param 	id 		Id of the PSMove controller.
		\param trigger 	Value of the trigger.
	*/
	virtual void trigger_pressed(int id, qreal trigger);
};

#endif