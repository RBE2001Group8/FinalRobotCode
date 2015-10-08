#ifndef SWINGTURN_H
#define SWINGTURN_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class SwingTurn : public Command {
public:
	SwingTurn(float turn, int duration);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	int _duration;
	Robot* curie;
};

#endif