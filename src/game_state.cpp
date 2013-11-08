#include <stdio.h>

#include <QColor>

#include "game_state.h"

#include "psmove_tracker.h"
#include "psmove_controller_thread.h"
#include "opencv2/core/core_c.h"


// The number of the state
int GameState::n = 0;

// Simple constructor
GameState::GameState(int width, int height)
{
	QString name = "State";

	name.append(n);
	n++;

	set_name(name);

	this->width = width;
	this->height = height;

	this->camera_image = new QImage(width, height, QImage::Format_RGB888);
	this->camera_image->fill(QColor(0, 0, 0, 255));
}

// Constructor with name
GameState::GameState(int width, int height, QString name)
{
	set_name(name);

	this->width = width;
	this->height = height;
}

GameState::~GameState()
{
	if(this->camera_image)
	{
		delete this->camera_image;
	}
}

// Set the name of the state
void GameState::set_name(QString name)
{
	this->name = name;
}

void GameState::position(int id, int x, int y, int z)
{

}

void GameState::move_button(int id)
{

}

void GameState::square_button(int id)
{

}

void GameState::triangle_button(int id)
{

}

void GameState::circle_button(int id)
{

}

void GameState::cross_button(int id)
{

}

void GameState::select_button(int id)
{

}

void GameState::start_button(int id)
{

}

void GameState::trigger_pressed(int id, qreal trigger)
{

}

void GameState::image(void* image)
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