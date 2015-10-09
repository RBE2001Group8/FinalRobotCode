#include "SwingTurn.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
SwingTurn::SwingTurn(float turn, int duration) : Command("SwingTurn") {
	_turn = turn;
	_duration = duration;
	curie = Robot::getInstance();
}

void SwingTurn::initialize() {
	curie->drivetrain.initialize();
}

void SwingTurn::execute() {
	curie->drivetrain.swingTurn(_turn);
}

void SwingTurn::end() {
	curie->drivetrain.stop();
}

bool SwingTurn::isFinished() {
	return getTime() > _duration; 
}
