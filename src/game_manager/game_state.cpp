#include <stdio.h>

#include <QColor>

#include "game_state.h"


int GameState::n = 0;

GameState::GameState()
{
	QString name = "State";

	name.append(n);
	n++;

	set_name(name);
}

GameState::GameState(QString name)
{
	set_name(name);
}

void GameState::set_name(QString name)
{
	this->name = name;
}

void GameState::calibration_finished()
{

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