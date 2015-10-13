#include "RollerSuck.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
RollerSuck::RollerSuck(int duration) : PausableCommand("RollerSuck"){
	_duration = duration;
	curie = Robot::getInstance();
}

void RollerSuck::initialize() {
}

void RollerSuck::execute() {
	curie->roller->suck();
}

void RollerSuck::end() {
	curie->roller->stop();
}

bool RollerSuck::isFinished() {
	return getTime() > _duration; 
}

/** Stop the rollers when paused **/
void RollerSuck::onPause() {
	curie->roller->stop();
}

/** Nothing special on resume **/
void RollerSuck::onResume() {}