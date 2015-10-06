#ifndef DRIVE2RL_H
#define DRIVE2RL_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"
#include "LineTracker.h"

class DriveToRearLine : public Command {
public:
	DriveToRearLine(float speed, float turn, Drivetrain drive);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed, _turn;
	int _duration;
	Drivetrain drivetrain;
	LineTracker lineTracker;
};

#endif