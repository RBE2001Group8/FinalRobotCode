#include "TurnToPosition.h"

/* Constructor */
/** Turns toward the next position based on where the robot is currently
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 * @param drivetrain Drivetrain object to use for driving
 * @param currentPos Position of robot on the field at the beginning of the command
 * @param nextPos Position the robot should be pointing toward when the command finishes
 **/
TurnToPosition::TurnToPosition(float turn, int duration, bool sideA) : Command("TurnToPosition") {
	curie = Robot::getInstance();
	_turn = abs(turn);
	_duration = duration;
}

void TurnToPosition::initialize() {
	deltaPos = curie->nextPos-curie->currentPos;
	if (deltaPos != 0) {
		_turn = -1*_turn*deltaPos/abs(deltaPos);
	} else { // Turning from perpendicular to the new fuel rod directly opposite
		_duration =* 0.75;
	}
}

void TurnToPosition::execute() {
	prevCenter = curie->lineTracker.centerOnLine();
	if (deltaPos != 0) {
		curie->drivetrain.swingTurn(_turn);
	} else {
		curie->drivetrain.pointTurn(_turn);
	}
}

void TurnToPosition::end() {
	curie->drivetrain.stop();
}

bool TurnToPosition::isFinished() {
	return (getTime() > 1000) && (curie->lineTracker.centerOnLine() && (!prevCenter)); 
}
