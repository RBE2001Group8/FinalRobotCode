#include "LineFollowToNearest.h"

/* Constructor */
LineFollowToNearest::LineFollowToNearest(float speed, Drivetrain drive, char bitmask) : Command("LineFollowToNearest"), drivetrain(drive){
	_speed = speed;
	if (bitmask & 0x01) {
		linesToCross = 1;
	} else if (bitmask & 0x02) {
		linesToCross = 2;
	} else if (bitmask & 0x04) {
		linesToCross = 3;
	} else if (bitmask & 0x08) {
		linesToCross = 4;
	} else {
		linesToCross = 1;
	}
}

void LineFollowToNearest::initialize() {
	Serial.begin(9600);
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
