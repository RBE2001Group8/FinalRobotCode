#ifndef POINTTURN2LINE_H
#define POINTTURN2LINE_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"
#include "LineTracker.h"

class PointTurnToLine : public Command {
public:
	PointTurnToLine(float turn, Drivetrain drive);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	Drivetrain drivetrain;
	LineTracker lineTracker;
};

#endif