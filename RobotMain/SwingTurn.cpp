#include "SwingTurn.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
SwingTurn::SwingTurn(float turn, int duration, Drivetrain drive) : Command("SwingTurn"), drivetrain(drive) {
	_turn = turn;
	_duration = duration;
}

void SwingTurn::initialize() {
	drivetrain.initialize();
}

void SwingTurn::execute() {
	drivetrain.swingTurn(_turn);
}

void SwingTurn::end() {
	drivetrain.stop();
}

bool SwingTurn::isFinished() {
	return getTime() > _duration; 
}
