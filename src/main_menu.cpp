#include <QPainter>

#include "main_menu.h"

MainMenu::MainMenu()
	: test("button_base")
{
	test.set_position(50, 50);
}

void MainMenu::update()
{

}

void MainMenu::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	painter.drawImage(test.get_position(), test.get_button());
}