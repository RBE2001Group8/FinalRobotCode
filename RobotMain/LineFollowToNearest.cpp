#include "LineFollowToNearest.h"

/* Constructor */
/**
 * @param speed Linefollowing speed
 * @param drive Drivetrain object to use for driving, must be initialized
 * @param bitmask uses lowest 4 bits of char, assumes 1 indicates open storage slot
 * @param firstSide True if starting with storage slots on the left
 **/
LineFollowToNearest::LineFollowToNearest(float speed, Drivetrain drive, char bitmask, bool firstSide) : Command("LineFollowToNearest"), drivetrain(drive){
	_speed = speed;
	if (firstSide) {
		if (bitmask & 0x01) {
			linesToCross = 1;
		} else if (bitmask & 0x02) {
			linesToCross = 2;
		} else if (bitmask & 0x04) {
			linesToCross = 3;
		} else if (bitmask & 0x08) {
			linesToCross = 4;
		} else {
			linesToCross = 1; // Should never happen
		}
	} else {
		if (bitmask & 0x08) {
			linesToCross = 1;
		} else if (bitmask & 0x04) {
			linesToCross = 2;
		} else if (bitmask & 0x02) {
			linesToCross = 3;
		} else if (bitmask & 0x01) {
			linesToCross = 4;
		} else {
			linesToCross = 1; // Should never happen
		}
	}
}

void LineFollowToNearest::initialize() {
}

/** 
 * Commands the robot to follow the line at the specified speed
 *@param speed Speed that the robot should line follow at
 **/
void LineFollowToNearest::execute() {
	char toPrint[10];
	sprintf(toPrint, "%d", linesToCross);
	Serial.println(toPrint);
	drivetrain.drive(_speed, 0.08*lineTracker.lineError());
	if (lineTracker.isAtCross()) {
		if (!onLine) {
			linesCrossed++;
		}
		onLine = true;
	} else {
		onLine = false;
	}
}

void LineFollowToNearest::end() {
	drivetrain.stop();
}

bool LineFollowToNearest::isFinished() {
	return linesCrossed == linesToCross; // Is finished if outer sensors are on black (only happens if on a cross line)
}
