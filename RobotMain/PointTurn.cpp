/** Command to make the robot do a zero radius turn at the given speed
  * (with direction) for the given amount of time.
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "PointTurn.h"

/** Constructor
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurn::PointTurn(float turn, int duration) : PausableCommand("PointTurn") {
	_turn = turn;
	_duration = duration;
	curie = Robot::getInstance();
}

void PointTurn::initialize() {}

void PointTurn::execute() {
	curie->drivetrain->pointTurn(_turn);
}

void PointTurn::end() {
	curie->drivetrain->stop();
}

/** Command is finished when the appropriate amount of time has elapsed **/
bool PointTurn::isFinished() {
	return getTime() > _duration; 
}

/** Stop the drivetrain when paused **/
void PointTurn::onPause() {
	curie->drivetrain->stop();
}

/** Nothing special on resume **/
void PointTurn::onResume() {}
