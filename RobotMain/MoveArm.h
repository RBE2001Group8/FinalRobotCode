#ifndef MOVEARM_H
#define MOVEARM_H

#include <Arduino.h>
#include <PID_v1.h>
#include <Servo.h>
#include "Command.h"
#include "RobotConstants.h"



class MoveArm : public Command {
public:
	MoveArm(int Setpoint);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	Servo armMotor;
	int input, error, last_error, accum_error, current_time, prev_time, setpoint;
	static const float Kp = 8.5;
	//static const float Ki = 0.0;
	static const float Kd = 0.0;
	//#TODO: Change threshold
	static const int threshold = 10;
	float output;

};

#endif