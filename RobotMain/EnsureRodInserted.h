#ifndef ENSUREROD_H
#define ENSUREROD_H

#include "Command.h"
#include <Arduino.h>
#include "Robot.h"

class EnsureRodInserted : public Command {
public:
	EnsureRodInserted(float speed, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	float _speed;
	Robot* curie;
	int closestStorage;
	bool _sideA;
	char _bitmask;
};

#endif