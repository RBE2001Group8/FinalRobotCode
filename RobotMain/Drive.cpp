#include "Drive.h"

/* Constructor */
/**
 * @param speed Speed that the robot should drive at
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right. 0.0 is straight ahead
 * @param duration Length of time in milliseconds to drive for
 **/
Drive::Drive(float speed, float turn, int duration) : Command("Drive") {
	_speed = speed;
	_turn = turn;
	_duration = duration;
}

void Drive::initialize() {
	drivetrain.initialize();
	Serial.begin(9600);
}

void Drive::execute() {
	drivetrain.drive(_speed, _turn);
}

void Drive::end() {
	drivetrain.stop();
}

bool Drive::isFinished() {
	return getTime() < _duration; 
}
