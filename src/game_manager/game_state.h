#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <QObject>
#include <QWidget>
#include <QString>

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

	//! The number of the state in the game.
	static int n;

	/************************************************
	*	Methods										*
	*************************************************/

	/*!
		Sets the name of the GameState.
		\param 	name 	The name of the GameState.
	*/
	void set_name(QString name);

protected:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! The name of the state.
	QString name;

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
		Initializes the name with StateN.
	*/
	GameState();

	//! Constructor passing the GameState name.
	GameState(QString name);

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

	/*! 
		Called when the move button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void move_button(int id);

	/*! 
		Called when the square button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void square_button(int id);

	/*! 
		Called when the triangle button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void triangle_button(int id);

	/*! 
		Called when the circle button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void circle_button(int id);

	/*! 
		Called when the cross button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void cross_button(int id);

	/*! 
		Called when the select button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void select_button(int id);

	/*! 
		Called when the start button is pressed.
		\param 	id 	Id of the PSMove controller.
	*/
	virtual void start_button(int id);

	/*! 
		Called when the trigger is pressed.
		\param 	id 		Id of the PSMove controller.
		\param trigger 	Value of the trigger.
	*/
	virtual void trigger_pressed(int id, qreal trigger);
};

#endif