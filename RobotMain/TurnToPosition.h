#ifndef TURN2P_H
#define TURN2P_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"
#include "LineTracker.h"

class TurnToPosition : public Command {
public:
	TurnToPosition(float turn, int duration, Drivetrain drive, int *currentPos, int *nextPos);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	int _duration;
	Drivetrain drivetrain;
	int deltaPos;
	bool prevCenter = true;
	LineTracker lineTracker;
};

#endif