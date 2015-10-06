#ifndef LINEFOLLOWOVERLINES_H
#define LINEFOLLOWOVERLINES_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"
#include "LineTracker.h"

class LineFollowOverLines : public Command {
public:
	LineFollowOverLines(float speed, Drivetrain drive, int *currentPos, int *nextPos);
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