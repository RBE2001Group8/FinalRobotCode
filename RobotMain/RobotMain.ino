/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
#include "BlinkLED.h"
#include "Robot.h"
#include "Scheduler.h"
#include "LineFollowToSwitch.h"
#include "MoveArm.h"
#include "Roller.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

Roller roller;

/** Code to initialize the robot **/
void setup() {
	scheduler->addCommand(new MoveArm(680));
	scheduler->addCommand(new LineFollowToSwitch(0.5));
	roller.initialize();
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();

	if (!digitalRead(12)) {
		roller.spit();
	}

}

