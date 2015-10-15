/** Example command that blinks an LED once for the
  * given period.
  * @author Jordan Burklund
  * @date Sept. 2015
  **/

#include "BlinkLED.h"

/* Constructor */
BlinkLED::BlinkLED(unsigned long period) : Command("BlinkLED") {
	_period = period;
}

void BlinkLED::initialize() {
	pinMode(LEDPin, OUTPUT);
}

/** Turn the LED on for half of the period **/
void BlinkLED::execute() {
	if(getTime() > _period/2) {
		digitalWrite(LEDPin, LOW);
	} else {
		digitalWrite(LEDPin, HIGH);
	}
}

void BlinkLED::end() {

}

/** Command is finished when period has elapsed **/
bool BlinkLED::isFinished() {
	return getTime() > _period;
}