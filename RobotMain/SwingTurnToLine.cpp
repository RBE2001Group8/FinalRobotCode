#include "SwingTurnToLine.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
SwingTurnToLine::SwingTurnToLine(float turn, Drivetrain drive) : Command("SwingTurnToLine"), drivetrain(drive) {
	_turn = turn;
}

void SwingTurnToLine::initialize() {
	Serial.begin(9600);
}

void SwingTurnToLine::execute() {
	drivetrain.swingTurn(0.07*lineTracker.lineError());
	
}

void SwingTurnToLine::end() {
	drivetrain.stop();
}

bool SwingTurnToLine::isFinished() {
	return lineTracker.lineError() == 0.0;// && onLine; 
}
