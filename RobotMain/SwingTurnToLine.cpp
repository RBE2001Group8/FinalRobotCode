/** Command to perform a swing turn until the linesensor
  * detects the line
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "SwingTurnToLine.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
SwingTurnToLine::SwingTurnToLine(float turn) : PausableCommand("SwingTurnToLine") {
	_turn = turn;
	curie = Robot::getInstance();
}

void SwingTurnToLine::initialize() {}

void SwingTurnToLine::execute() {
	curie->drivetrain->pointTurn(_turn);
	onLine = (abs(curie->lineTracker->lineError()) > 8) | onLine;
}

void SwingTurnToLine::end() {
	curie->drivetrain->stop();
}

/** Command is done when the line sensor detects the line,
  * and did not previously detect the line
  **/
bool SwingTurnToLine::isFinished() {
	return (curie->lineTracker->centerOnLine() && onLine);
}

/** Stop the drivetrain while paused **/
void SwingTurnToLine::onPause() {
	curie->drivetrain->stop();
}

/** Nothing special on resume **/
void SwingTurnToLine::onResume() {}
