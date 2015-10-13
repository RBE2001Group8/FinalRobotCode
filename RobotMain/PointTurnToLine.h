#ifndef POINTTURN2LINE_H
#define POINTTURN2LINE_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"


class PointTurnToLine : public PausableCommand {
public:
	PointTurnToLine(float turn);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _turn;
	Robot* curie;
	bool onLine = false;
};

#endif