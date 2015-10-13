
#include "PausableCommand.h"

/** Constructor **/
PausableCommand::PausableCommand() : Command() {
	robotPauser = RobotPauser::getInstance();
}

/** Constructor with name **/
PausableCommand::PausableCommand(const String name) : Command(name) {
	robotPauser = RobotPauser::getInstance();
}


/** Get the time from the start of the command
  * @return time since the command has started in milliseconds
  **/
unsigned long PausableCommand::getTime() {
	return getPauseMillis() - this->startTime;
}

/* Background code for initialization */
void PausableCommand::_initialize() {
	running = true;
	startTime = getPauseMillis();
}

/** Execute an iteration of the command
  **/
bool PausableCommand::cycle() {
	bool finished = false;
	bool isNowPaused = robotPauser->isPaused(); 

	if(!initialized) {
		initialize();
		_initialize();
		initialized = true;
	} else if (isFinished()) {
		finished = true;
		end();
		_end();
	} else {
		if(isNowPaused && (isNowPaused != wasPaused)) {
			//Robot is paused, but wasn't last time
			onPause();
		} else if(!isNowPaused && (isNowPaused != wasPaused)) {
			//Robot is resumed, but wasn't last time
			onResume();
		} else if(!isNowPaused) {
			//Robot is not paused, and was not paused last time
			_execute();
			execute();
		} else {
			//Robot is paused.  Do nothing
		}
	}

	wasPaused = isNowPaused;
	return finished;
}
