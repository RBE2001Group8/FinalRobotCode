#ifndef POINTTURN_H
#define POINTTURN_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class PointTurn : public PausableCommand {
public:
	PointTurn(float turn, int duration);
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
};

#endif