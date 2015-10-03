#ifndef ROLLERSUCK_H
#define ROLLERSUCK_H

#include "Command.h"
#include <Arduino.h>
#include "Roller.h"

class RollerSuck : public Command {
public:
	RollerSuck(int duration);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	int _duration;
	Roller roller;
};

#endif