/** Command to wait for a certain amount of time
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "WaitTime.h"

/* Constructor 
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

/** Command if finished when the duration has elapsed **/
bool WaitTime::isFinished() {
	return getTime() > _duration;
}
