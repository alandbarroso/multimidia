#ifndef ORIENTATIONVIEW_H
#define ORIENTATIONVIEW_H

#include <QWidget>
#include <QImage>

#include "opencv2/core/core_c.h"

class PaintView : public QWidget
{
    Q_OBJECT
public:
    PaintView(QWidget *parent, int width, int height);
    ~PaintView();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QPixmap m_painting;
    QPixmap m_painting_backup;
    QPoint m_cursor[2];
    QColor m_color[2];
    QImage *m_image;

public slots:
    void newposition(int id, qreal scale, qreal x, qreal y, qreal trigger);
    void backup_frame();
    void restore_frame();
    void newcolor(int id, int r, int g, int b);
    void newimage(void *image);
};

#endif
