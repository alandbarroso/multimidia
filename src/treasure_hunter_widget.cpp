#include "treasure_hunter_widget.h"

#include <QPainter>

TreasureHunterWidget::TreasureHunterWidget(QWidget *parent, int width, int height, PSMoveControllerThread* controller)
    : QWidget(parent)
{
    resize(width, height);

    game_manager->init(width, height, controller);
}

void TreasureHunterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    game_manager->update();

    game_manager->paint_screen(this);

}

void TreasureHunterWidget::update_screen()
{
    update();
}