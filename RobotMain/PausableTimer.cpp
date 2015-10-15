/** Implements a timer that outputs the time in milliseconds
  * since the program has started, but can be paused by 
  * setting a flag
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

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
	_SHOULD_PAUSE = false;
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

/** Unpause the timer **/
void resumeTimer() {
	_SHOULD_PAUSE = false;
}