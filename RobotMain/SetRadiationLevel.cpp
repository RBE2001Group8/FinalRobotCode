/** Command to set the radiation level of the robot
  **/

#include "SetRadiationLevel.h"

/** Constructor
  **/
SetRadiationLevel::SetRadiationLevel(Robot* robot, int radiationLevel) 
	: Command("SetRadiationLevel"), _radLevel(radiationLevel), _robot(robot) {
}

/** Nothing to initialize
  **/
void SetRadiationLevel::initialize() {
	_robot->setRadLevel(_radLevel);
}

/** Set the robot radiation level
  **/
//#TODO might need to move to initialize for faster execution
// Does this take 2 cycles to fully complete?
void SetRadiationLevel::execute() {
}

/** Nothing to clean up
  **/
void SetRadiationLevel::end() {

}

bool SetRadiationLevel::isFinished() {
	return true;
}