#include <Arduino.h>
#include "ReactorLink.h"


//Constructor
ReactorLink::ReactorLink() {
	Serial3.begin(115200);
}

//Alternate Constructor that specifies the serial interface to use,
//team number, 
/*
ReactorLink::ReactorLink(HardwareSerial serialPort, uint8_t teamNum) {
  
  serialX = serialPort;
  serialX.begin(115200);
}
*

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

/** Get a packet from the Field Computer if there is one available.  If there
  * is not a packet available, it will not be processed.  If at least a minimum
  * size packet is available, the packet will only be processed if the full
  * packet is available based on the length byte.  If only part of the packet
  * is available, control will be returned the full packet will be processed
  * on the next call.
  * @return 1 if a packet was read, 0 if no packet was read, -1 if only a 
  * partial packet was received, and -2 if garbage data was cleared.
  **/
uint8_t ReactorLink::getPacket() {
  //Check if an entire packet is available
  if(Serial3.available() >= MIN_PACKET_SIZE) {
  	//Check for preceeding garbage data
    if(Serial3.peek() == PACKET_START_BYTE) {
      //Valid packet start byte.  Start reading data in.
      tempPacketBuff[0] = Serial3.read();   //Packet Start byte
      tempPacketBuff[1] = Serial3.read();   //Packet Length

      //Check if the rest of the packet is available, and busy wait until then
      while (Serial3.available() < (tempPacketBuff[1] -1)) {}

      //The rest of the packet is available, get the rest of the packet
      for(uint8_t i=0; i < (tempPacketBuff[1]-1); i++) {
        tempPacketBuff[2+i] = Serial3.read();
      }

      //Calculate the checksum
      /*
      uint8_t checksum=0;
      for(uint8_t i=1; i < tempPacketBuff[1]; i++) {
        checksum += tempPacketBuff[i];
      }
      checksum = 0xFF - checksum;

      //Check the checksum
      if(checksum == tempPacketBuff[tempPacketBuff[1]]) {
        //The packet was valid
        Serial.println("Valid Checksum");
      } else {
        //The packet was not valid
        Serial.println("Invalid Checksum");
      }
      */
      //Interpret the packet
      /*
      switch(tempPacketBuff[2]) {
        case PACKET_TYPE_STORAGE_AVAILABILITY:
          break;

        case PACKET_TYPE_SUPPLY_AVAILABILITY:
          break;

        case PACKET_TYPE_STOP_MOVEMENT:
          //Check if this message is intended for this robot
          if(tempPacketBuff[4] == ADDRESS_TEAM) {   //TODO is it necessary to check the source address?
            //Whoah!  Hold up now!
          }   
          break;

        case PACKET_TYPE_RESUME_MOVEMENT:
          //Check if this message is intended for this robot
          if(tempPacketBuff[4] == ADDRESS_TEAM) {
            //CHARGE!!!!
          }
          break;

        case PACKET_TYPE_RADIATION_ALERT:
          //Silly robot, radiation is only for humans...
          break;
        default:
          break;
      }
      */

      //Debug print the packet
      for(uint8_t j=0; j <= tempPacketBuff[1]; j++) {
        Serial.print(tempPacketBuff[j], HEX);
        Serial.print(",");
      }
      Serial.println("");

      //Success!
      return 1;
    } else {
      //Invalid packet start byte.  Clear buffer until the next valid start byte
      while(Serial3.peek() != PACKET_START_BYTE && Serial3.available()) {
        Serial.print("Removing Byte: ");
        Serial.println(Serial3.read(), HEX);
      }
      return -2;
    }
  }
}