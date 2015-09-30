#ifndef LINEFOLLOW2S_H
#define LINEFOLLOW2S_H

#include "Command.h"
#include <Arduino.h>

class LineFollowToSwitch : public Command {
public:
	LineFollowToSwitch(int speed);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	unsigned long _speed;
	int lineError();
};

#endif