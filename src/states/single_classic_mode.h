#ifndef SINGLE_CLASSIC_MODE_H
#define SINGLE_CLASSIC_MODE_H

#include "game_state.h"

/************************************************
*	Class										*
*************************************************/

//! SingleClassicMode Class.
/*!
	Initial state. Asks the user to wait while the controller is being calibrated.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class SingleClassicMode : public GameState
{
	Q_OBJECT

private:
	/************************************************
	*	Attributes									*
	*************************************************/

	//! Max distance
	const int MAX_DISTANCE = 400;

	//! Coordinates of the player 
	int x, y, z;

	//! Space point
	struct SpacePoint
	{
		int z;
		int x;
		int y;
	};

	//! Objective attributes
	SpacePoint objective;

	//! Barriers
	QList<SpacePoint> barriers;

	//! Number of barriers
	int nb_barriers;

	//! Sets the minimal distance to start the vibration
	qreal objective_vibration_distance;

	//! Sets the minimal distance to start hearing the beep
	qreal obstacle_hearing_sound;

	//! If true, the beep has already been set
	int set_beep;

	//! Sets the distance to win
	qreal distance_to_win;

	//! Sets the distance to take damage
	qreal distance_to_damage;

	//! Taken damage
	int taken_damage;

	//! Sets the minimal distance between the objective and the obstacles
	qreal min_distance_obstacles;

	//! The current distance to the closest obstacle
	qreal current_distance;

	//! Indicates if have won
	int have_won;

	//! Score of the game
	int score;

	//! Penalty
	int penalty;

	//! Lost over time
	qreal lost_by_time;

	// TIMERS

	//! Winning timer
	QTime winning_timer;

	//! Score timer
	QTime score_timer;

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

	/*!
		Basic constructor, initiates the images.
	*/
	SingleClassicMode();

	/*! Destructor */
	~SingleClassicMode();

	/*!
		Initial configuration.
	*/
	void init();

	/*!
		Prints the distance from the screen.
	*/
	void update();

	/*!
		Paints the camera image.
	*/
	void paint_screen_camera(QWidget* screen, QImage* camera_image);

	/*!
		Paints nothing
	*/
	void paint_screen(QWidget* screen);

	/*!
		Updates the player position.
	*/
	void position(int id, int x, int y, int z);

	/*! 
		Send signal to the controller to change the LED color
	*/
	void trigger_pressed(int id, qreal trigger);
};

#endif