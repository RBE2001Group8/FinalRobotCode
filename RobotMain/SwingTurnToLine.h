#ifndef SWINGTURN2LINE_H
#define SWINGTURN2LINE_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class SwingTurnToLine : public Command {
public:
	SwingTurnToLine(float turn);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _turn;
	Robot* curie;
	bool onLine = false;
};

#endif