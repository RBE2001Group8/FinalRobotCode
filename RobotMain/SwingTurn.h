#ifndef SWINGTURN_H
#define SWINGTURN_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"

class SwingTurn : public Command {
public:
	SwingTurn(float turn, int duration, Drivetrain drive);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	int _duration;
	Drivetrain drivetrain;
};

#endif