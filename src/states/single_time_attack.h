#ifndef SINGLE_TIME_ATTACK_H
#define SINGLE_TIME_ATTACK_H

#include "game_state.h"

/************************************************
*	Class										*
*************************************************/

//! SingleTimeAttack Class.
/*!
	Initial state. Asks the user to wait while the controller is being calibrated.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class SingleTimeAttack : public GameState
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

	//! Sets the minimal distance to start the vibration
	qreal objective_vibration_distance;

	//! Sets the distance to win
	qreal distance_to_win;

	//! Indicates if have won
	int have_won;

	//! Score of the game
	int score;

	//! Bonus
	int bonus;

	//! Total time of game
	int total_game_time;

	// TIMERS

	//! Winning timer
	QTime winning_timer;

	//! Game time
	QTime game_time;

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
	SingleTimeAttack();

	/*! Destructor */
	~SingleTimeAttack();

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
};

#endif