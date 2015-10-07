#include "LineFollowOverLines.h"

/* Constructor */
/** Line follows, counting lines until the robot is at the position specified in newPos parameter, based on the inital position of the robot
 * @param speed Linefollowing speed
 * @param drive Drivetrain object to use for driving, must be initialized
 * @param currentPos Position of robot on the field at the beginning of the command
 * @param newPos Position the robot should be at when the command finishes
 **/
LineFollowOverLines::LineFollowOverLines(float speed, Drivetrain drive, int *currentPos, int *newPos) : Command("LineFollowOverLines"), drivetrain(drive){
	_speed = speed;
	linesToCross = abs(*newPos-*currentPos);
}

void LineFollowOverLines::initialize() {
	Serial.begin(9600);
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowOverLines::execute() {
	drivetrain.drive(_speed, 0.08*lineTracker.lineError());
	if (lineTracker.isAtCross()) {
		if (!onLine) {
			linesCrossed++;
		}
		onLine = true;
	} else {
		onLine = false;
	}
}

void LineFollowOverLines::end() {
	drivetrain.stop();
}

bool LineFollowOverLines::isFinished() {
	return linesCrossed == linesToCross; 
}