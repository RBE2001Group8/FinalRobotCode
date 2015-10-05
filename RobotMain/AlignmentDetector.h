#ifndef ALIGNDETECT_H
#define ALIGNDETECT_H
#include <Arduino.h>

class AlignmentDetector {
public:
	AlignmentDetector();
	boolean isAligned();
private:
	static const int SWITCH_PIN = 22;
};

#endif