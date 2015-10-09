#ifndef SETCURRENTPOSITION_H
#define SETCURRENTPOSITION_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class SetCurrentPosition : public Command {
public:
	SetCurrentPosition(bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	bool _sideA;
	int tubeNum;
	char _bitmask;
	Robot* curie;
};

#endif