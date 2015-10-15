/** Command to move the rollers to spit out the rod for the given amount of time
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "RollerSpit.h"

/** Constructor 
 * @param duration Length of time in milliseconds to outtake for
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

/** Command has finished when the amount of time has elapsed **/
bool RollerSpit::isFinished() {
	return getTime() > _duration; 
}

/** Stop the rollers when paused **/
void RollerSpit::onPause() {
	curie->roller->stop();
}

/** Nothing special on resume **/
void RollerSpit::onResume() {}
