#include "DriveAndSquareOnLine.h"

/* Constructor */
/**
 * @param speed Speed that the robot should drive at
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right. 0.0 is straight ahead
 * @param duration Length of time in milliseconds to drive for
 **/
DriveAndSquareOnLine::DriveAndSquareOnLine(float speed, float turn, Drivetrain drive) : Command("Drive"), drivetrain(drive) {
	_speed = speed;
	_turn = turn;
}

void DriveAndSquareOnLine::initialize() {
	drivetrain.initialize();
}

void DriveAndSquareOnLine::execute() {
	if (lineTracker.leftRear() > 500) {
		_speed = 0;
		_turn = 0.5;
	} else if (lineTracker.rightRear() > 500) {
		_speed = 0;
		_turn = -0.5;
	}
	drivetrain.drive(_speed, _turn);
}

void DriveAndSquareOnLine::end() {
	drivetrain.stop();
}

bool DriveAndSquareOnLine::isFinished() {
	return lineTracker.rearOnLine();
}
