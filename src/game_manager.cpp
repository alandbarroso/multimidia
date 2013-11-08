#include <QObject>

#include "game_manager.h"
#include "game_state.h"
#include "main_menu.h"

GameManager::GameManager(int width, int height, PSMoveControllerThread* psmove_thread)
{
	this->psmove_thread = psmove_thread;

	this->width = width;
	this->height = height;

	current_state = new MainMenu(width, height);

	connect_signals();
}

void GameManager::update()
{
	this->current_state->update();
}

void GameManager::paint_screen(QWidget* screen)
{
	this->current_state->paint_screen(screen);
}

void GameManager::change_state(GameState* state)
{
	disconnect_signals();

	current_state = state;

	connect_signals();
}

void GameManager::connect_signals()
{
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

	QObject::connect(psmove_thread, SIGNAL(image(void*)),
				current_state, SLOT(image(void*)));
}

void GameManager::disconnect_signals()
{
	QObject::disconnect(psmove_thread, 0, current_state, 0);
}