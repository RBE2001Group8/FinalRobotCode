/** Command to turn toward the next position based on where the robot is currently
  * @author Hans Johnson
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "TurnToPosition.h"

/** Constructor
  * @param turn Turning rate of robot
  * @param duration Length of time in milliseconds to turn for
  * @param drivetrain Drivetrain object to use for driving
  * @param currentPos Position of robot on the field at the beginning of the command
  * @param nextPos Position the robot should be pointing toward when the command finishes
 **/
TurnToPosition::TurnToPosition(float turn, bool sideA) : PausableCommand("TurnToPosition") {
	curie = Robot::getInstance();
	_turn = abs(turn);
	_sideA = sideA;
}

void TurnToPosition::initialize() {
	_bitmask = curie->reactorLink->getSupplyAvailabilityByte();
	deltaPos = curie->tubeProcessor->getFreshRodTube(_bitmask, _sideA)-curie->currentPos;
	_turn = -1*_turn*deltaPos/abs(deltaPos);
}

void TurnToPosition::execute() {
	offLine = (curie->lineTracker->centerOnLine()) | offLine;
	curie->drivetrain->swingTurn(_turn);
}

void TurnToPosition::end() {
	curie->drivetrain->stop();
}

/** Command is finished when the linesensor detects the line,
  * has not detected the line previously, and a certain amount of time has elapsed
  **/
bool TurnToPosition::isFinished() {
	return ((getTime() > 750) && (curie->lineTracker->centerOnLine() && (offLine))) || (deltaPos==0); 
}

/** Stop the drivetrain when paused **/
void TurnToPosition::onPause() {
	curie->drivetrain->stop();
}

/** Nothing special on resume **/
void TurnToPosition::onResume() {}
