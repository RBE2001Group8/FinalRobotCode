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
<<<<<<< HEAD
#include "RollerSpit.h"
#include "RollerSuck.h"
#include "Drive.h"
#include "SwingTurn.h"
#include "PointTurn.h"
=======
#include "Roller.h"
#include "Drivetrain.h"
#include "WaitUntilPressed.h"
#include "UserButton.h"
>>>>>>> master

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

Roller roller;
Drivetrain myDrive(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);
UserButton myButton(USER_BUTTON_PIN);

/** Code to initialize the robot **/
<<<<<<< HEAD
void setup() {	
	scheduler->addCommand(new MoveArm(1015));
	scheduler->addCommand(new RollerSuck(2000));
	scheduler->addCommand(new MoveArm(680));
	scheduler->addCommand(new Drive(-0.75, 0.2, 750));
	scheduler->addCommand(new PointTurn(-1.0, 1200));
	scheduler->addCommand(new LineFollowToCrossLine(0.5));
	scheduler->addCommand(new Drive(-0.75, 0.2, 100));
	scheduler->addCommand(new SwingTurn(1.0, 1600));
	scheduler->addCommand(new LineFollowToSwitch(0.75));
	scheduler->addCommand(new RollerSpit(1500));
=======
void setup() {
	myDrive.initialize();
	myButton.initialize();
	scheduler->addCommand(new WaitUntilPressed(myButton));
	scheduler->addCommand(new LineFollowToSwitch(0.5, myDrive));
>>>>>>> master
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

