#ifndef LINEFOLLOWOVERLINES_H
#define LINEFOLLOWOVERLINES_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowOverLines : public Command {
public:
	LineFollowOverLines(float speed, int *currentPos, int *nextPos);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed;
	Robot* curie;
	bool onLine = false;
	char linesCrossed = 0;
	char linesToCross;
};

#endif