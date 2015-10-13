#ifndef ROLLERSUCK_H
#define ROLLERSUCK_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class RollerSuck : public PausableCommand {
public:
	RollerSuck(int duration);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	int _duration;
	Robot* curie;
};

#endif