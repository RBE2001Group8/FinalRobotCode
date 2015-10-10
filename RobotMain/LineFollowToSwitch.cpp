#include "LineFollowToSwitch.h"

/** Line follows until the limit switch in the slot on the front of the robot is triggered
 * @param speed Linefollowing speed
 * @param drive Drivetrain object to use for driving, must be initialized
 **/
LineFollowToSwitch::LineFollowToSwitch(float speed) : Command("LineFollowToSwitch") {
	_speed = speed;
	curie = Robot::getInstance();
}

void LineFollowToSwitch::initialize() {
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowToSwitch::execute() {
	curie->drivetrain->drive(_speed, 0.08*curie->lineTracker->lineError());
}

void LineFollowToSwitch::end() {
	curie->drivetrain->stop();
}

bool LineFollowToSwitch::isFinished() {
	return curie->alignmentDetector->isAligned(); // Is finished if limit switch is triggered
}
