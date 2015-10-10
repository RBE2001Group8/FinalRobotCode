#include "DriveAndSquareOnLine.h"

/* Constructor */
/**
 * @param speed Speed that the robot should drive at
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right. 0.0 is straight ahead
 * @param duration Length of time in milliseconds to drive for
 **/
DriveAndSquareOnLine::DriveAndSquareOnLine(float speed, float turn) : Command("Drive") {
	_speed = speed;
	_turn = turn;
	curie = Robot::getInstance();
}

void DriveAndSquareOnLine::initialize() {
}

void DriveAndSquareOnLine::execute() {
	if (curie->lineTracker->leftRear() > 500) {
		_speed = 0;
		_turn = 0.5;
	} else if (curie->lineTracker->rightRear() > 500) {
		_speed = 0;
		_turn = -0.5;
	}
	curie->drivetrain->drive(_speed, _turn);
}

void DriveAndSquareOnLine::end() {
	curie->drivetrain->stop();
}

bool DriveAndSquareOnLine::isFinished() {
	return curie->lineTracker->rearOnLine();
}
