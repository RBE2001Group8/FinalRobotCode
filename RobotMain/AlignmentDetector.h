#ifndef ALIGNDETECT_H
#define ALIGNDETECT_H
#include <Arduino.h>
#include <RobotConstants.h>

class AlignmentDetector {
public:
	AlignmentDetector();
	boolean isAligned();
};

#endif