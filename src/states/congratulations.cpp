#include <QPainter>
#include <QImage>
#include <QPoint>
#include <QtCore/qmath.h>

#include "congratulations.h"
#include "main_menu.h"

Congratulations::Congratulations(int points)
	: GameState(GameManager::CONGRATULATIONS)
{
	int width = game_manager->get_width();
	int height = game_manager->get_height();

	printf("Congratulations initiated!\n");

	this->points = points;

	for(int i = 0; i < 256; i++) color_table.push_back(qRgb(i,i,i));

	this->congratulations = QImage(":/assets/congratulations.png");
	this->source_rect = QRectF(0, 0, this->congratulations.width(), this->congratulations.height());

	qreal screen_width_scale = 0.8;
	qreal scale_factor = screen_width_scale*width/this->congratulations.width();
	this->target_rect = QRectF(0, 0, width*screen_width_scale, scale_factor*this->congratulations.height());
	this->target_rect.moveCenter(QPoint(width/2, height/2));
}

void Congratulations::init()
{
	emit change_sound_volume(1.0);

	emit play_cheering();
}

void Congratulations::update()
{
	emit set_color(0, 255, 0);

	emit set_change_color(1);

	emit set_change_vibration(0);
}

void Congratulations::paint_screen_camera(QWidget* screen, QImage* camera_image)
{
	QPainter painter(screen);

	QImage aux_image = camera_image->rgbSwapped().mirrored(true, false).convertToFormat(QImage::Format_Indexed8);
	aux_image.setColorTable(color_table);

	painter.drawImage(0, 0, aux_image);	
}

void Congratulations::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	int width = game_manager->get_width();
	int height = game_manager->get_height();

	painter.drawImage(this->target_rect, this->congratulations, this->source_rect);

	QPen pen;
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(5);
	pen.setColor(QColor(246, 137, 42));
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);

	QFont font("Times", 17, QFont::Bold);

	painter.setPen(pen);
	painter.setFont(font);

	QRectF rect = QRectF(0, 0, 300, 60);
	rect.moveCenter(QPointF(width/2, height/2 + 60));

	QString str_score = QString("SCORE: %1").arg(points);

	painter.drawText(rect, Qt::AlignCenter, str_score);
}

void Congratulations::move_button_up(int id)
{
	MainMenu *main_menu = new MainMenu();

	emit set_change_color(0);

	emit change_state(main_menu);

	return;
}