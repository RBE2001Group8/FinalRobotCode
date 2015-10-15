/** Command to drive the robot at the given speed
  * and turn rate for a given amount of time
  * @author Hans Johnson
  * @date Sept. 2015
  **/

#include "Drive.h"

/* Constructor */
/**
 * @param speed Speed that the robot should drive at
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right. 0.0 is straight ahead
 * @param duration Length of time in milliseconds to drive for
 **/
Drive::Drive(float speed, float turn, int duration) : PausableCommand("Drive") {
	_speed = speed;
	_turn = turn;
	_duration = duration;
	curie = Robot::getInstance();
}

void Drive::initialize() {}

/** Drive the drivetrain with the given
  * speed and turn rate parameters
  **/
void Drive::execute() {
	curie->drivetrain->drive(_speed, _turn);
}

void Drive::end() {
	curie->drivetrain->stop();
}

/** Command is finished when enough time has elapsed **/
bool Drive::isFinished() {
	return getTime() > _duration; 
}

/** Stop the drivetrain when paused **/
void Drive::onPause() {
	curie->drivetrain->stop();
}

/** Do nothing special on resume **/
void Drive::onResume() {}
