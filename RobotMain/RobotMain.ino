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
#include "MoveArm.h"
#include "Roller.h"
#include "WaitUntilPressed.h"
#include "UserButton.h"
#include "PersistentBlink.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

Roller roller;
UserButton myButton(USER_BUTTON_PIN);

/** Code to initialize the robot **/
void setup() {
	myButton.initialize();
	Serial.begin(115200);
	scheduler->addParallelCommand(new PersistentBlink(100));
	scheduler->addSequentialCommand(new WaitUntilPressed(myButton));
	scheduler->addSequentialCommand(new BlinkLED(500));
	scheduler->addSequentialCommand(new BlinkLED(500));
	scheduler->addSequentialCommand(new BlinkLED(500));
	scheduler->addSequentialCommand(new BlinkLED(500));

	roller.initialize();
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();
	scheduler->printCommands();

}

