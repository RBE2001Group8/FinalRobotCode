/** Command to do a point turn to a position between the supply
  * and storage tubes
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "PointTurnToPosition.h"

/** Constructor 
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 **/
PointTurnToPosition::PointTurnToPosition(float turn, int duration, bool sideA) : PausableCommand("PointTurnToPosition") {
	curie = Robot::getInstance();
	_turn = turn;
	_duration = duration;
	_sideA = sideA;
}

void PointTurnToPosition::initialize() {
	//Calculate the direction to turn based on the current position, and closest Supply
	_bitmask = curie->reactorLink->getSupplyAvailabilityByte();
	deltaPos = curie->tubeProcessor->getFreshRodTube(_bitmask, _sideA)-curie->currentPos;
	if (deltaPos != 0) {
		_turn = -1*abs(_turn)*deltaPos/abs(deltaPos);
	} 
}

void PointTurnToPosition::execute() {
	curie->drivetrain->pointTurn(_turn);
}

void PointTurnToPosition::end() {
	curie->drivetrain->stop();
}

bool PointTurnToPosition::isFinished() {
	return getTime() > _duration; 
}

/** Stop the drivetrain while paused **/
void PointTurnToPosition::onPause() {
	curie->drivetrain->stop();
}

/** Nothing special on resume **/
void PointTurnToPosition::onResume() {}
