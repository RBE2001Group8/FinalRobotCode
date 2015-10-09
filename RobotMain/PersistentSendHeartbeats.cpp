/** Command that sends Heartbeat messages to the Field Controller
  * periodically.  This command is persistent, and will never end
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "PersistentSendHeartbeats.h"

/** Constructor
  **/
PersistentSendHeartbeats::PersistentSendHeartbeats() : Command("PersistentSendHeartbeats") {
}

/** Initialize the command by getting a reference to the reacto
  * link and instantiating a new ElapsedTimer
  **/
void PersistentSendHeartbeats::initialize() {
	rLink = Robot::getInstance()->reactorLink;
	hbTimer = *(new ElapsedTimer());
}

/** Continue to send heartbeat messages periodically with the 
  * time between each message set by the "period" member variable
  **/
void PersistentSendHeartbeats::execute() {
	//Send a heartbeat message after the set time has elapsed
	if(hbTimer.getTimeMillis() > period) {
		rLink->sendHeartbeat();
		hbTimer.resetTimer();
	}
}

/** Nothing to do for end, since this command never ends
  **/
void PersistentSendHeartbeats::end() {
	
}

/** Always return true so that the command is persistent
  **/
bool PersistentSendHeartbeats::isFinished() {
	return false;
}