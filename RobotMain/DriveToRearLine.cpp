#include "DriveToRearLine.h"

/* Constructor */
/** Backs drives until one of the line sensors on the back of the robot is on a black line
 * @param speed Speed that the robot should drive at
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right. 0.0 is straight ahead
 * @param drivetrain Drivetrain object to use for driving
 **/
DriveToRearLine::DriveToRearLine(float speed, float turn) : Command("Drive") {
	_speed = speed;
	_turn = turn;
	curie = Robot::getInstance();
}

void DriveToRearLine::initialize() {
	curie->drivetrain->initialize();
}

void DriveToRearLine::execute() {
	curie->drivetrain->drive(_speed, _turn);
}

void DriveToRearLine::end() {
	curie->drivetrain->stop();
}

bool DriveToRearLine::isFinished() {
	return curie->lineTracker->oneRearOnLine();
}
