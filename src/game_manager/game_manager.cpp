#include <stdio.h>

#include <QObject>

#include "psmove_tracker.h"
#include "psmove_controller_thread.h"
#include "opencv2/core/core_c.h"

#include "game_manager.h"
#include "calibration_state.h"

GameManager* game_manager = GameManager::getInstance();

bool GameManager::instance_flag = false;

GameManager* GameManager::single = NULL;

GameManager* GameManager::getInstance()
{
	if(! instance_flag)
	{
		single = new GameManager();
		instance_flag = true;
		return single;
	}
	else
	{
		return single;
	}
}

GameManager::GameManager()
{
	this->width = 800;
	this->height = 600;

	this->difficulty = MEDIUM;
	this->handicap_mode_type = NO_HANDICAP;
	this->game_size = MODE_3M;
}

void GameManager::init(int width, int height, PSMoveControllerThread* psmove_thread)
{
	this->psmove_thread = psmove_thread;

	this->width = width;
	this->height = height;

	this->camera_image = new QImage(width, height, QImage::Format_RGB888);
	this->camera_image->fill(QColor(0, 0, 0, 255));

	QObject::connect(psmove_thread, SIGNAL(image(void*)),
				this, SLOT(image(void*)));

	this->current_state = new CalibrationState();

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

	instance_flag = false;
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

	/* Change difficulty */
	QObject::connect(current_state, SIGNAL(change_difficulty(GameManager::Difficulty)),
				this, SLOT(change_difficulty(GameManager::Difficulty)));

	/* Change handicap mode */
	QObject::connect(current_state, SIGNAL(change_handicap_mode(GameManager::HandicapModeType)),
				this, SLOT(change_handicap_mode(GameManager::HandicapModeType)));

	/* Change difficulty */
	QObject::connect(current_state, SIGNAL(change_game_size(GameManager::Game_Size)),
				this, SLOT(change_game_size(GameManager::Game_Size)));

	/* End of calibration */
	QObject::connect(psmove_thread, SIGNAL(calibration_finished()),
				current_state, SLOT(calibration_finished()));

	QObject::connect(psmove_thread, SIGNAL(position(int, int, int, int)),
				current_state, SLOT(position(int, int, int, int)));

	/* Buttons up */
	QObject::connect(psmove_thread, SIGNAL(move_button_down(int)),
				current_state, SLOT(move_button_down(int)));

	QObject::connect(psmove_thread, SIGNAL(square_button_down(int)),
				current_state, SLOT(square_button_down(int)));

	QObject::connect(psmove_thread, SIGNAL(triangle_button_down(int)),
				current_state, SLOT(triangle_button_down(int)));

	QObject::connect(psmove_thread, SIGNAL(circle_button_down(int)),
				current_state, SLOT(circle_button_down(int)));

	QObject::connect(psmove_thread, SIGNAL(cross_button_down(int)),
				current_state, SLOT(cross_button_down(int)));

	QObject::connect(psmove_thread, SIGNAL(select_button_down(int)),
				current_state, SLOT(select_button_down(int)));

	QObject::connect(psmove_thread, SIGNAL(start_button_down(int)),
				current_state, SLOT(start_button_down(int)));

	/* Buttons pressed */
	QObject::connect(psmove_thread, SIGNAL(move_button_pressed(int)),
				current_state, SLOT(move_button_pressed(int)));

	QObject::connect(psmove_thread, SIGNAL(square_button_pressed(int)),
				current_state, SLOT(square_button_pressed(int)));

	QObject::connect(psmove_thread, SIGNAL(triangle_button_pressed(int)),
				current_state, SLOT(triangle_button_pressed(int)));

	QObject::connect(psmove_thread, SIGNAL(circle_button_pressed(int)),
				current_state, SLOT(circle_button_pressed(int)));

	QObject::connect(psmove_thread, SIGNAL(cross_button_pressed(int)),
				current_state, SLOT(cross_button_pressed(int)));

	QObject::connect(psmove_thread, SIGNAL(select_button_pressed(int)),
				current_state, SLOT(select_button_pressed(int)));

	QObject::connect(psmove_thread, SIGNAL(start_button_pressed(int)),
				current_state, SLOT(start_button_pressed(int)));

	/* Buttons down */
	QObject::connect(psmove_thread, SIGNAL(move_button_up(int)),
				current_state, SLOT(move_button_up(int)));

	QObject::connect(psmove_thread, SIGNAL(square_button_up(int)),
				current_state, SLOT(square_button_up(int)));

	QObject::connect(psmove_thread, SIGNAL(triangle_button_up(int)),
				current_state, SLOT(triangle_button_up(int)));

	QObject::connect(psmove_thread, SIGNAL(circle_button_up(int)),
				current_state, SLOT(circle_button_up(int)));

	QObject::connect(psmove_thread, SIGNAL(cross_button_up(int)),
				current_state, SLOT(cross_button_up(int)));

	QObject::connect(psmove_thread, SIGNAL(select_button_up(int)),
				current_state, SLOT(select_button_up(int)));

	QObject::connect(psmove_thread, SIGNAL(start_button_up(int)),
				current_state, SLOT(start_button_up(int)));

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

int GameManager::get_width()
{
	return this->width;
}

int GameManager::get_height()
{
	return this->height;
}

GameManager::Difficulty GameManager::get_game_difficulty()
{
	return this->difficulty;
}

void GameManager::change_difficulty(GameManager::Difficulty difficulty)
{
	this->difficulty = difficulty;
}

GameManager::HandicapModeType GameManager::get_handicap_mode_type()
{
	return this->handicap_mode_type;
}

void GameManager::change_handicap_mode(GameManager::HandicapModeType handicap_mode_type)
{
	this->handicap_mode_type = handicap_mode_type;
}

GameManager::Game_Size GameManager::get_game_size()
{
	return this->game_size;
}

void GameManager::change_game_size(GameManager::Game_Size game_size)
{
	this->game_size = game_size;
}