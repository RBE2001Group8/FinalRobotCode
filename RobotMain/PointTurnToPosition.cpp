#include "PointTurnToPosition.h"

/* Constructor */
/**
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurnToPosition::PointTurnToPosition(float turn, int duration, bool sideA) : Command("PointTurnToPosition") {
	curie = Robot::getInstance();
	_turn = turn;
	_duration = duration;
	_sideA = sideA;
}

void PointTurnToPosition::initialize() {
	_bitmask = curie->reactorLink.getSupplyAvailabilityByte();
	deltaPos = curie->tubeProcessor.getFreshRodTube(_bitmask, _sideA)-curie->currentPos;
	if (deltaPos != 0) {
		_turn = -1*abs(_turn)*deltaPos/abs(deltaPos);
	} 
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
