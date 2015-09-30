#ifndef ALIGNDETECT_H
#define ALIGNDETECT_H
#include <Arduino.h>

class AlignmentDetector {
public:
	AlignmentDetector();
	boolean isAligned();
};

#endif