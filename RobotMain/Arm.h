#ifndef ARM_H
#define ARM_H

#include <Arduino.h>
#include <PID_v1.h>
#include <Servo.h>


class Arm {
public:
	Arm();
	void initialize();
	void moveToSetpoint(double setpoint);
	void stop();
private:
	Servo armMotor;
	double setpoint, input, output;
	static const int ARM_MOTOR_PIN = 7;
	static const int POTPIN = A11;
	PID armPID(&input, &output, &setpoint, 0.0, 0.0, 0.0, REVERSE);
};

#endif