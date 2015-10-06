#include "LineFollowToCrossLine.h"

/* Constructor */
LineFollowToCrossLine::LineFollowToCrossLine(float speed, Drivetrain drive) : Command("LineFollowToCrossLine"), drivetrain(drive){
	_speed = speed;
}

void LineFollowToCrossLine::initialize() {
	drivetrain.initialize();
	Serial.begin(9600);
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowToCrossLine::execute() {
	drivetrain.drive(_speed, 0.08*lineTracker.lineError());
}

void LineFollowToCrossLine::end() {
	drivetrain.stop();
}

bool LineFollowToCrossLine::isFinished() {
	return lineTracker.isAtCross(); // Is finished if outer sensors are on black (only happens if on a cross line)
}
