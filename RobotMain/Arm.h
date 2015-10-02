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
	static const int MOTOR_PIN = 7;
	static const int POTPIN = 11;
	int input, error, last_error, accum_error, current_time, prev_time;
	static const float Kp = 5.0;
	//static const float Ki = 0.0;
	static const float Kd = 1.5;
	float output, cOutput;

};

#endif