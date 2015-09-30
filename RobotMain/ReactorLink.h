#ifndef REACTORLINK_H
#define REACTORLINK_H

#include <Arduino.h>

class ReactorLink {
public:
	ReactorLink();
	void sendHeartbeat();
	void sendRadiationAlertNew();
	void sendRadiationAlertSpent();
	uint8_t getPacket();
	uint8_t getStorageAvailabilityByte();
	uint8_t getSupplyAvailabilityByte();

private:
	//Constants for the Reactor Protocol
	const uint8_t MIN_PACKET_SIZE = 6;
	const uint8_t PACKET_START_BYTE = 0x5F;

	const uint8_t ADDRESS_TEAM = 8;
	const uint8_t ADDRESS_BROADCAST = 0;

	const uint8_t PACKET_LENGTH_HEARTBEAT = 5;
	const uint8_t PACKET_LENGTH_RADIATION_ALERT = 6;

	const uint8_t RADIATION_LEVEL_SPENT_ROD = 0x2C;
	const uint8_t RADIATION_LEVEL_NEW_ROD = 0xFF;

	const uint8_t PACKET_TYPE_STORAGE_AVAILABILITY = 0x01;
	const uint8_t PACKET_TYPE_SUPPLY_AVAILABILITY = 0x02;
	const uint8_t PACKET_TYPE_RADIATION_ALERT = 0x03;
	const uint8_t PACTET_TYPE_STOP_MOVEMENT = 0x04;
	const uint8_t PACKET_TYPE_RESUME_MOVEMENT = 0x05;
	const uint8_t PACKET_TYPE_ROBOT_STATUS = 0x06;
	const uint8_t PACKET_TYPE_HEARTBEAT = 0x07;

	const uint8_t CHECKSUM_HEARTBEAT = 0xFF - ( PACKET_LENGTH_HEARTBEAT+
                                            PACKET_TYPE_HEARTBEAT+
                                            ADDRESS_TEAM+
                                            ADDRESS_BROADCAST);
	const uint8_t CHECKSUM_RAD_ALERT_SPENT = 0xFF - ( PACKET_LENGTH_RADIATION_ALERT+
                                                        PACKET_TYPE_RADIATION_ALERT+
                                                        ADDRESS_TEAM+
                                                        ADDRESS_BROADCAST+
                                                        RADIATION_LEVEL_SPENT_ROD);
	const uint8_t CHECKSUM_RAD_ALERT_NEW = 0xFF - ( PACKET_LENGTH_RADIATION_ALERT+
                                                      PACKET_TYPE_RADIATION_ALERT+
                                                      ADDRESS_TEAM+
                                                      ADDRESS_BROADCAST+
                                                      RADIATION_LEVEL_NEW_ROD);

	//Buffer to hold the latest data
	uint8_t tempPacketBuff[10];

	//Bytes for the storage and supply availability
	uint8_t storageAvailability = 0;
	uint8_t supplyAvailability = 0;

	//Flag for only being able to read a partial packet
	uint8_t hasReadPartialPacket = false;


};

#endif