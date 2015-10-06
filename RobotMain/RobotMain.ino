/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
#include "BlinkLED.h"
#include "Robot.h"
#include "RobotConstants.h"
#include "Scheduler.h"
#include "LineFollowToCrossLine.h"
#include "LineFollowToSwitch.h"
#include "PointTurnToLine.h"
#include "MoveArm.h"
#include "RollerSpit.h"
#include "RollerSuck.h"
#include "Drive.h"
#include "SwingTurn.h"
#include "PointTurn.h"
#include "Drivetrain.h"
#include "WaitUntilPressed.h"
#include "UserButton.h"
#include "LineFollowToNearest.h"

const int potDown = 670;

char storageBitMap = 10;

Scheduler* scheduler = Scheduler::getInstance();

Robot* curie = Robot::getInstance();

/** Code to initialize the robot **/
void setup() {	
	curie->initializeSubsystems();

	//Serial.begin(9600);
	scheduler->addCommand(new WaitUntilPressed(curie->button));
    scheduler->addCommand(new LineFollowToNearest(0.5, curie->drivetrain, storageBitMap, false));
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

