#ifndef LINEFOLLOWOVERLINES_H
#define LINEFOLLOWOVERLINES_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowOverLines : public PausableCommand {
public:
	LineFollowOverLines(float speed, bool sideA);
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
	char _bitmask;
	bool _sideA;
	unsigned long lastCrossTime;
};

#endif