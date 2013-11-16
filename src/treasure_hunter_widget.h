#ifndef ORIENTATIONVIEW_H
#define ORIENTATIONVIEW_H

#include <QWidget>
#include <QImage>

#include "psmove_controller_thread.h"
#include "game_manager.h"

class TreasureHunterWidget : public QWidget
{
    Q_OBJECT
public:
    TreasureHunterWidget(QWidget *parent, int width, int height, PSMoveControllerThread* controller);

protected:
    void paintEvent(QPaintEvent *event);

private:
    GameManager gm;

public slots:
    void update_screen();
};

#endif
