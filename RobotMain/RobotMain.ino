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
#include "PointTurnToLine.h"
#include "MoveArm.h"
#include "RollerSpit.h"
#include "RollerSuck.h"
#include "Drive.h"
#include "SwingTurn.h"
#include "PointTurn.h"
#include "WaitUntilPressed.h"
#include "LineFollowOverLines.h"
#include "DriveToRearLine.h"
#include "SwingTurnToPosition.h"
#include "DriveAndSquareOnLine.h"
#include "PointTurnToPosition.h"
#include "TurnToPosition.h"

const int potDown = 660;

char storageBitMap = 10;

int dropoffPos = 2;
int pickupPos = 1;

Scheduler* scheduler = Scheduler::getInstance();

Robot* curie = Robot::getInstance();

/** Code to initialize the robot **/
void setup() {	
	curie->initializeSubsystems();

	//Serial.begin(9600);
	scheduler->addCommand(new WaitUntilPressed(curie->button));

	scheduler->addCommand(new MoveArm(potDown));
	scheduler->addCommand(new RollerSuck(1500, curie->roller));
	scheduler->addCommand(new Drive(-0.25, 0.0, 200, curie->drivetrain));
	scheduler->addCommand(new RollerSuck(1000, curie->roller));
	scheduler->addCommand(new MoveArm(potDown+90));

	scheduler->addCommand(new RollerSpit(250, curie->roller));
	scheduler->addCommand(new MoveArm(potDown+290));

	scheduler->addCommand(new Drive(-0.5, 0.0, 1000, curie->drivetrain));
	scheduler->addCommand(new PointTurn(-0.5, 1000, curie->drivetrain));
	scheduler->addCommand(new PointTurnToLine(-0.5, curie->drivetrain));
	scheduler->addCommand(new LineFollowOverLines(0.5, curie->drivetrain, 0, &dropoffPos));

	scheduler->addCommand(new Drive(-0.5, 0.0, 200, curie->drivetrain)); // Back up to center on line
	scheduler->addCommand(new SwingTurn(-1.0, 1100, curie->drivetrain));
	scheduler->addCommand(new LineFollowToSwitch(0.75, curie->drivetrain));

	scheduler->addCommand(new RollerSpit(1500, curie->roller));
	scheduler->addCommand(new Drive(-0.25, 0.0, 350, curie->drivetrain));
	scheduler->addCommand(new RollerSpit(500, curie->roller)); // Ensure rod is fully placed

	scheduler->addCommand(new DriveToRearLine(-0.375, 0.07, curie->drivetrain));
	scheduler->addCommand(new Drive(-0.375, 0.07, 250, curie->drivetrain));
	scheduler->addCommand(new PointTurnToPosition(0.375, 2000, curie->drivetrain, &dropoffPos, &pickupPos));
	scheduler->addCommand(new Drive(-0.375, 0.07, 250, curie->drivetrain));
	scheduler->addCommand(new DriveAndSquareOnLine(0.375, 0.07, curie->drivetrain));
	scheduler->addCommand(new Drive(-0.375, 0.07, 400, curie->drivetrain));
    scheduler->addCommand(new LineFollowOverLines(0.5, curie->drivetrain, &dropoffPos, &pickupPos));
    scheduler->addCommand(new TurnToPosition(0.5, 2200, curie->drivetrain, &dropoffPos, &pickupPos));
    scheduler->addCommand(new LineFollowToSwitch(0.375, curie->drivetrain));

    scheduler->addCommand(new RollerSuck(1000, curie->roller));
	scheduler->addCommand(new Drive(-0.5, 0.0, 750, curie->drivetrain));
	scheduler->addCommand(new RollerSuck(1000, curie->roller));

	scheduler->addCommand(new MoveArm(potDown+90));

	scheduler->addCommand(new DriveToRearLine(-0.375, 0.07, curie->drivetrain));
	scheduler->addCommand(new Drive(-0.375, 0.07, 250, curie->drivetrain));
	scheduler->addCommand(new PointTurn(0.5, 1600, curie->drivetrain));

	scheduler->addCommand(new LineFollowToSwitch(0.75, curie->drivetrain));

	scheduler->addCommand(new MoveArm(potDown));
	scheduler->addCommand(new RollerSpit(1250, curie->roller));
	scheduler->addCommand(new Drive(-0.25, 0.0, 200, curie->drivetrain));
	scheduler->addCommand(new RollerSpit(1250, curie->roller));
	scheduler->addCommand(new MoveArm(potDown+100));

}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

