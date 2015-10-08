#ifndef TURN2P_H
#define TURN2P_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class TurnToPosition : public Command {
public:
	TurnToPosition(float turn, int duration, int *currentPos, int *nextPos, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	int _duration;
	Robot* curie;
	int deltaPos;
	bool prevCenter = true;
};

#endif