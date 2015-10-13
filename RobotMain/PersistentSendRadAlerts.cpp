/** This command broadcasts Radiation Alerts periodically when
  * the robot is holding a rod.  Radiation Alerts for the appropriate
  * type of rod will be sent out.  This command is persistent, and will
  * never end.
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "PersistentSendRadAlerts.h"

/** Constructor **/
PersistentSendRadAlerts::PersistentSendRadAlerts() : Command("PersistentSendRadAlerts") {

}

/** Initialize the command by getting a reference to the reactor link,
  * the robot, and instantiating a new Elapsed Timer
  **/
void PersistentSendRadAlerts::initialize() {
	robot = Robot::getInstance();
	rLink = robot->reactorLink;
	alertTimer = *(new ElapsedTimer());
}

/** Send radiation alerts only every so often, and only send out the 
  * appropriate alert type when the robot has a rod.
  **/
void PersistentSendRadAlerts::execute() {
	//Decide to send packets periodically
	if(alertTimer.getTimeMillis() > period) {
		//Only send out the appropriate alerts
		if(robot->getRadLevel() == RAD_LEVEL_NEW) {
			rLink->sendRadiationAlertNew();
		} else if(robot->getRadLevel() == RAD_LEVEL_SPENT) {
			rLink->sendRadiationAlertSpent();
		}
		//Dont set alerts if neither condition is satisfied
		//Reset the timer so that this case gets executed periodically
		alertTimer.resetTimer();
	}
}

/** Nothing to do for ending, since this command is persistent **/
void PersistentSendRadAlerts::end() {

}

/** Always return false, since this command is persistent **/
bool PersistentSendRadAlerts::isFinished() {
	return false;
}