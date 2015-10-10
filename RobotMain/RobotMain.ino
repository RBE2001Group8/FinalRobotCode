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
#include "PointTurn.h"
#include "SwingTurn.h"
#include "WaitUntilPressed.h"
#include "LineFollowOverLines.h"
#include "DriveToRearLine.h"
#include "DriveAndSquareOnLine.h"
#include "PointTurnToPosition.h"
#include "TurnToPosition.h"
#include "SetRadiationLevel.h"
#include "LineFollowToStorage.h"
#include "PersistentSendHeartbeats.h"
#include "PersistentSendRadAlerts.h"
#include "PersistentGetPackets.h"
#include "PersistentWarnRadiation.h"
#include "LineFollowToCrossLine.h"
#include "SwingTurnToLine.h"
#include "TurnToSupplyDirection.h"

int potDown = 665;


Scheduler* scheduler = Scheduler::getInstance();

Robot* curie = Robot::getInstance();

/** Code to initialize the robot **/
void setup() {	
	potDown = 665;
	Serial.begin(115200);
	curie->initializeSubsystems();

	scheduler->addParallelCommand(new PersistentWarnRadiation(curie, curie->radInd));
	scheduler->addParallelCommand(new PersistentSendHeartbeats());
	scheduler->addParallelCommand(new PersistentSendRadAlerts());
	scheduler->addParallelCommand(new PersistentGetPackets());

	scheduler->addSequentialCommand(new WaitUntilPressed());
	
	scheduler->addSequentialCommand(new MoveArm(potDown));
	scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_SPENT));
	scheduler->addSequentialCommand(new RollerSuck(1500));
	scheduler->addParallelCommand(new Drive(-0.25, 0.0, 200));
	scheduler->addSequentialCommand(new RollerSuck(1000));

	scheduler->addParallelCommand(new RollerSpit(250));
	scheduler->addSequentialCommand(new MoveArm(potDown+290));

	scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 1000));
	scheduler->addSequentialCommand(new PointTurn(-0.5, 1000));
	scheduler->addSequentialCommand(new PointTurnToLine(-0.5));
	//#TODO Add constant for SIDE_A and SIDE_B
	scheduler->addSequentialCommand(new LineFollowToStorage(0.5, true));

	scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 200)); // Back up to center on line
	//#TODO Make this swing turn to line
	scheduler->addSequentialCommand(new SwingTurn(1.0, 950));
	scheduler->addSequentialCommand(new LineFollowToSwitch(0.75));

	scheduler->addSequentialCommand(new RollerSpit(1000)); // Ensure rod is fully placed
	scheduler->addParallelCommand(new RollerSpit(1000));
	scheduler->addSequentialCommand(new Drive(-0.25, 0.0, 350));
	scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NONE));

	//scheduler->addSequentialCommand(new DriveToRearLine(-0.375, 0.07));
	scheduler->addSequentialCommand(new Drive(-0.5, 0.07, 500));
	scheduler->addSequentialCommand(new PointTurn(-0.5, 1000));
	scheduler->addSequentialCommand(new PointTurnToLine(-0.5));
	scheduler->addSequentialCommand(new LineFollowToCrossLine(0.5));
	scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 200));

	scheduler->addSequentialCommand(new TurnToSupplyDirection(0.375, true));
    scheduler->addSequentialCommand(new LineFollowOverLines(0.5, true));
    scheduler->addSequentialCommand(new Drive(0.5, 0.0, 250));
    scheduler->addSequentialCommand(new TurnToPosition(0.4, true));

  	scheduler->addSequentialCommand(new LineFollowToSwitch(0.5));

    scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NEW));
    scheduler->addSequentialCommand(new RollerSuck(1000));
	scheduler->addParallelCommand(new Drive(-0.5, 0.0, 500));
	scheduler->addSequentialCommand(new RollerSuck(1000));

	scheduler->addParallelCommand(new MoveArm(potDown+90));

	//scheduler->addSequentialCommand(new Drive(-0.5, 0.07, 500));
	scheduler->addSequentialCommand(new PointTurn(-0.5, 1000));
	scheduler->addSequentialCommand(new PointTurnToLine(-0.5));
	scheduler->addSequentialCommand(new LineFollowToCrossLine(0.5));
	scheduler->addSequentialCommand(new SwingTurnToLine(0.5));

	scheduler->addSequentialCommand(new LineFollowToSwitch(0.75));

	scheduler->addSequentialCommand(new MoveArm(potDown));
	scheduler->addSequentialCommand(new RollerSpit(1250));
	scheduler->addSequentialCommand(new Drive(-0.25, 0.0, 200));
	scheduler->addSequentialCommand(new RollerSpit(1250));
	scheduler->addParallelCommand(new RollerSpit(500));
	scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NONE));
	scheduler->addSequentialCommand(new MoveArm(potDown+100));

	// /////////////////////////// SIDE 2 //////////////////////////////// 
	// scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 1000));
	// scheduler->addSequentialCommand(new PointTurn(-0.5, 1000));
	// scheduler->addSequentialCommand(new PointTurnToLine(-0.5));
	// scheduler->addSequentialCommand(new LineFollowToSwitch(0.5));

	// scheduler->addSequentialCommand(new MoveArm(potDown));
	// scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_SPENT));
	// scheduler->addSequentialCommand(new RollerSuck(1500));
	// scheduler->addParallelCommand(new Drive(-0.25, 0.0, 200));
	// scheduler->addSequentialCommand(new RollerSuck(1000));

	// scheduler->addParallelCommand(new RollerSpit(250));
	// scheduler->addSequentialCommand(new MoveArm(potDown+290));

	// scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 1000));
	// scheduler->addSequentialCommand(new PointTurn(-0.5, 1000));
	// scheduler->addSequentialCommand(new PointTurnToLine(-0.5));
	// scheduler->addSequentialCommand(new LineFollowToStorage(0.5, false));

	// scheduler->addSequentialCommand(new Drive(-0.5, 0.0, 200)); // Back up to center on line
	// scheduler->addSequentialCommand(new SwingTurn(-1.0, 950));
	// scheduler->addSequentialCommand(new LineFollowToSwitch(0.75));

	// scheduler->addSequentialCommand(new RollerSpit(1000)); // Ensure rod is fully placed
	// scheduler->addParallelCommand(new RollerSpit(1000));
	// scheduler->addSequentialCommand(new Drive(-0.25, 0.0, 350));
	// scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NONE));

	// scheduler->addSequentialCommand(new DriveToRearLine(-0.375, 0.07));
	// scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 250));
	// scheduler->addSequentialCommand(new PointTurnToPosition(0.375, 1700, false));
	// scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 550));
	// scheduler->addSequentialCommand(new DriveAndSquareOnLine(0.375, 0.07));
	// scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 600));
 //    scheduler->addSequentialCommand(new LineFollowOverLines(0.5, false));
 //    scheduler->addSequentialCommand(new TurnToPosition(0.4, 2000, false));
 //    scheduler->addSequentialCommand(new LineFollowToSwitch(0.5));

 //    scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NEW));
 //    scheduler->addSequentialCommand(new RollerSuck(1000));
	// scheduler->addParallelCommand(new Drive(-0.5, 0.0, 750));
	// scheduler->addSequentialCommand(new RollerSuck(1000));

	// scheduler->addParallelCommand(new MoveArm(potDown+90));

	// scheduler->addSequentialCommand(new DriveToRearLine(-0.375, 0.07));
	// scheduler->addSequentialCommand(new Drive(-0.375, 0.07, 250));
	// scheduler->addSequentialCommand(new PointTurn(0.5, 1700));

	// scheduler->addSequentialCommand(new LineFollowToSwitch(0.75));

	// scheduler->addSequentialCommand(new MoveArm(potDown));
	// scheduler->addSequentialCommand(new RollerSpit(1250));
	// scheduler->addSequentialCommand(new Drive(-0.25, 0.0, 200));
	// scheduler->addSequentialCommand(new RollerSpit(1250));
	// scheduler->addParallelCommand(new RollerSpit(500));
	// scheduler->addParallelCommand(new SetRadiationLevel(curie, RAD_LEVEL_NONE));
	// scheduler->addSequentialCommand(new MoveArm(potDown+100));


	//curie->setRadLevel(RAD_LEVEL_NEW);
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
	//Serial.print("Rad Level: ");
	//Serial.println(curie->getRadLevel());
}

