#ifndef TURN2SD_H
#define TURN2SD_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class TurnToSupplyDirection : public Command {
public:
	TurnToSupplyDirection(float turn, bool sideA);
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