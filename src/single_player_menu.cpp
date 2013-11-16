#include <QPainter>
#include <QImage>

#include "main_menu.h"
#include "single_player_menu.h"

SinglePlayerMenu::SinglePlayerMenu(int width, int height)
	: BaseMenu(width, height, "SinglePLayerMenu"),
	classic_mode_button(),
	dynamic_mode_button(),
	barrier_mode_button()
{
	qreal step = 0.15;
	qreal first_button = 0.4;

	classic_mode_button.set_center(width/2, (first_button + 0*step)*height);
	dynamic_mode_button.set_center(width/2, (first_button + 1*step)*height);
	barrier_mode_button.set_center(width/2, (first_button + 2*step)*height);

	buttons["classic_mode"] = &classic_mode_button;
	buttons["dynamic_mode"] = &dynamic_mode_button;
	buttons["barrier_mode"] = &barrier_mode_button;	
}

void SinglePlayerMenu::move_button(int id)
{
	if(classic_mode_button.get_hovered())
	{
		return;
	}
	else if(dynamic_mode_button.get_hovered())
	{
		return;
	}
	else if(barrier_mode_button.get_hovered())
	{
		return;
	}
}

void SinglePlayerMenu::circle_button(int id)
{
	MainMenu *main_menu = new MainMenu(width, height);

	emit change_state(main_menu);

	return;
}