#ifndef POINTTURN2LINE_H
#define POINTTURN2LINE_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"


class PointTurnToLine : public Command {
public:
	PointTurnToLine(float turn);
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