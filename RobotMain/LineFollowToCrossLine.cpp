#include "LineFollowToCrossLine.h"

/* Constructor */
LineFollowToCrossLine::LineFollowToCrossLine(float speed) : PausableCommand("LineFollowToCrossLine"){
	_speed = speed;
	curie = Robot::getInstance();
}

void LineFollowToCrossLine::initialize() {}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowToCrossLine::execute() {
	curie->drivetrain->drive(_speed, 0.08*curie->lineTracker->lineError());
}

void LineFollowToCrossLine::end() {
	curie->drivetrain->stop();
}

/** Command is done when the LineTracker detects a cross **/
bool LineFollowToCrossLine::isFinished() {
	return curie->lineTracker->isAtCross(); // Is finished if outer sensors are on black (only happens if on a cross line)
}

/** Stop the drivetrain while paused **/
void LineFollowToCrossLine::onPause() {
	curie->drivetrain->stop();
}

/** Do nothing special on resume **/
void LineFollowToCrossLine::onResume() {}
