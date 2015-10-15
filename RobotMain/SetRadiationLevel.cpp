/** Command to set the radiation level of the robot
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "SetRadiationLevel.h"

/** Constructor **/
SetRadiationLevel::SetRadiationLevel(Robot* robot, int radiationLevel) 
	: Command("SetRadiationLevel"), _radLevel(radiationLevel), _robot(robot) {
}

/** Set the robot radiation level **/
void SetRadiationLevel::initialize() {
	_robot->setRadLevel(_radLevel);
}

void SetRadiationLevel::execute() {}

void SetRadiationLevel::end() {}

/** Simple command that finishes instantly **/
bool SetRadiationLevel::isFinished() {
	return true;
}