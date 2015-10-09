#ifndef ROLLERSPIT_H
#define ROLLERSPIT_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class RollerSpit : public Command {
public:
	RollerSpit(int duration);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	int _duration;
	Robot* curie;
};

#endif