#include <QPainter>
#include <QImage>

#include "main_menu.h"
#include "single_player_menu.h"

#include "single_classic_mode.h"
#include "single_time_attack.h"

SinglePlayerMenu::SinglePlayerMenu()
	: BaseMenu(GameManager::SINGLE_PLAYER_MENU),
	classic_mode_button("button_classic_mode"),
	time_attack_button("button_time_attack")
{
	int width = game_manager->get_width(); 
	int height = game_manager->get_height();

	qreal step = 0.15;
	qreal first_button = 0.4;

	classic_mode_button.set_center(width/2, (first_button + 0*step)*height);
	time_attack_button.set_center(width/2, (first_button + 1*step)*height);

	buttons["classic_mode"] = &classic_mode_button;
	buttons["dynamic_mode"] = &time_attack_button;

	printf("Single player menu initiated!\n");
}

void SinglePlayerMenu::move_button_up(int id)
{
	if(classic_mode_button.get_hovered())
	{
		SingleClassicMode *single_classic = new SingleClassicMode();

		emit change_state(single_classic);

		return;
	}
	else if(time_attack_button.get_hovered())
	{
		SingleTimeAttack *time_attack = new SingleTimeAttack();

		emit change_state(time_attack);

		return;
	}
}