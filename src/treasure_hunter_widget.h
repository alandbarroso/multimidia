#ifndef ORIENTATIONVIEW_H
#define ORIENTATIONVIEW_H

#include <QWidget>
#include <QImage>

#include "psmove_controller_thread.h"
#include "game_manager.h"

/************************************************
*	Class										*
*************************************************/

//! ThreadHunterWidget Class.
/*!
	Main screen of the game.
	\author		Alan Barroso
	\author		Ricardo Dall'Olio
	\author		Eduardo Cominetti
	\version	1.0
	\date		2013
*/
class TreasureHunterWidget : public QWidget
{
    Q_OBJECT
public:
	/************************************************
	*	Attributes									*
	*************************************************/

	/************************************************
	*	Methods										*
	*************************************************/

	//! Constructor
	/*!
		\param 	parent 		The parent screen (Used to QWidget constructor).
		\param 	width 		The width that the screen shall have.
		\param 	height 		The height that the screen shall have.
		\param 	controller 	The thread to be passed to the GameManager::init()
	*/
    TreasureHunterWidget(QWidget *parent, int width, int height, PSMoveControllerThread* controller);

protected:
	/************************************************
	*	Attributes									*
	*************************************************/

	/************************************************
	*	Methods										*
	*************************************************/

	//! Paints the screen
	/*!
		Inherited method from QWidget
	*/
    void paintEvent(QPaintEvent *event);

public slots:
	/************************************************
	*	Slots										*
	*************************************************/

	/*!
		When a signal is received the screen is updated
	*/
    void update_screen();
};

#endif
