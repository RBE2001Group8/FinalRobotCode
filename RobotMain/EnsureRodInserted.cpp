/** Command to attempt to insert the rod if the robot missed the storage tube
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "EnsureRodInserted.h"

/** Constructor 
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
EnsureRodInserted::EnsureRodInserted(float speed, bool sideA) : PausableCommand("EnsureRodInserted") {
	_speed = speed;
	_sideA = sideA;
	curie = Robot::getInstance();
}

/** Check if the supply tube indicates that it was inserted **/
void EnsureRodInserted::initialize() {
	_bitmask = curie->reactorLink->getSupplyAvailabilityByte();
	closestStorage = curie->tubeProcessor->getFreshRodTube(_bitmask, _sideA);
}

/** Push the rod in **/
void EnsureRodInserted::execute() {
	curie->drivetrain->drive(_speed, 0.0);
	curie->roller->spit();
}

void EnsureRodInserted::end() {
	curie->drivetrain->stop();
	curie->roller->stop();
}

/** Command is finished if the rod is detected to be fully inserted,
  * or if the robot as driven up to the alignment post
  **/
bool EnsureRodInserted::isFinished() {
	return curie->alignmentDetector->isAligned() || ((curie->currentPos-closestStorage) != 0); 
}

/** Stop the drivetrain while paused **/
void EnsureRodInserted::onPause() {
	curie->drivetrain->stop();
}

/** Do nothing special on resume **/
void EnsureRodInserted::onResume() {}
