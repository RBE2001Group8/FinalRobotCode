#include "RollerSpit.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
RollerSpit::RollerSpit(int duration) : PausableCommand("RollerSpit") {
	_duration = duration;
	curie = Robot::getInstance();
}

void RollerSpit::initialize() {}

void RollerSpit::execute() {
	curie->roller->spit();
}

void RollerSpit::end() {
	curie->roller->stop();
}

bool RollerSpit::isFinished() {
	return getTime() > _duration; 
}

/** Stop the rollers when paused **/
void RollerSpit::onPause() {
	curie->roller->stop();
}

/** Nothing special on resume **/
void RollerSpit::onResume() {}
