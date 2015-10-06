#include "PointTurnToPosition.h"

/* Constructor */
/**
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurnToPosition::PointTurnToPosition(float turn, int duration, Drivetrain drive, int *currentPos, int *nextPos) : Command("PointTurnToPosition"), drivetrain(drive) {
	deltaPos = *nextPos-*currentPos;
	if (deltaPos != 0) {
		_turn = abs(turn)*deltaPos/abs(deltaPos);
		_duration = duration;
	} else {
		_turn = turn;
		_duration = duration;
	}
	
}

void PointTurnToPosition::initialize() {
	drivetrain.initialize();
	Serial.begin(9600);
}

void PointTurnToPosition::execute() {
	drivetrain.pointTurn(_turn);
}

void PointTurnToPosition::end() {
	drivetrain.stop();
}

bool PointTurnToPosition::isFinished() {
	return getTime() > _duration; 
}
