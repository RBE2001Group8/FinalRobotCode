#include "LineFollowToSwitch.h"

/* Constructor */
LineFollowToSwitch::LineFollowToSwitch(float speed, Drivetrain drive) : Command("LineFollowToSwitch"), drivetrain(drive) {
	_speed = speed;
}

void LineFollowToSwitch::initialize() {
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowToSwitch::execute() {
	drivetrain.drive(_speed, 0.08*lineTracker.lineError());
}

void LineFollowToSwitch::end() {
	drivetrain.stop();
}

bool LineFollowToSwitch::isFinished() {
	return alignmentDetector.isAligned(); // Is finished if limit switch is triggered
}
