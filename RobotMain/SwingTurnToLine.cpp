#include "SwingTurnToLine.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
SwingTurnToLine::SwingTurnToLine(float turn) : Command("SwingTurnToLine") {
	_turn = turn;
	curie = Robot::getInstance();
}

void SwingTurnToLine::initialize() {
}

void SwingTurnToLine::execute() {
	curie->drivetrain->pointTurn(_turn);
	onLine = (abs(curie->lineTracker->lineError()) > 8) | onLine;
}

void SwingTurnToLine::end() {
	curie->drivetrain->stop();
}

bool SwingTurnToLine::isFinished() {
	return curie->lineTracker->centerOnLine() && onLine; 
}
