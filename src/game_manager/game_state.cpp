#include <stdio.h>

#include <QColor>

#include "game_state.h"

GameState::GameState()
{
	set_type(GameManager::DEFAULT);
}

GameState::GameState(GameManager::StateType type)
{
	set_type(type);
}

void GameState::set_type(GameManager::StateType type)
{
	this->type = type;
}

GameManager::StateType GameState::get_type()
{
	return this->type;
}

void GameState::init()
{

}

void GameState::calibration_finished()
{

}

void GameState::position(int id, int x, int y, int z)
{

}

void GameState::move_button_down(int id)
{

}

void GameState::square_button_down(int id)
{

}

void GameState::triangle_button_down(int id)
{

}

void GameState::circle_button_down(int id)
{

}

void GameState::cross_button_down(int id)
{

}

void GameState::select_button_down(int id)
{

}

void GameState::start_button_down(int id)
{

}

void GameState::move_button_pressed(int id)
{

}

void GameState::square_button_pressed(int id)
{

}

void GameState::triangle_button_pressed(int id)
{

}

void GameState::circle_button_pressed(int id)
{

}

void GameState::cross_button_pressed(int id)
{

}

void GameState::select_button_pressed(int id)
{

}

void GameState::start_button_pressed(int id)
{

}

void GameState::move_button_up(int id)
{

}

void GameState::square_button_up(int id)
{

}

void GameState::triangle_button_up(int id)
{

}

void GameState::circle_button_up(int id)
{

}

void GameState::cross_button_up(int id)
{

}

void GameState::select_button_up(int id)
{

}

void GameState::start_button_up(int id)
{

}

void GameState::trigger_pressed(int id, qreal trigger)
{

}