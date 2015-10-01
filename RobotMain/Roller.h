#ifndef ROLLER_H
#define ROLLER_H

#include <Arduino.h>
#include <Servo.h>

class Roller {
public:
	Roller();
	void initialize();
	void suck();
	void spit();
	void stop();
private:
	Servo rollerMotor;
	static const int ROLLER_MOTOR_PIN = 8;
};

#endif