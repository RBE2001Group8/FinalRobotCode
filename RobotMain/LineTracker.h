#ifndef LINETRACKER_H
#define LINETRACKER_H
#include <Arduino.h>

class LineTracker{
public:
	LineTracker();
	float lineError();
private:
	static const int m1 = 21; // In 1/16ths of an inch
	static const int m2 = 15;
	static const int m3 = 9;
	static const int m4 = 3;

};

#endif