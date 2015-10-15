/** Example Command to continuously blink an LED
  * with a given period.
  * @author Jordan Burklund
  * @date Sept. 2015
  **/ 
#include "PersistentBlink.h"

PersistentBlink::PersistentBlink(unsigned long period) : Command("PersistentBlink") {
	_period = period;
}

void PersistentBlink::initialize() {
	pinMode(LEDPin, OUTPUT);
}

void PersistentBlink::execute() {
	if((getTime() % _period) > _period/2) {
		digitalWrite(LEDPin, LOW);
	} else {
		digitalWrite(LEDPin, HIGH);
	}
}

void PersistentBlink::end() {

}

bool PersistentBlink::isFinished() {
	return false;
}