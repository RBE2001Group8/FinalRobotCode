#include <Arduino.h>
#include "ElapsedTimer.h"

ElapsedTimer::ElapsedTimer() {
	startTimeMillis = millis();
	startTimeMicros = micros();
}

unsigned long ElapsedTimer::getTimeMillis() {
	return millis() - startTimeMillis;
}

unsigned long ElapsedTimer::getTimeMicros() {
	return micros() - startTimeMicros;
}

void ElapsedTimer::resetTimer() {
	startTimeMillis = millis();
	startTimeMicros = micros();
}
