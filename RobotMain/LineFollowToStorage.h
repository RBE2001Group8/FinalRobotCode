#ifndef LINEFOLLOWToStorage_H
#define LINEFOLLOWToStorage_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class LineFollowToStorage : public Command {
public:
	LineFollowToStorage(float speed, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed;
	Robot* curie;
	bool onLine = false;
	char linesCrossed = 0;
	char linesToCross;
	bool _side;
	int tubeNum;
};

#endif