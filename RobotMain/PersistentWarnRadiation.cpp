/** Persistent command to blink the Radiation
  * Indicator when the robot is carrying an
  * exposed rod
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "PersistentWarnRadiation.h"

PersistentWarnRadiation::PersistentWarnRadiation(Robot *robot, RadiationIndicator *radInd) {
	_robot = robot;
	_radInd = radInd;
}

/** Do nothing for initialization.  Assumes
  * the RadiationIndicator is already initialized
  **/
void PersistentWarnRadiation::initialize() {

}

/** Check if the LED should be blinking, and update its
  * state.
  **/
void PersistentWarnRadiation::execute() {
	if(_robot->getRadLevel() == RAD_LEVEL_NEW || _robot->getRadLevel() == RAD_LEVEL_SPENT) {
		_radInd->setBlink();
	} else {
		_radInd->setNotBlink();
	}
	_radInd->update();
}

/** No final clean up to do
  **/
void PersistentWarnRadiation::end() {
}

/** Since this command is persistent, it is
  * never finished
  **/
bool PersistentWarnRadiation::isFinished() {
	return false;
}
