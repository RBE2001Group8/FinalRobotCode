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
#include "LineFollowOverLines.h"
#include "DriveToRearLine.h"
#include "SwingTurnToLine.h"
#include "SwingTurnToPosition.h"
#include "DriveAndSquareOnLine.h"
#include "PointTurnToPosition.h"
#include "TurnToPosition.h"

const int potDown = 670;

char storageBitMap = 10;

int currentPos = 2;
int newPos = 1;

Scheduler* scheduler = Scheduler::getInstance();

Robot* curie = Robot::getInstance();

/** Code to initialize the robot **/
void setup() {	
	curie->initializeSubsystems();

	//Serial.begin(9600);
	scheduler->addCommand(new WaitUntilPressed(curie->button));
	scheduler->addCommand(new DriveToRearLine(-0.375, 0.07, curie->drivetrain));
	scheduler->addCommand(new Drive(-0.375, 0.07, 250, curie->drivetrain));
	scheduler->addCommand(new PointTurnToPosition(0.375, 2000, curie->drivetrain, &currentPos, &newPos));
	scheduler->addCommand(new Drive(-0.375, 0.07, 250, curie->drivetrain));
	scheduler->addCommand(new DriveAndSquareOnLine(0.375, 0.07, curie->drivetrain));
	scheduler->addCommand(new Drive(-0.375, 0.07, 400, curie->drivetrain));
    scheduler->addCommand(new LineFollowOverLines(0.5, curie->drivetrain, &currentPos, &newPos));
    scheduler->addCommand(new TurnToPosition(0.5, 2200, curie->drivetrain, &currentPos, &newPos));
    scheduler->addCommand(new LineFollowToSwitch(0.375, curie->drivetrain));
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

