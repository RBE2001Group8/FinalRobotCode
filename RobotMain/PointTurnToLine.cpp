/** Turn the robot with a zero turn radius to a line
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "PointTurnToLine.h"

/** Constructor 
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurnToLine::PointTurnToLine(float turn) : PausableCommand("PointTurnToLine") {
	_turn = turn;
	curie = Robot::getInstance();
}

void PointTurnToLine::initialize() {}

void PointTurnToLine::execute() {
	curie->drivetrain->pointTurn(_turn);
	onLine = (abs(curie->lineTracker->lineError()) > 8) | onLine;
}

void PointTurnToLine::end() {
	curie->drivetrain->stop();
}

/** Command is finished when the line tracker is on the 
  * center of the line
  **/
bool PointTurnToLine::isFinished() {
	return curie->lineTracker->centerOnLine() && onLine; 
}

/** Stop the drivetrain while paused **/
void PointTurnToLine::onPause() {
	curie->drivetrain->stop();
}

/** Nothing special on resume **/
void PointTurnToLine::onResume() {}
