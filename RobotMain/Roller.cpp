/** Abstraction for the intake rollers on the robot.
  * This class provides methods for intaking, outtaking,
  * and stopping the rollers
  * @author Hans Johnson
  * @date Sept. 2015
  **/

#include "Roller.h"

/** Constructor - does not initalize the motor **/
Roller::Roller() {

}

/** Initializes the motor pin **/
void Roller::initialize() {
	rollerMotor.attach(ROLLER_MOTOR_PIN);
}

/** Drives the rollers to pull the pin into the gripper **/
void Roller::suck() {
	rollerMotor.writeMicroseconds(1000);
}

/** Drives the rollers to push the pin out **/
void Roller::spit() {
	rollerMotor.writeMicroseconds(2000);
}

/** Stops the movement of the rollers **/
void Roller::stop() {
	rollerMotor.writeMicroseconds(1500);
}