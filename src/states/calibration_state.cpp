#include <QPainter>
#include <QImage>
#include <QPoint>

#include "calibration_state.h"
#include "main_menu.h"

CalibrationState::CalibrationState()
	: GameState("Calibration State")
{
	int width = game_manager->get_width();
	int height = game_manager->get_height();

	this->black_screen = QImage(width, height, QImage::Format_RGB888);
	this->black_screen.fill(QColor(0, 0, 0, 255));

	this->calibrating_text = QImage(":/assets/calibrating_text.png");
	this->source_rect = QRectF(0, 0, this->calibrating_text.width(), this->calibrating_text.height());

	qreal screen_width_scale = 0.8;
	qreal scale_factor = screen_width_scale*width/this->calibrating_text.width();
	this->target_rect = QRectF(0, 0, width*screen_width_scale, scale_factor*this->calibrating_text.height());
	this->target_rect.moveCenter(QPoint(width/2, height/2));
}

void CalibrationState::update()
{

}

void CalibrationState::paint_screen_camera(QWidget* screen, QImage* camera_image)
{

}

void CalibrationState::paint_screen(QWidget *screen)
{
	QPainter painter(screen);

	painter.drawImage(0, 0, this->black_screen);

	painter.drawImage(this->target_rect, this->calibrating_text, this->source_rect);
}

void CalibrationState::calibration_finished()
{
	MainMenu *main_menu = new MainMenu();

	emit change_state(main_menu);

	return;
}