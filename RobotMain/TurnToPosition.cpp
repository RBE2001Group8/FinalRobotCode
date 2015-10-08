#include "TurnToPosition.h"

/* Constructor */
/** Turns toward the next position based on where the robot is currently
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 * @param drivetrain Drivetrain object to use for driving
 * @param currentPos Position of robot on the field at the beginning of the command
 * @param nextPos Position the robot should be pointing toward when the command finishes
 **/
TurnToPosition::TurnToPosition(float turn, int duration, int *currentPos, int *nextPos) : Command("TurnToPosition") {
	deltaPos = *nextPos-*currentPos;
	if (deltaPos != 0) {
		_turn = abs(turn)*deltaPos/abs(deltaPos);
		_duration = duration;
	} else {
		_turn = turn;
		_duration = duration*0.75;
	}
	curie = Robot::getInstance();
	
}

void TurnToPosition::initialize() {

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
