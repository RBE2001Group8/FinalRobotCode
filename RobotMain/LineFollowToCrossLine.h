#ifndef LINEFOLLOW2CL_H
#define LINEFOLLOW2CL_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowToCrossLine : public Command {
public:
	LineFollowToCrossLine(float speed);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed;
	Robot* curie;
};

#endif