#ifndef LINEFOLLOWToStorage_H
#define LINEFOLLOWToStorage_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowToStorage : public PausableCommand {
public:
	LineFollowToStorage(float speed, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _speed;
	Robot* curie;
	bool onLine = false;
	char linesCrossed = 0;
	char linesToCross;
	bool _sideA;
	char _bitmask;
	int tubeNum;
};

#endif