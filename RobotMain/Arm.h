#ifndef ARM_H
#define ARM_H

#include <Arduino.h>
#include <PID_v1.h>
#include <Servo.h>


class Arm {
public:
	Arm();
	void initialize();
	void moveToSetpoint(int setpoint);
	void stop();
private:
	Servo armMotor;
	static const int ARM_MOTOR_PIN = 8;
	static const int POTPIN = 11;
	int input, error, last_error;
	static const int Kp = 0.95;
	static const int Kd = 0.1;
	float output;

};

#endif