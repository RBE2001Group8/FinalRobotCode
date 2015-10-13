#ifndef SWINGTURN_H
#define SWINGTURN_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class SwingTurn : public PausableCommand {
public:
	SwingTurn(float turn, int duration);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _turn;
	int _duration;
	Robot* curie;
};

#endif