
#include "Robot.h"

Robot* Robot::instance = NULL;

/** Gets the Singleton instance of this robot.
  * @return Pointer to the Robot object
  **/
Robot* Robot::getInstance() {
	if(instance == NULL) {
		instance = new Robot();
	}
	return instance;
}

