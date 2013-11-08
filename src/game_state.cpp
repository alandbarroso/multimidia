#include <stdio.h>

#include "game_state.h"


// The number of the state
int GameState::n = 0;

// Simple constructor
GameState::GameState()
{
	QString name = "State";

	name.append(n);
	n++;

	set_name(name);
}

// Constructor with name
GameState::GameState(QString name)
{
	set_name(name);
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