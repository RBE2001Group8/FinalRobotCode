#ifndef TURN2SD_H
#define TURN2SD_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class TurnToSupplyDirection : public PausableCommand {
public:
	TurnToSupplyDirection(float turn, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
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