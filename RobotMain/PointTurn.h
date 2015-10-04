#ifndef POINTTURN_H
#define POINTTURN_H

#include "Command.h"
#include <Arduino.h>
#include "Drivetrain.h"

class PointTurn : public Command {
public:
	PointTurn(float turn, int duration, Drivetrain drive);
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