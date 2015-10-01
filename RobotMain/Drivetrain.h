#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>
#include <Servo.h>

class Drivetrain {
public:
	Drivetrain();
	void initialize();
	void drive(float speed, float turnRate);
	void swingTurn(float turnRate);
	void pointTurn(float turnRate);
	void stop();

private:
	static const int LEFT_MOTOR_PIN = 6;
	static const int RIGHT_MOTOR_PIN = 5;
	static const int MICROSECONDS_STOP = 1500;
	static const int MICROSECONDS_FULL_FORWARD = 2000;
	static const int MICROSECONDS_FULL_REVERSE = 1000;
	static const int MICROSECONDS_MAX_RANGE = MICROSECONDS_FULL_FORWARD - MICROSECONDS_STOP;
	/* Right Motor is reversed (2000 usec moves the motor in reverse) */
	Servo leftMotor;
	Servo rightMotor;
};

#endif