#include "PointTurnToLine.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurnToLine::PointTurnToLine(float turn) : Command("PointTurnToLine") {
	_turn = turn;
	curie = Robot::getInstance();
}

void PointTurnToLine::initialize() {
}

void PointTurnToLine::execute() {
<<<<<<< HEAD
	curie->drivetrain.pointTurn(_turn);
	onLine = (abs(curie->lineTracker.lineError()) > 8) | onLine;
=======
	curie->drivetrain->pointTurn(_turn);
	onLine = (abs(lineTracker.lineError()) > 8) | onLine;
>>>>>>> refs/remotes/origin/master
}

void PointTurnToLine::end() {
	curie->drivetrain->stop();
}

bool PointTurnToLine::isFinished() {
	return curie->lineTracker.centerOnLine() && onLine; 
}
