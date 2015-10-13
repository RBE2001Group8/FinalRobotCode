#ifndef ROLLERSPIT_H
#define ROLLERSPIT_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class RollerSpit : public PausableCommand {
public:
	RollerSpit(int duration);
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