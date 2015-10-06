#ifndef SWINGTURN2LINE_H
#define SWINGTURN2LINE_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"
#include "LineTracker.h"

class SwingTurnToLine : public Command {
public:
	SwingTurnToLine(float turn, Drivetrain drive);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	Drivetrain drivetrain;
	LineTracker lineTracker;
	bool onLine = false;
};

#endif