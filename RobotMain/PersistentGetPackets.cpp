/** Command that continuously gets and interprets packets from the
  * field computer.  This command is persistent and will never end
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "PersistentGetPackets.h"

/** Constructor **/
  PersistentGetPackets::PersistentGetPackets() : Command("PersistentGetPackets") {

  }

/** Initialize the command by getting a reference to the reactor link
  **/
void PersistentGetPackets::initialize() {
	rLink = Robot::getInstance()->reactorLink;
}

/** Continuously get packets from the Bluetooth connection
  **/
void PersistentGetPackets::execute() {
	rLink->getPacket();
}

/** Nothing to do for end, since this command never ends **/
void PersistentGetPackets::end() {

}

/** Alwayts return false so that the command is persistent **/
bool PersistentGetPackets::isFinished() {
	return false;
}