#include "SwingTurnToPosition.h"

/* Constructor */
/**
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 **/
SwingTurnToPosition::SwingTurnToPosition(float turn, int duration, Drivetrain drive, int *currentPos, int *nextPos) : Command("SwingTurnToPosition"), drivetrain(drive) {
	deltaPos = nextPos-currentPos;
	_turn = -1*abs(turn)*deltaPos/abs(deltaPos);
	_duration = duration;
}

void SwingTurnToPosition::initialize() {
	drivetrain.initialize();
}

void SwingTurnToPosition::execute() {
	drivetrain.swingTurn(_turn);
}

void SwingTurnToPosition::end() {
	drivetrain.stop();
}

bool SwingTurnToPosition::isFinished() {
	return getTime() > _duration || !deltaPos; 
}
