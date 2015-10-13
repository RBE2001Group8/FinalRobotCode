#include "TurnToSupplyDirection.h"

/* Constructor */
/** Turns toward the next SupplyDirection based on where the robot is currently
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 * @param drivetrain Drivetrain object to use for driving
 * @param currentPos SupplyDirection of robot on the field at the beginning of the command
 * @param nextPos SupplyDirection the robot should be pointing toward when the command finishes
 **/
TurnToSupplyDirection::TurnToSupplyDirection(float turn, bool sideA) : PausableCommand("TurnToSupplyDirection") {
	curie = Robot::getInstance();
	_turn = abs(turn);
	_sideA = sideA;
}

void TurnToSupplyDirection::initialize() {
	_bitmask = curie->reactorLink->getSupplyAvailabilityByte();
	deltaPos = curie->tubeProcessor->getFreshRodTube(_bitmask, _sideA)-curie->currentPos;
	_turn = _turn*deltaPos/abs(deltaPos);
}

void TurnToSupplyDirection::execute() {
	prevCenter = curie->lineTracker->centerOnLine();
	curie->drivetrain->swingTurn(_turn);
	offLine = (!curie->lineTracker->isAtCross()) | offLine;
}

void TurnToSupplyDirection::end() {
	curie->drivetrain->stop();
}

bool TurnToSupplyDirection::isFinished() {
	return ((getTime() > 1250) && (curie->lineTracker->isAtCross()) && offLine) || (deltaPos==0); //&& (!prevCenter)))
}

/** Stop the robot while paused **/
void TurnToSupplyDirection::onPause() {
	curie->drivetrain->stop();
}

/** Nothing special on resume **/
void TurnToSupplyDirection::onResume() {}
