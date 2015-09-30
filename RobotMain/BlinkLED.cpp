#include "BlinkLED.h"

/* Constructor */
BlinkLED::BlinkLED(unsigned long period) : Command("BlinkLED") {
	_period = period;
}

void BlinkLED::initialize() {
	pinMode(LEDPin, OUTPUT);
}

void BlinkLED::execute() {
	if(getTime() > _period/2) {
		digitalWrite(LEDPin, LOW);
	} else {
		digitalWrite(LEDPin, HIGH);
	}
}

void BlinkLED::end() {

}

bool BlinkLED::isFinished() {
	return getTime() > _period;
}