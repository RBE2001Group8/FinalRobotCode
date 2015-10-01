#include "Drivetrain.h"



/** Constructor
  * Intentionally does not initialize the drivetrain
  **/
Drivetrain::Drivetrain() {

}
/** Initializes the drivetrain, and sets up the motor port
  **/
void Drivetrain::initialize() {
	leftMotor.attach(LEFT_MOTOR_PIN);
	rightMotor.attach(RIGHT_MOTOR_PIN);
}

/** Drives the robot with the given speed and turn rate.
  * Values range between -1 and 1 where 1 specifies full
  * speed forward, or full speed turning left.
  * @param speed Speed that the robot should travel at
  * @param turnRate Rate that the robot should turn at
  **/
void Drivetrain::drive(float speed, float turnRate) {
	//Calculate the values for each motor based on speed and turn rate.  Note right is reversed
	int leftValue = MICROSECONDS_STOP + (MICROSECONDS_MAX_RANGE*speed) - ((float)MICROSECONDS_MAX_RANGE*turnRate);
	int rightValue = MICROSECONDS_STOP - (MICROSECONDS_MAX_RANGE*speed) - ((float)MICROSECONDS_MAX_RANGE*turnRate);

	//Constrain the values to valid ranges for the servo
	leftValue = constrain(leftValue, MICROSECONDS_FULL_REVERSE, MICROSECONDS_FULL_FORWARD);
	rightValue = constrain(rightValue, MICROSECONDS_FULL_REVERSE, MICROSECONDS_FULL_FORWARD);

	//Write the values to the motors
	leftMotor.writeMicroseconds(leftValue);
	rightMotor.writeMicroseconds(rightValue);
}

/** Moves the robot through a swing turn at the given
  * rate. Where one wheel is stopped, and the other moves
  * at the specified rate.  Values range from -1 to 1 where
  * 1 is full speed swing turn left.
  * @note Only swings forward
  * @param turnRate Speed that the robot should turn at
  **/
void Drivetrain::swingTurn(float turnRate) {
	if(turnRate == 0.0) {
		//Don't turn
		stop();
	} else if(turnRate > 0) {
		//turn left
		leftMotor.writeMicroseconds(MICROSECONDS_STOP);
		rightMotor.writeMicroseconds(MICROSECONDS_STOP + (MICROSECONDS_MAX_RANGE*turnRate));
	} else {
		//turn right
		leftMotor.writeMicroseconds(MICROSECONDS_STOP + (MICROSECONDS_MAX_RANGE*turnRate));
		rightMotor.writeMicroseconds(MICROSECONDS_STOP);
	}
}

/** Moves the robot through a point turn at the given
  * rate, where the wheels rotate in opposite directions
  * at the same speed.  Values range from -1 to 1 where
  * 1 is full speed turning left.
  * @param turnRate Speed that the robot should turn at
  **/
void Drivetrain::pointTurn(float turnRate){
	leftMotor.writeMicroseconds(MICROSECONDS_STOP + (MICROSECONDS_MAX_RANGE*turnRate));
	rightMotor.writeMicroseconds(MICROSECONDS_STOP + (MICROSECONDS_MAX_RANGE*turnRate));
}

/** Stops the drivetrain.
  **/
void Drivetrain::stop() {
	leftMotor.writeMicroseconds(MICROSECONDS_STOP);
	rightMotor.writeMicroseconds(MICROSECONDS_STOP);
}
