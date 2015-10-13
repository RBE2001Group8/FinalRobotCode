#ifndef POINTTURN2P_H
#define POINTTURN2P_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class PointTurnToPosition : public PausableCommand {
public:
	PointTurnToPosition(float turn, int duration, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _turn;
	int _duration;
	Robot* curie;
	int deltaPos;
	char _bitmask;
	bool _sideA;
};

#endif