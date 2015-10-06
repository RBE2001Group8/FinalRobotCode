#ifndef PERSISTENTBLINK_H
#define PERSISTENTBLINK_H

#include <Arduino.h>
#include "Command.h"

class PersistentBlink : public Command {
public:
	PersistentBlink(unsigned long period);
	void initialize();
	void execute();
	void end();
	bool isFinished();

private:
	unsigned long _period;
	int LEDPin = 13;
};

#endif