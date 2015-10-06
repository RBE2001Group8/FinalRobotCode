#include "PointTurnToLine.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurnToLine::PointTurnToLine(float turn, Drivetrain drive) : Command("PointTurnToLine"), drivetrain(drive) {
	_turn = turn;
}

void PointTurnToLine::initialize() {
	drivetrain.initialize();
	Serial.begin(9600);
}

void PointTurnToLine::execute() {
	drivetrain.pointTurn(_turn);
}

void PointTurnToLine::end() {
	drivetrain.stop();
}

bool PointTurnToLine::isFinished() {
	return abs(lineTracker.lineError()) > 8; 
}