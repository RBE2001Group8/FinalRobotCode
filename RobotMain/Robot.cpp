
#include "Robot.h"

Robot* Robot::instance = NULL;

/* Constructor */
Robot::Robot() {}

/** Gets the Singleton instance of this robot.
  * @return Pointer to the Robot object
  **/
Robot* Robot::getInstance() {
	if(instance == NULL) {
		instance = new Robot();
	}
	return instance;
}

/** Calls initialize methods for all subsystems
  **/
void Robot::initializeSubsystems() {
	initializePauseTimer();
	drivetrain.initialize();
	button.initialize();
	roller.initialize();
	radInd->initialize();
}

/** Set the radiation level for the robot
  * when the robot is carying an unshielded rod
  **/
void Robot::setRadLevel(int newRadLevel) {
	radLevel = newRadLevel;
}

/** Get the radiation level for the robot
  **/
int Robot::getRadLevel() {
	return radLevel;
}
