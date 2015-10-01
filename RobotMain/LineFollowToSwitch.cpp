#include "LineFollowToSwitch.h"

/* Constructor */
LineFollowToSwitch::LineFollowToSwitch(int speed) : Command("LineFollowToSwitch") {
	_speed = speed;
}

void LineFollowToSwitch::initialize() {

}

/** 
 * Commands the robot to follow the line at the specified speed
 **/
void LineFollowToSwitch::execute() {
	float error = map(lineTracker.lineError(), -15, 15, -1, 1);
	drivetrain.drive(_speed, error);
}

void LineFollowToSwitch::end() {
	drivetrain.stop();
}

bool LineFollowToSwitch::isFinished() {
	return alignmentDetector.isAligned(); // Is finished if limit switch is triggered
}
