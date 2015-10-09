#ifndef TUBEPROCESSING_H
#define TUBEPROCESSING_H
#include <Arduino.h>
#include <RobotConstants.h>

class TubeProcessing {
public:
	TubeProcessing();
	int getStorageTube(char bitmask, bool sideA);
	int getFreshRodTube(char bitmask, bool sideA);
};

#endif