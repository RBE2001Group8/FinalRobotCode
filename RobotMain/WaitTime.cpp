#include "WaitTime.h"

/* Constructor */
/**
 * @param duration Length of time in milliseconds to wait for
 **/
WaitTime::WaitTime(int duration) : Command("WaitTime") {
	_duration = duration;
}

void WaitTime::initialize() {
}

void WaitTime::execute() {
}

void WaitTime::end() {
}

bool WaitTime::isFinished() {
	return getTime() > _duration;
}
