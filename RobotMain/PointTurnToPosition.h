#ifndef POINTTURN2P_H
#define POINTTURN2P_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class PointTurnToPosition : public Command {
public:
	PointTurnToPosition(float turn, int duration, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	int _duration;
	Robot* curie;
	int deltaPos;
};

#endif