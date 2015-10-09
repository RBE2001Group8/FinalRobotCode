#ifndef LINEFOLLOW2S_H
#define LINEFOLLOW2S_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowToSwitch : public Command {
public:
	LineFollowToSwitch(float speed);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed;
	Robot* curie;
};

#endif