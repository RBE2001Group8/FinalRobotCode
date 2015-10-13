#ifndef SWINGTURN2LINE_H
#define SWINGTURN2LINE_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class SwingTurnToLine : public PausableCommand {
public:
	SwingTurnToLine(float turn);
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