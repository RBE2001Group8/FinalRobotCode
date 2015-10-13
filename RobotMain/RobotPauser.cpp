#include "RobotPauser.h"

RobotPauser* RobotPauser::instance = NULL;
bool RobotPauser::paused = false;

/* Private Constructor */
RobotPauser::RobotPauser() {
}

/** Get an instance of the Robot Pauser
  * @return Pointer to the singleton instance
  **/
RobotPauser* RobotPauser::getInstance() {
	if(instance == NULL) {
		instance = new RobotPauser();
	}
	return instance;
}

/** Set the flag to pause the robot **/
void RobotPauser::pauseRobot() {
	paused = true;
	pauseTimer();
}

/** Set the flag to resume the robot **/
void RobotPauser::resumeRobot() {
	paused = false;
	resumeTimer();
}

/** Check if the flag is set to be paused
  * @return True if the robot is paused
  **/
bool RobotPauser::isPaused() {
	return paused;
}