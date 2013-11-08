#include <stdio.h>

#include "game_state.h"


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
}

// Constructor with name
GameState::GameState(int width, int height, QString name)
{
	set_name(name);

	this->width = width;
	this->height = height;
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

}