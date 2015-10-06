/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
#include "BlinkLED.h"
#include "Robot.h"
#include "RobotConstants.h"
#include "Scheduler.h"
#include "LineFollowToSwitch.h"
#include "MoveArm.h"
#include "Roller.h"
#include "Drivetrain.h"
#include "WaitUntilPressed.h"
#include "UserButton.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

Roller roller;
Robot* curie = Robot::getInstance();

/** Code to initialize the robot **/
void setup() {
	curie->initializeSubsystems();
	scheduler->addCommand(new WaitUntilPressed(curie->button));
	scheduler->addCommand(new LineFollowToSwitch(0.5, curie->drivetrain));
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

