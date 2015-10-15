#include "StopEverything.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
StopEverything::StopEverything() : Command("StopEverything") {
	curie = Robot::getInstance();
}

void StopEverything::initialize() {
	curie->drivetrain->stop();
	curie->roller->stop();
}

void StopEverything::execute() {}

void StopEverything::end() {}

/** Command is finished if the rod is detected to be fully inserted,
  * or if the robot as driven up to the alignment post
  **/
bool StopEverything::isFinished() {
	return true; 
}
