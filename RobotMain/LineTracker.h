#ifndef LINETRACKER_H
#define LINETRACKER_H
#include <Arduino.h>

class LineTracker{
public:
	LineTracker();
	float lineError();
private:
	static const int m1 = 20;
	static const int m2 = 12;
	static const int m3 = 8;
	static const int m4 = 4;

};

#endif