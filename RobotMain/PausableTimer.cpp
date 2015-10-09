
#include "PausableTimer.h"


/** Gets the time in milliseconds of the timer **/
unsigned long getPauseMillis() {
	//Disable interrupts to copy the variable
	unsigned long temp;
	uint8_t SaveSREG = SREG;	//Save the interrupt flags
	cli();						//Disable interrupts
	temp = _PAUSE_TIME_COUNT;	//Copy the value
	SREG = SaveSREG;			//Re-enable interrupts
	return temp;
}

/** Initialize the pausable timer **/
void initializePauseTimer() {
	Timer1.initialize(1000);  //1000 usec = 1 msec
	Timer1.attachInterrupt(incrementPauseTime);
}

/** Increment the milliseconds count
  * only if it is not paused
  **/
void incrementPauseTime() {
	if(!_SHOULD_PAUSE) {
		_PAUSE_TIME_COUNT++;
	}
}

/** Pause the timer **/
void pauseTimer() {
	_SHOULD_PAUSE = true;
}

void resumeTimer() {
	_SHOULD_PAUSE = false;
}