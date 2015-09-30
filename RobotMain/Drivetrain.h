#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Arduino.h>
#include <Servo.h>

class Drivetrain {
public:
	void drive(float speed, float turnRate);
	void driveForward(float speed);
	void swingTurn(float turnRate);
	void pointTurn(float turnRate);
	void stop();
	Servo leftMotor;
	Servo rightMotor;

private:
	static const int LEFT_MOTOR_PIN = 6;
	static const int RIGHT_MOTOR_PIN = 5;
};

#endif