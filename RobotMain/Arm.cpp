#include "Arm.h"

/**
 * Constructor - does not initalize the motor
 **/
Arm::Arm(int Setpoint) : Command("Arm") {
	setpoint = Setpoint;
}

/** 
 * Initializes the motor pin
 **/
void Arm::initialize() {
	armMotor.attach(MOTOR_PIN);
	Serial.begin(9600);
}

/**
 * Drives the arm to the provided setpoint
 **/
void Arm::execute() {
	input = analogRead(POTPIN);
	error = setpoint-input;
	//current_time = millis();
	//accum_error += error/(float)(current_time-prev_time);

	output = Kp*(float)error + Kd*(float)(error-last_error);// Ki*(float)(accum_error) + 

	output = constrain(output, -500, 500);
	armMotor.writeMicroseconds(1500-output);//+output);
	last_error = error;
	//prev_time = current_time;
	/*Serial.print(Kp*(float)error);
	Serial.print(", ");
	Serial.print(Ki*(accum_error));
	Serial.print(", ");
	Serial.print(Kd*(float)(error-last_error));
	Serial.print(", ");
	Serial.print(output);
	Serial.print(", ");
	Serial.println(error);*/
}

/**
 * Finished when error is less than the threshold specified in Arm.h
 **/
bool Arm::isFinished() {
	return abs(error) < 10;
}

/**
 * Stops the arm movement when Finished
 **/

void Arm::end() {
	armMotor.writeMicroseconds(1500);
}