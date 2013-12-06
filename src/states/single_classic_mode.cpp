#include <QPainter>
#include <QImage>
#include <QPoint>
#include <QtCore/qmath.h>

#include "single_classic_mode.h"
#include "congratulations.h"

SingleClassicMode::SingleClassicMode()
	: GameState(GameManager::SINGLE_CLASSIC_MODE)
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

	min_distance_obstacles = 100;

	obstacle_hearing_sound = 150;

	nb_barriers = 5;
	for(int i = 0; i < nb_barriers; i++)
	{
		SpacePoint p;
		do
		{
			p.x = qrand() % (game_manager->get_width() - 50) + 25;
			p.y = qrand() % (game_manager->get_height() - 40) + 20;
			p.z = (qrand() % 100) + 30;
		} while(qSqrt((p.x - objective.x)*(p.x - objective.x) + (p.y - objective.y)*(p.y - objective.y) + (p.z - objective.z)*(p.z - objective.z)) < min_distance_obstacles);

		printf("Barrier %d: X: %d, Y: %d, Z: %d\n", i, p.x, p.y, p.z);

		barriers.append(p);
	}

	distance_to_damage = 50;

	set_beep = 0;

	taken_damage = 0;

	penalty = 3000;
	score = 2000 + nb_barriers*penalty;
	lost_by_time = score/120000.0;

	score_timer.start();
}

SingleClassicMode::~SingleClassicMode()
{

}

void SingleClassicMode::init()
{
	emit stop_music();

	emit change_sound_volume(1.0);
}

void SingleClassicMode::update()
{
	score -= lost_by_time*score_timer.elapsed();
	if(score < 0)
		score = 0;
	score_timer.restart();

	if(taken_damage)
	{
		emit set_change_color(0);

		taken_damage = 0;
	}

	current_distance = 999;
	for(int i = 0; i < barriers.size(); i++)
	{
		qreal dist = qSqrt((x - barriers[i].x)*(x - barriers[i].x) + (y - barriers[i].y)*(y - barriers[i].y) + (z - barriers[i].z)*(z - barriers[i].z));

		if(dist < current_distance)
		{
			current_distance = dist;
		}

		if(dist < distance_to_damage)
		{
			emit set_color(255, 0, 0);

			emit set_change_color(1);

			emit set_vibration(255);

			emit set_change_vibration(1);

			emit change_sound_volume(1.0);

			emit play_damage();

			score -= penalty;
			if(score < 0)
				score = 0;

			barriers.removeAt(i);

			taken_damage = 1;

			return;
		}
	}

	/* Calculate the distance between the objective to the contoller */
	qreal distance = qSqrt((x - objective.x)*(x - objective.x) + (y - objective.y)*(y - objective.y) + (z - objective.z)*(z - objective.z));

	printf("X: %d, Y: %d, Z: %d\n", x, y, z);
	printf("Distance: %f\n", distance);
	printf("Score: %d\n", score);

	printf("Time elapsed: %d\n", winning_timer.elapsed());

	if(this->have_won && (winning_timer.elapsed() >= 2000))
	{
		Congratulations *congratulations = new Congratulations(score);

		emit change_state(congratulations);

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

				emit change_sound_volume(1.0);
				
				emit play_winning();
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

void SingleClassicMode::paint_screen_camera(QWidget* screen, QImage* camera_image)
{
	QPainter painter(screen);

	painter.drawImage(0, 0, camera_image->rgbSwapped().mirrored(true, false));
}

void SingleClassicMode::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

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

	painter.drawText(rect, Qt::AlignLeft, str_score);
}

void SingleClassicMode::position(int id, int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void SingleClassicMode::trigger_pressed(int id, qreal trigger)
{
	if(have_won)
	{
		emit change_sound_volume(1.0);
	}
	else
	{
		/* Check if the trigger is fully pressed */
		if(trigger/255.)
		{
			if(current_distance < obstacle_hearing_sound)
			{
				emit change_sound_volume(1.5*(obstacle_hearing_sound - current_distance)/obstacle_hearing_sound);

				if(!set_beep)
				{
					set_beep = 1;

					emit play_beep();
				}
			}
		}
		else
		{
			emit change_sound_volume(1.0);

			if(set_beep)
			{
				set_beep = 0;

				stop_music();
			}

			return;	
		}
	}
}