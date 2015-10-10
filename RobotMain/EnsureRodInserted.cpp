#include "EnsureRodInserted.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
EnsureRodInserted::EnsureRodInserted(float speed, bool sideA) : Command("EnsureRodInserted") {
	_speed = speed;
	_sideA = sideA;
	curie = Robot::getInstance();
}

void EnsureRodInserted::initialize() {
	_bitmask = curie->reactorLink->getSupplyAvailabilityByte();
	closestStorage = curie->tubeProcessor->getFreshRodTube(_bitmask, _sideA);
}

void EnsureRodInserted::execute() {
	curie->drivetrain->drive(_speed, 0.0);
}

void EnsureRodInserted::end() {
	curie->drivetrain->stop();
}

bool EnsureRodInserted::isFinished() {
	return curie->alignmentDetector->isAligned() || ((curie->currentPos-closestStorage) != 0); 
}
