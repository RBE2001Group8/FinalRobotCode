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
#include "PersistentWarnRadiation.h"
#include "SetRadiationLevel.h"

const int potDown = 665;


char storageBitMap = 10;

int dropoffPos = 1;
int pickupPos = 3;

Scheduler* scheduler = Scheduler::getInstance();

Robot* curie = Robot::getInstance();

/** Code to initialize the robot **/
void setup() {	
	Serial.begin(115200);
	curie->initializeSubsystems();

	scheduler->addParallelCommand(new PersistentWarnRadiation(curie, curie->radInd));
	scheduler->addSequentialCommand(new WaitUntilPressed(curie->button));
	
	scheduler->addSequentialCommand(new MoveArm(potDown));
	scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_SPENT));
	scheduler->addSequentialCommand(new RollerSuck(1500, curie->roller));
	scheduler->addParallelCommand(new Drive(-0.25, 0.0, 200, curie->drivetrain));
	scheduler->addSequentialCommand(new RollerSuck(1000, curie->roller));

	scheduler->addParallelCommand(new RollerSpit(250, curie->roller));
	scheduler->addSequentialCommand(new MoveArm(potDown+290));

	scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 1000, curie->drivetrain));
	scheduler->addSequentialCommand(new PointTurn(-0.5, 1000, curie->drivetrain));
	scheduler->addSequentialCommand(new PointTurnToLine(-0.5, curie->drivetrain));
	scheduler->addSequentialCommand(new LineFollowOverLines(0.5, curie->drivetrain, 0, &dropoffPos));

	scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 200, curie->drivetrain)); // Back up to center on line
	scheduler->addSequentialCommand(new SwingTurn(-1.0, 1100, curie->drivetrain));
	scheduler->addSequentialCommand(new LineFollowToSwitch(0.75, curie->drivetrain));

	scheduler->addSequentialCommand(new RollerSpit(1000, curie->roller)); // Ensure rod is fully placed
	scheduler->addParallelCommand(new RollerSpit(1000, curie->roller));
	scheduler->addSequentialCommand(new Drive(-0.25, 0.0, 350, curie->drivetrain));
	scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NONE));

	scheduler->addSequentialCommand(new DriveToRearLine(-0.375, 0.07, curie->drivetrain));
	scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 250, curie->drivetrain));
	scheduler->addSequentialCommand(new PointTurnToPosition(0.375, 1700, curie->drivetrain, &dropoffPos, &pickupPos));
	scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 550, curie->drivetrain));
	scheduler->addSequentialCommand(new DriveAndSquareOnLine(0.375, 0.07, curie->drivetrain));
	scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 600, curie->drivetrain));
    scheduler->addSequentialCommand(new LineFollowOverLines(0.5, curie->drivetrain, &dropoffPos, &pickupPos));
    scheduler->addSequentialCommand(new TurnToPosition(0.5, 2000, curie->drivetrain, &dropoffPos, &pickupPos));
    scheduler->addSequentialCommand(new LineFollowToSwitch(0.375, curie->drivetrain));

    scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NEW));
    scheduler->addSequentialCommand(new RollerSuck(1000, curie->roller));
	scheduler->addParallelCommand(new Drive(-0.5, 0.0, 750, curie->drivetrain));
	scheduler->addSequentialCommand(new RollerSuck(1000, curie->roller));

	scheduler->addParallelCommand(new MoveArm(potDown+90));

	scheduler->addSequentialCommand(new DriveToRearLine(-0.375, 0.07, curie->drivetrain));
	scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 250, curie->drivetrain));
	scheduler->addSequentialCommand(new PointTurn(0.5, 1600, curie->drivetrain));

	scheduler->addSequentialCommand(new LineFollowToSwitch(0.75, curie->drivetrain));

	scheduler->addSequentialCommand(new MoveArm(potDown));
	scheduler->addSequentialCommand(new RollerSpit(1250, curie->roller));
	scheduler->addSequentialCommand(new Drive(-0.25, 0.0, 200, curie->drivetrain));
	scheduler->addSequentialCommand(new RollerSpit(1250, curie->roller));
	scheduler->addParallelCommand(new RollerSpit(500, curie->roller));
	scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NONE));
	scheduler->addSequentialCommand(new MoveArm(potDown+100));

	//curie->setRadLevel(RAD_LEVEL_NEW);
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
	//Serial.print("Rad Level: ");
	//Serial.println(curie->getRadLevel());
}

