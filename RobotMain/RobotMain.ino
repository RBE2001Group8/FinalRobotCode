/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
#include "BlinkLED.h"
#include "Robot.h"
#include "Scheduler.h"
#include "LineFollowToCrossLine.h"
#include "LineFollowToSwitch.h"
#include "MoveArm.h"
#include "RollerSpit.h"
#include "RollerSuck.h"
#include "Drive.h"
#include "SwingTurn.h"
#include "PointTurn.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

Roller roller;

/** Code to initialize the robot **/
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
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
}

