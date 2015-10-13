#ifndef LINEFOLLOW2CL_H
#define LINEFOLLOW2CL_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowToCrossLine : public PausableCommand {
public:
	LineFollowToCrossLine(float speed);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _speed;
	Robot* curie;
};

#endif