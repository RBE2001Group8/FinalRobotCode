#include "LineFollowOverLines.h"

/* Constructor */
/** Line follows, counting lines until the robot is at the position specified in newPos parameter, based on the inital position of the robot
 * @param speed Linefollowing speed
 * @param drive Drivetrain object to use for driving, must be initialized
 * @param currentPos Position of robot on the field at the beginning of the command
 * @param newPos Position the robot should be at when the command finishes
 **/
LineFollowOverLines::LineFollowOverLines(float speed, int currentPos, int newPos) : Command("LineFollowOverLines"){
	_speed = speed;
	linesToCross = abs(newPos-currentPos);
	curie = Robot::getInstance();
}

void LineFollowOverLines::initialize() {
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowOverLines::execute() {
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

void LineFollowOverLines::end() {
	curie->drivetrain.stop();
}

bool LineFollowOverLines::isFinished() {
	return linesCrossed == linesToCross; 
}