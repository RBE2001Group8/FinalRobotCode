#ifndef ENSUREROD_H
#define ENSUREROD_H

#include "PausableCommand.h"
#include <Arduino.h>
#include "Robot.h"

class EnsureRodInserted : public PausableCommand {
public:
	EnsureRodInserted(float speed, bool sideA);
	void initialize();
	void execute();
	void end();
	bool isFinished();
	void onPause();
	void onResume();
private:
	float _speed;
	Robot* curie;
	int closestStorage;
	bool _sideA;
	char _bitmask;
};

#endif