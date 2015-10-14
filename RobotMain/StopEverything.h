#ifndef STOPEVERYTHING_H
#define STOPEVERYTHING_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class StopEverything : public Command {
public:
	StopEverything();
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	Robot* curie;
};

#endif