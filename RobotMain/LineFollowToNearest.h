#ifndef LINEFOLLOW2N_H
#define LINEFOLLOW2N_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"
#include "LineTracker.h"

class LineFollowToNearest : public Command {
public:
	LineFollowToNearest(float speed, Drivetrain drive, char bitmask, bool firstSide);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed;
	Drivetrain drivetrain;
	LineTracker lineTracker;
	bool onLine = false;
	char linesCrossed = 0;
	char linesToCross;
};

#endif