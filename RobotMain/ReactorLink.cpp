/** Class for handling the connection to the field computer
  * Assumes the bluetooth module is plugged into the RBE2001
  * Shield port for the bluetooth module.
  * @author Jordan Burklund
  * @date Sept. 2015
  **/

#include "ReactorLink.h"


//Constructor
ReactorLink::ReactorLink() {
	Serial3.begin(115200);
  pinMode(SERIAL3_RX_PIN, INPUT_PULLUP);
  pinMode(SERIAL3_TX_PIN, INPUT_PULLUP);
}

//#TODO Make a constructor that specifies the serial interface to use
//Alternate Constructor that specifies the serial interface to use,
//team number, 
/*
ReactorLink::ReactorLink(HardwareSerial serialPort, uint8_t teamNum) {
  
  serialX = serialPort;
  serialX.begin(115200);
}
*/

//#TODO use the HardwareSerial specified in the constructor
//e.g. linkSerial.write(xxx);
// for debugging: debugSerial.write(XXX);
/** Send a heartbeat packet to the Field Computer **/
void ReactorLink::sendHeartbeat() {
    Serial3.write(PACKET_START_BYTE);
    Serial3.write(PACKET_LENGTH_HEARTBEAT);
    Serial3.write(PACKET_TYPE_HEARTBEAT);
    Serial3.write(ADDRESS_TEAM);
    Serial3.write(ADDRESS_BROADCAST);
    Serial3.write(CHECKSUM_HEARTBEAT);
}

/** Send a Radiation Alert packet for a new rod to
  * the Field Computer **/
void ReactorLink::sendRadiationAlertNew() {
	Serial3.write(PACKET_START_BYTE);
	Serial3.write(PACKET_LENGTH_RADIATION_ALERT);
	Serial3.write(PACKET_TYPE_RADIATION_ALERT);
	Serial3.write(ADDRESS_TEAM);
	Serial3.write(ADDRESS_BROADCAST);
	Serial3.write(RADIATION_LEVEL_NEW_ROD);
	Serial3.write(CHECKSUM_RAD_ALERT_NEW);
}

/** Send a Radiation Alert packet for a spent rod to
  * the Field Computer **/
void ReactorLink::sendRadiationAlertSpent() {
	Serial3.write(PACKET_START_BYTE);
	Serial3.write(PACKET_LENGTH_RADIATION_ALERT);
	Serial3.write(PACKET_TYPE_RADIATION_ALERT);
	Serial3.write(ADDRESS_TEAM);
	Serial3.write(ADDRESS_BROADCAST);
	Serial3.write(RADIATION_LEVEL_SPENT_ROD);
	Serial3.write(CHECKSUM_RAD_ALERT_SPENT);
}

/** Get a packet from the Field Computer if there is one available.  If data
  * is not available, the method will exit.  If at least a minimum
  * size packet is available, the first two bytes (start, and length) will be read.
  * If the full packet is available based on the length byte, the rest of the packet
  * will be read in to the buffer.  The checksum will be verified, and then the data
  * will be processed.  If the amount of bytes for the full packet are not available,
  * it will return control, and wait until the next time it is called to interpret the packet
  * This also removes any garbage data that it finds between the end of a packet and the
  * start of another (if a packet header is corrupted, the entire packet will be discarded)
  * @return 1 if a packet was read, 0 if no packet was read, -1 if only a 
  * partial packet was received, and -2 if garbage data was cleared.
  **/
uint8_t ReactorLink::getPacket() {

  //Handle reading a parital packet or a full packet
  //Reads in the header only if it hasn't in a previous iteration
  if(!hasReadPartialPacket) {
    //Exit early if a packet is definitely not yet available
    if(Serial3.available() < MIN_PACKET_SIZE) {
      //Packet is not available
      return 0;
    }
    //Discard garbage data until the header is detected
    while(Serial3.peek() != PACKET_START_BYTE) {
      //Serial.println("Discarding data");
      Serial3.read();
    }
    //Check again if a packet might be available
    if(Serial3.available() < MIN_PACKET_SIZE) {
      //Packet is not available, exit early
      return 0;
    }
    //A packet is partially available, read the first two bytes
    tempPacketBuff[0] = Serial3.read();
    tempPacketBuff[1] = Serial3.read();
  }

  //Check if the rest of the data is available
  if(Serial3.available() < (tempPacketBuff[1] - 1)) {
    //Return control and set the flag for a partially read packet
    hasReadPartialPacket = true;
    return -1;
  }

  //Packet is available, clear the flag, and get the rest of the packet
  hasReadPartialPacket = false;
  for(uint8_t i=0; i < (tempPacketBuff[1]-1); i++) {
    tempPacketBuff[2+i] = Serial3.read();
  }

  //Calculate the checksum
  uint8_t checksum=0;
  for(uint8_t i=1; i < tempPacketBuff[1]; i++) {
    checksum += tempPacketBuff[i];
  }
  checksum = 0xFF - checksum;

  //Check the checksum, if not valid return an error and exit, discarding the packet
  if(checksum != tempPacketBuff[tempPacketBuff[1]]) {
    //Serial.print("Invalid Checksum: ");
    //Serial.println(checksum, HEX);
    return -1;
  }

  //Interpret the data
  switch(tempPacketBuff[2]) {
    //PACKET_TYPE_STORAGE_AVAILABILITY
    case 0x01:
      //Copy the storage availability byte
      storageAvailability = tempPacketBuff[5];
      //Serial.println("New Storage Packet");
      break;

    //PACKET_TYPE_SUPPLY_AVAILABILITY
    case 0x02:
      //Copy the supply availability byte
      supplyAvailability = tempPacketBuff[5];
      //Serial.println("New Supply Packet");
      break;

    //PACKET_TYPE_RADIATION_ALERT
    case 0x03:
      //Silly robot! Radiation is for humans!
      //probably from another robot.  Ignore it
      break;

    ///PACKET_TYPE_STOP_MOVEMENT
    case 0x04:
      //Check if the packet is addressed to this robot
      if(tempPacketBuff[4] == ADDRESS_TEAM) {
        //Set the flag to stop the robot
        shouldStop = true;
        pauseTimer();
        //Serial.println("#### Stop this robot ####");
      } else {
        //Serial.println("Stop for other robot");
      }
      break;

    //PACKET_TYPE_RESUME_MOVEMENT
    case 0x05:
      //Check if the packet is addressed to this robot
      if(tempPacketBuff[4] == ADDRESS_TEAM) {
        //Clear the stop flag to continue driving
        shouldStop = false;
        resumeTimer();
        //Serial.println("#### Resume this robot ####");
      } else {
        //Serial.println("Resume for other robot");
      }
      break;

    //PACKET_TYPE_ROBOT_STATUS
    case 0x06:
      //Probably from another robot.  Ignore it

    //PACKET_TYPE_HEARTBEAT
    case 0x07:
      //probably from another robot.  Ignore it
      break;
    default:
      break;
  }

  /*
  //Processing time information
  stopTime = micros();
  Serial.print("Processing Time: ");
  Serial.println(stopTime - startTime);

  //Debug print the packet
  for(uint8_t j=0; j <= tempPacketBuff[1]; j++) {
    Serial.print(tempPacketBuff[j], HEX);
    Serial.print(",");
  }
  Serial.println("");
  */

  //Packet successfully read!
  return 1;
}

/** Get the latest cached information on the Storage
  * availability.  Mask this byte the get information
  * on each supply tube.
  * @return The storage availability byte
  **/
uint8_t ReactorLink::getStorageAvailabilityByte() {
  return storageAvailability;
}

/** Get the latest cached information on the Supply
  * availability.  Mask this byte to get information
  * on each supply tube.
  * @return The supply availability byte
  **/
uint8_t ReactorLink::getSupplyAvailabilityByte() {
  return supplyAvailability;
}

/** Check if the robot should stop/resume based on the cached
  * info from the field computer
  **/
bool ReactorLink::robotShouldStop() {
  return shouldStop;
}