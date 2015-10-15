/** Moves the arm to the specified position
  * @author Hans Johnson
  * @date Sept. 2015
  **/

#include "MoveArm.h"

/**
 * Constructor - does not initalize the motor. 
 * @param Setpoint The pot value to move the arm to
 **/
MoveArm::MoveArm(int Setpoint) : Command("MoveArm") {
	setpoint = Setpoint+ARM_POT_OFFSET;
}

/** 
 * Initializes the motor pin
 **/
void MoveArm::initialize() {
	armMotor.attach(ARM_MOTOR_PIN);
}

/**
 * Drives the MoveArm to the provided setpoint
 **/
void MoveArm::execute() {
	input = analogRead(POTPIN);
	error = setpoint-input;
	//current_time = millis();
	//accum_error += error/(float)(current_time-prev_time);

	output = Kp*(float)error + Kd*(float)(error-last_error);// Ki*(float)(accum_error) + 

	output = constrain(output, -500, 500);
	armMotor.writeMicroseconds(1500+output);//+output);
	last_error = error;
}

/**
 * Finished when error is less than the threshold specified in MoveArm.h
 **/
bool MoveArm::isFinished() {
	return abs(error) < threshold;
}

/**
 * Stops the MoveArm movement when Finished
 **/
void MoveArm::end() {
	armMotor.writeMicroseconds(1500);
	armMotor.detach();
}