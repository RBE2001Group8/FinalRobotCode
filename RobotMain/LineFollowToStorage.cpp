#include "LineFollowToStorage.h"

/* Constructor */
/** Line follows, counting lines until the robot is at the position specified in newPos parameter
 * @param speed Linefollowing speed
 * @param drive Drivetrain object to use for driving, must be initialized
 * @param newPos Position the robot should be at when the command finishes
 **/
LineFollowToStorage::LineFollowToStorage(float speed, int newPos, bool sideA) : Command("LineFollowToStorage"){
	_speed = speed;
	linesToCross = (sideA) ? newPos : (5-newPos);
	curie = Robot::getInstance();
}

void LineFollowToStorage::initialize() {
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowToStorage::execute() {
	curie->drivetrain.drive(_speed, 0.08*curie->lineTracker.lineError());
	if (curie->lineTracker.isAtCross()) {
		if (!onLine) {
			linesCrossed++;
		}
		onLine = true;
	} else {
		onLine = false;
	}
}

void LineFollowToStorage::end() {
	curie->drivetrain.stop();
}

bool LineFollowToStorage::isFinished() {
	return linesCrossed == linesToCross; 
}