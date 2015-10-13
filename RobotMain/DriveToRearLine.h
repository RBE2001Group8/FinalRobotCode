#ifndef DRIVE2RL_H
#define DRIVE2RL_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"
#include "LineTracker.h"

class DriveToRearLine : public PausableCommand {
public:
	DriveToRearLine(float speed, float turn);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _speed, _turn;
	int _duration;
	Robot* curie;
};

#endif