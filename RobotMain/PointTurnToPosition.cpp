#include "PointTurnToPosition.h"

/* Constructor */
/**
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurnToPosition::PointTurnToPosition(float turn, int duration, int *currentPos, int *nextPos, bool sideA) : Command("PointTurnToPosition") {
	curie = Robot::getInstance();
	deltaPos = *nextPos-*currentPos;
	if (deltaPos != 0) {
		_turn = -1*abs(turn)*deltaPos/abs(deltaPos);
		_duration = duration;
	} else {
		_turn = turn;
		_duration = duration;
	}
	
}

void PointTurnToPosition::initialize() {
	curie->drivetrain.initialize();
}

void PointTurnToPosition::execute() {
	curie->drivetrain.pointTurn(_turn);
}

void PointTurnToPosition::end() {
	curie->drivetrain.stop();
}

bool PointTurnToPosition::isFinished() {
	return getTime() > _duration; 
}
