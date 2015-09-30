#ifndef BLINKLED_H
#define BLINKLED_H

#include "Command.h"
#include <Arduino.h>

class BlinkLED : public Command {
public:
	BlinkLED(unsigned long period);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	unsigned long _period;
	int LEDPin = 13;
};

#endif