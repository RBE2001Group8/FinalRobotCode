
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
	drivetrain.initialize();
	button.initialize();
	roller.initialize();
}

