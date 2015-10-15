/** Line follow over the appropriate amount of lines given the
  * robot's current position and desired position relative to 
  * the storage/supply tubes.
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "LineFollowOverLines.h"

/* Constructor */
/** Line follows, counting lines until the robot is at the position specified in newPos parameter, based on the inital position of the robot
 * @param speed Linefollowing speed
 * @param drive Drivetrain object to use for driving, must be initialized
 * @param currentPos Position of robot on the field at the beginning of the command
 * @param newPos Position the robot should be at when the command finishes
 **/
LineFollowOverLines::LineFollowOverLines(float speed, bool sideA) : PausableCommand("LineFollowOverLines"){
	_speed = speed;
	curie = Robot::getInstance();
	_sideA = sideA;
}

void LineFollowOverLines::initialize() {
	_bitmask = curie->reactorLink->getSupplyAvailabilityByte();
	linesToCross = abs(curie->tubeProcessor->getFreshRodTube(_bitmask, _sideA) - curie->currentPos);
	lastCrossTime = getTime();
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowOverLines::execute() {
	curie->drivetrain->drive(_speed, 0.08*curie->lineTracker->lineError());
	if (curie->lineTracker->isAtCross()) {
		//Check if it was not previously on the line, and has surpassed the time heuristic
		if (!onLine && (getTime() - lastCrossTime) > 400) {
			linesCrossed++;
			lastCrossTime = getTime();
		}
		onLine = true;
	} else {
		onLine = false;
	}
}

void LineFollowOverLines::end() {
	curie->drivetrain->stop();
}

/** Command has finished when it has crossed the appropriate
  * amount of lines or just needs to go to the next line
  **/
bool LineFollowOverLines::isFinished() {
	return (linesCrossed == linesToCross) || (linesToCross == 1); 
}

/** Stop the drivetrain while paused **/
void LineFollowOverLines::onPause() {
	curie->drivetrain->stop();
}

/** Do nothing special on resume **/
void LineFollowOverLines::onResume() {}
