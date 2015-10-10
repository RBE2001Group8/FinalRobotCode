#ifndef TURN2P_H
#define TURN2P_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class TurnToPosition : public Command {
public:
	TurnToPosition(float turn, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	Robot* curie;
	int deltaPos;
	bool prevCenter = true;
	bool _sideA;
	char _bitmask;
	bool offLine;
};

#endif