#include "PointTurn.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurn::PointTurn(float turn, int duration) : Command("PointTurn") {
	_turn = turn;
	_duration = duration;
}

void PointTurn::initialize() {
	drivetrain.initialize();
	Serial.begin(9600);
}

void PointTurn::execute() {
	drivetrain.pointTurn(_turn);
}

void PointTurn::end() {
	drivetrain.stop();
}

bool PointTurn::isFinished() {
	return getTime() > _duration; 
}
