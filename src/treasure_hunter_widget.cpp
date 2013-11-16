#include "treasure_hunter_widget.h"

#include <QPainter>

TreasureHunterWidget::TreasureHunterWidget(QWidget *parent, int width, int height, PSMoveControllerThread* controller)
    : QWidget(parent),
      gm(width, height, controller)
{
    resize(width, height);
}

void TreasureHunterWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    gm.update();

    gm.paint_screen(this);

}

void TreasureHunterWidget::update_screen()
{
    update();
}