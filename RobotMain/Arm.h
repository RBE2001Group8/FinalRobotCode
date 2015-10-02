#ifndef ARM_H
#define ARM_H

#include <Arduino.h>
#include <PID_v1.h>
#include <Servo.h>
#include "Command.h"



class Arm : public Command {
public:
	Arm(int Setpoint);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	Servo armMotor;
	static const int MOTOR_PIN = 7;
	static const int POTPIN = 11;
	int input, error, last_error, accum_error, current_time, prev_time, setpoint;
	static const float Kp = 5.0;
	//static const float Ki = 0.0;
	static const float Kd = 1.5;
	float output;

};

#endif