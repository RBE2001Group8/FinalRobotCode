#include "AlignmentDetector.h"

AlignmentDetector::AlignmentDetector() {
	pinMode(ALIGNMENT_SWITCH_PIN, INPUT_PULLUP);
}

/**
 * Reads limit switch on digital pin 12
 * @return Boolean True if sensor is pressed and robot is aligned
 **/

boolean AlignmentDetector::isAligned() {
	return !digitalRead(ALIGNMENT_SWITCH_PIN); // Inverted because of pullup resistor
}