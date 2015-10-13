#ifndef WAITTIME_H
#define WAITTIME_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class WaitTime : public Command {
public:
	WaitTime(int duration);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	int _duration;
};

#endif