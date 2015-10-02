#include "Arm.h"


/**
 * Constructor - does not initalize the motor
 **/
Arm::Arm() {
}

/** 
 * Initializes the motor pin
 **/
void Arm::initialize() {
	armMotor.attach(ARM_MOTOR_PIN);
	Serial.begin(9600);
}

/**
 * Drives the arm to the provided setpoint
 **/
void Arm::moveToSetpoint(int setpoint) {
	input = analogRead(POTPIN);
	error = setpoint-input;
	//current_time = millis();
	//accum_error += error/(float)(current_time-prev_time);

	output = Kp*error + Kd*(error-last_error);// + Ki*(accum_error) 

	//last_error = error;
	//prev_time = current_time;
	armMotor.writeMicroseconds(1500+output);
	last_error = error;
	Serial.println(input);
}

/** 
 * Stops the movement of the arm
 **/
void Arm::stop() {
	armMotor.writeMicroseconds(1500);
}