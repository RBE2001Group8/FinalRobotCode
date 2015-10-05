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
#include "MoveArm.h"
#include "RollerSpit.h"
#include "RollerSuck.h"
#include "Drive.h"
#include "SwingTurn.h"
#include "PointTurn.h"
#include "Drivetrain.h"
#include "WaitUntilPressed.h"
#include "UserButton.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

Roller roller;
Drivetrain myDrive(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);
UserButton myButton(USER_BUTTON_PIN);
const int potDown = 670;

/** Code to initialize the robot **/
void setup() {	
	myButton.initialize();
	//Serial.begin(9600);
	scheduler->addCommand(new WaitUntilPressed(myButton));

	scheduler->addCommand(new MoveArm(potDown));
	scheduler->addCommand(new RollerSuck(1500));
	scheduler->addCommand(new Drive(-0.25, 0.1, 200, myDrive));
	scheduler->addCommand(new RollerSuck(1000));
	scheduler->addCommand(new MoveArm(potDown+120));

	scheduler->addCommand(new RollerSpit(250));
	scheduler->addCommand(new MoveArm(potDown+290));

	scheduler->addCommand(new Drive(-0.5, 0.1, 1000, myDrive));
	scheduler->addCommand(new PointTurn(-0.5, 2100, myDrive));

	scheduler->addCommand(new LineFollowToCrossLine(0.5, myDrive)); // First line

	scheduler->addCommand(new Drive(0.5, 0.1, 300, myDrive));
	scheduler->addCommand(new LineFollowToCrossLine(0.5, myDrive)); // Second line

	scheduler->addCommand(new Drive(-0.5, 0.1, 200, myDrive)); // Back up to center on lone

	scheduler->addCommand(new SwingTurn(1.0, 1100, myDrive));
	scheduler->addCommand(new LineFollowToSwitch(0.75, myDrive));

	scheduler->addCommand(new RollerSpit(1500));
	scheduler->addCommand(new Drive(-0.25, 0.1, 350, myDrive));
	scheduler->addCommand(new RollerSpit(500));

	scheduler->addCommand(new Drive(-0.75, 0.1, 500, myDrive));
	scheduler->addCommand(new PointTurn(-0.5, 2000, myDrive));

	scheduler->addCommand(new LineFollowToSwitch(0.75, myDrive));

	scheduler->addCommand(new RollerSuck(1000));

	scheduler->addCommand(new Drive(-0.5, 0.1, 750, myDrive));

	scheduler->addCommand(new RollerSuck(1000));

}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

