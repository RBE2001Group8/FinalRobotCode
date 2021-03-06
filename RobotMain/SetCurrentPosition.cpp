/** Command to set the current position of the robot
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "SetCurrentPosition.h"

SetCurrentPosition::SetCurrentPosition(bool sideA) : Command("SetCurrentPosition"){
	curie = Robot::getInstance();
	_sideA = sideA;
}

void SetCurrentPosition::initialize() {
	_bitmask = curie->reactorLink->getStorageAvailabilityByte();
	tubeNum = curie->tubeProcessor->getStorageTube(_bitmask, _sideA);
	curie->currentPos = tubeNum;
}


void SetCurrentPosition::execute() {
}

void SetCurrentPosition::end() {
}

bool SetCurrentPosition::isFinished() {
	return true; 
}