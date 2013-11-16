#include <stdio.h>

#include <QObject>

#include "psmove_tracker.h"
#include "psmove_controller_thread.h"
#include "opencv2/core/core_c.h"

#include "game_manager.h"
#include "game_state.h"
#include "main_menu.h"

GameManager::GameManager(int width, int height, PSMoveControllerThread* psmove_thread)
{
	this->psmove_thread = psmove_thread;

	this->width = width;
	this->height = height;

	this->camera_image = new QImage(width, height, QImage::Format_RGB888);
	this->camera_image->fill(QColor(0, 0, 0, 255));

	QObject::connect(psmove_thread, SIGNAL(image(void*)),
				this, SLOT(image(void*)));

	this->current_state = new MainMenu(width, height);

	connect_signals();
}

GameManager::~GameManager()
{
	if(this->current_state)
	{
		delete this->current_state;
	}

	if(this->camera_image)
	{
		delete camera_image;
	}
}

void GameManager::update()
{
	this->current_state->update();
}

void GameManager::paint_screen(QWidget* screen)
{
	if(camera_image)
	{
		this->current_state->paint_screen_camera(screen, camera_image);
	}

	this->current_state->paint_screen(screen);
}

void GameManager::change_state(GameState* state)
{
	if(this->current_state)
	{
		delete this->current_state;
	}

	current_state = state;

	connect_signals();
}

void GameManager::connect_signals()
{
	/* Change the states */
	QObject::connect(current_state, SIGNAL(change_state(GameState*)),
				this, SLOT(change_state(GameState*)));	

	/* Buttons */
	QObject::connect(psmove_thread, SIGNAL(position(int, int, int, int)),
				current_state, SLOT(position(int, int, int, int)));

	QObject::connect(psmove_thread, SIGNAL(move_button(int)),
				current_state, SLOT(move_button(int)));

	QObject::connect(psmove_thread, SIGNAL(square_button(int)),
				current_state, SLOT(square_button(int)));

	QObject::connect(psmove_thread, SIGNAL(triangle_button(int)),
				current_state, SLOT(triangle_button(int)));

	QObject::connect(psmove_thread, SIGNAL(circle_button(int)),
				current_state, SLOT(circle_button(int)));

	QObject::connect(psmove_thread, SIGNAL(cross_button(int)),
				current_state, SLOT(cross_button(int)));

	QObject::connect(psmove_thread, SIGNAL(select_button(int)),
				current_state, SLOT(select_button(int)));

	QObject::connect(psmove_thread, SIGNAL(start_button(int)),
				current_state, SLOT(start_button(int)));

	QObject::connect(psmove_thread, SIGNAL(trigger_pressed(int, qreal)),
				current_state, SLOT(trigger_pressed(int, qreal)));

	/* Exit signal */ 
	QObject::connect(current_state, SIGNAL(exit_signal()),
				psmove_thread, SLOT(exit_signal()));
}

void GameManager::disconnect_signals()
{
	QObject::disconnect(psmove_thread, 0, current_state, 0);

	QObject::disconnect(this, 0, current_state, 0);
}


void GameManager::image(void* image)
{
	static void *oldptr = NULL;

	if (image != oldptr) 
	{
		oldptr = image;

		IplImage *img = (IplImage*)image;
		assert(img->nChannels == 3);
		assert(img->depth == 8);

		if(this->camera_image)
		{
			delete this->camera_image;
		}
		camera_image = new QImage((uchar*)img->imageData, img->width, img->height, img->widthStep, QImage::Format_RGB888);
	}
}