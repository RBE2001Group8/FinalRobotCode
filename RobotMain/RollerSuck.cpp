#include "RollerSuck.h"

/* Constructor */
/**
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
RollerSuck::RollerSuck(int duration, Roller roll) : Command("RollerSuck"), roller(roll) {
	_duration = duration;
}

void RollerSuck::initialize() {
	roller.initialize();
}

void RollerSuck::execute() {
	roller.suck();
}

void RollerSuck::end() {
	roller.stop();
}

bool RollerSuck::isFinished() {
	return getTime() > _duration; 
}
