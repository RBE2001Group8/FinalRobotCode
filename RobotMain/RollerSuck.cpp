/** Command to make the rollers intake a rod for the given amount of time
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "RollerSuck.h"

/** Constructor
 * @param duration Length of time in milliseconds to intake for
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

/** Command has finished when the set amount of time has elapsed **/
bool RollerSuck::isFinished() {
	return getTime() > _duration; 
}

/** Stop the rollers when paused **/
void RollerSuck::onPause() {
	curie->roller->stop();
}

/** Nothing special on resume **/
void RollerSuck::onResume() {}