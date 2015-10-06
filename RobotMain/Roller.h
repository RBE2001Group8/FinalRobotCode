#ifndef ROLLER_H
#define ROLLER_H

#include <Arduino.h>
#include <Servo.h>
#include "RobotConstants.h"

class Roller {
public:
	Roller();
	void initialize();
	void suck();
	void spit();
	void stop();
private:
	Servo rollerMotor;
};

#endif