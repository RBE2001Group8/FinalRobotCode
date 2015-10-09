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
	curie = Robot::getInstance();
}

void Drive::initialize() {
	curie->drivetrain.initialize();
}

void Drive::execute() {
	curie->drivetrain.drive(_speed, _turn);

}

void Drive::end() {
	curie->drivetrain.stop();
}

bool Drive::isFinished() {
	return getTime() > _duration; 
}
