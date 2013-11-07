#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <QObject>

class GameManager : public QObject
{
public slots:
    void newposition(int id, qreal scale, qreal x, qreal y, qreal trigger);
    void backup_frame();
    void restore_frame();
    void newcolor(int id, int r, int g, int b);
    void newimage(void *image);
};

#endif