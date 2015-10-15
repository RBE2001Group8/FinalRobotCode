/** A handy abstraction for calculating the amount of time 
  * that has elapsed since it was last reset
  * Inspired by Qualcomm's ElapsedTimer
  * @author Jordan Burklund
  * @date Sept. 2015
  **/

#include <Arduino.h>
#include "ElapsedTimer.h"

/** Constructor **/
ElapsedTimer::ElapsedTimer() {
	startTimeMillis = millis();
	startTimeMicros = micros();
}

/** Get the amount of elapsed time in milliseconds
  * @return Amount of time since last reset in milliseconds
  **/
unsigned long ElapsedTimer::getTimeMillis() {
	return millis() - startTimeMillis;
}

/** Get the amount of elapsed time in microseconds
  * @return Amount of time since last reset in microseconds
  **/
unsigned long ElapsedTimer::getTimeMicros() {
	return micros() - startTimeMicros;
}

/** Reset the elapsed time back to 0 **/
void ElapsedTimer::resetTimer() {
	startTimeMillis = millis();
	startTimeMicros = micros();
}
