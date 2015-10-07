#ifndef POINTTURN2P_H
#define POINTTURN2P_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"

class PointTurnToPosition : public Command {
public:
	PointTurnToPosition(float turn, int duration, Drivetrain drive, int *currentPos, int *nextPos);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	int _duration;
	Drivetrain drivetrain;
	int deltaPos;
};

#endif