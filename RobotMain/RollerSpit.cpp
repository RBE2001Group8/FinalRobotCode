#include "RollerSpit.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
RollerSpit::RollerSpit(int duration) : Command("RollerSpit") {
	_duration = duration;
}

void RollerSpit::initialize() {
	roller.initialize();
	Serial.begin(9600);
}

void RollerSpit::execute() {
	roller.spit();
}

void RollerSpit::end() {
	roller.stop();
}

bool RollerSpit::isFinished() {
	return getTime() > _duration; 
}
