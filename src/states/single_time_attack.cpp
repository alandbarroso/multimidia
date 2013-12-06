#include <QPainter>
#include <QImage>
#include <QPoint>
#include <QtCore/qmath.h>

#include "single_time_attack.h"
#include "congratulations.h"

SingleTimeAttack::SingleTimeAttack()
	: GameState(GameManager::SINGEL_TIME_ATTACK)
{
	printf("Single classic mode initiated!\n");

	objective_vibration_distance = 150;

	distance_to_win = 35;

	have_won = 0;
	winning_timer.start();

	qsrand(QTime::currentTime().msec());
	objective.x = qrand() % (game_manager->get_width() - 50) + 25;
	objective.y = qrand() % (game_manager->get_height() - 40) + 20;
	objective.z = (qrand() % 100) + 30;

	printf("Current objective: X: %d, Y: %d, Z: %d\n", objective.x, objective.y, objective.z);

	score = 0;
	bonus = 1000;

	total_game_time = 60000;

	game_time.start();
}

SingleTimeAttack::~SingleTimeAttack()
{

}

void SingleTimeAttack::init()
{
	emit stop_music();

	emit play_time_attack();
}

void SingleTimeAttack::update()
{
	if(game_time.elapsed() > total_game_time)
	{
		Congratulations *congratulations = new Congratulations(score);

		emit change_state(congratulations);

		return;
	}

	/* Calculate the distance between the objective to the contoller */
	qreal distance = qSqrt((x - objective.x)*(x - objective.x) + (y - objective.y)*(y - objective.y) + (z - objective.z)*(z - objective.z));

	printf("X: %d, Y: %d, Z: %d\n", x, y, z);
	printf("Distance: %f\n", distance);
	printf("Score: %d\n", score);

	printf("Time elapsed: %d\n", winning_timer.elapsed());

	if(this->have_won && (winning_timer.elapsed() >= 2000))
	{
		SpacePoint point;

		score += bonus;
		bonus += 1000;

		do
		{
			point.x = qrand() % (game_manager->get_width() - 50) + 25;
			point.y = qrand() % (game_manager->get_height() - 40) + 20;
			point.z = (qrand() % 100) + 30;
		} while(qSqrt((point.x - objective.x)*(point.x - objective.x) + (point.y - objective.y)*(point.y - objective.y) + (point.z - objective.z)*(point.z - objective.z)) < objective_vibration_distance);

		objective.x = point.x;
		objective.y = point.y;
		objective.z = point.z;

		have_won = 0;

		emit set_change_color(0);

		return;
	}

	// If the distance is lower than the distance set we send a vibration signal
	if(distance < objective_vibration_distance)
	{
		if(distance < distance_to_win)
		{
			emit set_change_vibration(0);

			emit set_color(0, 255, 0);

			emit set_change_color(1);

			if(winning_timer.elapsed() >= 2000)
			{
				winning_timer.restart();

				this->have_won = 1;
			}
		}
		else
		{
			// We calculate the vibration percentage
			int vibration = (objective_vibration_distance - distance)/objective_vibration_distance*255;

			emit set_vibration(vibration);

			emit set_change_vibration(1);
		}
	}
	else
	{
		emit set_change_vibration(0);
	}

	return;

}

void SingleTimeAttack::paint_screen_camera(QWidget* screen, QImage* camera_image)
{
	QPainter painter(screen);

	painter.drawImage(0, 0, camera_image->rgbSwapped().mirrored(true, false));
}

void SingleTimeAttack::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	int width = game_manager->get_width(); 
	int height = game_manager->get_height();

	QPen pen;
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(5);
	pen.setColor(QColor(246, 137, 42));
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);

	QFont font("Times", 15, QFont::Bold);

	painter.setPen(pen);
	painter.setFont(font);

	QRectF rect = QRectF(0, 0, 300, 60);

	QString str_score = QString("SCORE: %1").arg(score);

	QRectF rect2 = QRectF(0, height - 30, 300, 60);

	QString str_time = QString("TIME: %1 s").arg((total_game_time - game_time.elapsed())/1000);

	painter.drawText(rect, Qt::AlignLeft, str_score);

	painter.drawText(rect2, Qt::AlignLeft, str_time);
}

void SingleTimeAttack::position(int id, int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}