#include "AlignmentDetector.h"

AlignmentDetector::AlignmentDetector() {
	pinMode(12, INPUT_PULLUP);
}

/**
 * Reads limit switch on digital pin 12
 * @return Boolean True if sensor is pressed and robot is aligned
 **/

boolean AlignmentDetector::isAligned() {
	return !digitalRead(12); // Inverted because of pullup resistor
}