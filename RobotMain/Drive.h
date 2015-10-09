#ifndef DRIVE_H
#define DRIVE_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class Drive : public Command {
public:
	Drive(float speed, float turn, int duration);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed, _turn;
	int _duration;
	Robot* curie;
};

#endif