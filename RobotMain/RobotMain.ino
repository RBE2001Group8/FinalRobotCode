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

const int potDown = 670;

Scheduler* scheduler = Scheduler::getInstance();

Robot* curie = Robot::getInstance();

/** Code to initialize the robot **/
void setup() {	
	curie->initializeSubsystems();

	//Serial.begin(9600);
	scheduler->addCommand(new WaitUntilPressed(curie->button));
    //scheduler->addCommand(new Drive(-1.0, 0.0, 10000000, curie->drivetrain));
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

	scheduler->addCommand(new LineFollowToCrossLine(0.5, curie->drivetrain)); // First line

	scheduler->addCommand(new Drive(0.5, 0.1, 300, curie->drivetrain));
	scheduler->addCommand(new LineFollowToCrossLine(0.5, curie->drivetrain)); // Second line

	scheduler->addCommand(new Drive(-0.5, 0.0, 200, curie->drivetrain)); // Back up to center on lone

	scheduler->addCommand(new SwingTurn(1.0, 1100, curie->drivetrain));
	scheduler->addCommand(new LineFollowToSwitch(0.75, curie->drivetrain));

	scheduler->addCommand(new RollerSpit(1500, curie->roller));
	scheduler->addCommand(new Drive(-0.25, 0.0, 350, curie->drivetrain));
	scheduler->addCommand(new RollerSpit(500, curie->roller)); // Ensure rod is fully placed

	scheduler->addCommand(new Drive(-0.5, 0.1, 1400, curie->drivetrain)); // Back up so wheels are on main line(ish)
	scheduler->addCommand(new PointTurn(-0.375, 600, curie->drivetrain)); // Turn around, 2300 for fresh rod storage tube directly opposite
	
	scheduler->addCommand(new PointTurnToLine(-0.375, curie->drivetrain)); // Switch direction of turns to change 
	scheduler->addCommand(new Drive(-0.5, 0.0, 500, curie->drivetrain));
	scheduler->addCommand(new LineFollowToCrossLine(0.5, curie->drivetrain)); 
	scheduler->addCommand(new Drive(-0.5, 0.0, 200, curie->drivetrain)); 
	scheduler->addCommand(new SwingTurn(-1.0, 1100, curie->drivetrain));

	scheduler->addCommand(new LineFollowToSwitch(0.75, curie->drivetrain));
	scheduler->addCommand(new RollerSuck(1000, curie->roller));
	scheduler->addCommand(new Drive(-0.5, 0.0, 750, curie->drivetrain));
	scheduler->addCommand(new RollerSuck(1000, curie->roller));

	scheduler->addCommand(new MoveArm(potDown+90));

	scheduler->addCommand(new Drive(-0.5, 0.0, 750, curie->drivetrain));
	scheduler->addCommand(new PointTurn(-0.375, 600, curie->drivetrain));
	scheduler->addCommand(new PointTurnToLine(-0.375, curie->drivetrain));
	scheduler->addCommand(new LineFollowToSwitch(0.75, curie->drivetrain));

	scheduler->addCommand(new MoveArm(potDown));
	scheduler->addCommand(new RollerSpit(1250, curie->roller));
	scheduler->addCommand(new MoveArm(potDown+100));
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

