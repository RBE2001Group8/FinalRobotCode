#ifndef DRIVE_H
#define DRIVE_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class Drive : public PausableCommand {
public:
	Drive(float speed, float turn, int duration);
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