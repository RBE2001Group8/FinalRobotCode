#ifndef LINEFOLLOW2S_H
#define LINEFOLLOW2S_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowToSwitch : public PausableCommand {
public:
	LineFollowToSwitch(float speed);
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