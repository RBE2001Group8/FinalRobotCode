/** Class for a Radiation Indicator LED
  * on the robot for signaling radiation.
  **/
#include "RadiationIndicator.h"


/** Constructor
  * @param pin Pin for the LED
  * @param period Total period of the blink patter
  **/
RadiationIndicator::RadiationIndicator(int pin, int period) : _ledPin(pin), _period(period) {
	_onTime = period/8;
	shouldBlink = false;
}

/** Initialize the LED, and set the output
  * High so that it can be verified that it
  * is plugged in.
  **/
void RadiationIndicator::initialize() {
	pinMode(_ledPin, OUTPUT);
	digitalWrite(_ledPin, HIGH);
}

/** Updates the current state of the LED
  * based on the time, and if it should be 
  * blinking
  **/
void RadiationIndicator::update() {
	//Check if the light should be blinking
	if(shouldBlink) {
		//Get the current time in the period
		long periodIime = millis() % _period;
		//Blink a heartbeat like pattern
		if((periodIime < _onTime) ||
		   ((periodIime > 2*_onTime) && (periodIime < 3*_onTime))) {
			digitalWrite(_ledPin, HIGH);
		} else {
			digitalWrite(_ledPin, LOW);
		}
	} else {
		digitalWrite(_ledPin, LOW);
	}
}

/** Set the LED to blink
  **/
void RadiationIndicator::setBlink() {
	shouldBlink = true;
}

/** Set the LED to not blink
  **/
void RadiationIndicator::setNotBlink() {
	shouldBlink = false;
}