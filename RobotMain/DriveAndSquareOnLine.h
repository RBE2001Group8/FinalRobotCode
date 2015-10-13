#ifndef DRIVEANDSQUARE_H
#define DRIVEANDSQUARE_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class DriveAndSquareOnLine : public PausableCommand {
public:
	DriveAndSquareOnLine(float speed, float turn);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _speed, _turn;
	int _duration;
	Robot* curie;
};

#endif