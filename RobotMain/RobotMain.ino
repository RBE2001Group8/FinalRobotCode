/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
#include "BlinkLED.h"
#include "RobotConstants.h"
#include "Robot.h"
#include "Scheduler.h"

#include "UserButton.h"
#include "WaitUntilPressed.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

UserButton myButton(USER_BUTTON_PIN);


/** Code to initialize the robot **/
void setup() {
	Serial.begin(115200);
	myButton.initialize();

	//Waits until the button is pressed and then blinks the LED 4 times
	scheduler->addCommand(new WaitUntilPressed(myButton));
	scheduler->addCommand(new BlinkLED(100));
	scheduler->addCommand(new BlinkLED(100));
	scheduler->addCommand(new BlinkLED(100));
	scheduler->addCommand(new BlinkLED(100));
}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();

}

