#ifndef DRIVEANDSQUARE_H
#define DRIVEANDSQUARE_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class DriveAndSquareOnLine : public Command {
public:
	DriveAndSquareOnLine(float speed, float turn);
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