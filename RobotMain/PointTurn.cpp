#include "PointTurn.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurn::PointTurn(float turn, int duration) : Command("PointTurn") {
	_turn = turn;
	_duration = duration;
	curie = Robot::getInstance();
}

void PointTurn::initialize() {
}

void PointTurn::execute() {
	curie->drivetrain->pointTurn(_turn);
}

void PointTurn::end() {
	curie->drivetrain->stop();
}

bool PointTurn::isFinished() {
	return getTime() > _duration; 
}
