#include "Arm.h"


/**
 * Constructor - does not initalize the motor
 **/
Arm::Arm() {
	//PID armPID(&_input, &_output, &_setpoint, 0.95, 0, 0.1, REVERSE);
	armPID.SetTuning(0.95, 0.0, 0.1);
	armPID.SetMode(AUTOMATIC);
  	armPID.SetOutputLimits(-90, 90);
}

/** 
 * Initializes the motor pin
 **/
void Arm::initialize() {
	armMotor.attach(ARM_MOTOR_PIN);

}

/**
 * Drives the arm to the provided setpoint
 **/
void Arm::moveToSetpoint(double setpoint) {
	input = analogRead(POTPIN);
	armPID.Compute();
	armMotor.write(90+output);
}

/** 
 * Stops the movement of the arm
 **/
void Arm::stop() {
	armMotor.writeMicroseconds(1500);
}