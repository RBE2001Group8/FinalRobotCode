/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
#include "BlinkLED.h"
#include "Scheduler.h"
#include "Drivetrain.h"

Scheduler* scheduler = Scheduler::getInstance();

/** Code to initialize the robot **/
void setup() {
	Serial.begin(115200);
	Serial.println("Printing List");
	scheduler->addCommand(new BlinkLED(500));
	scheduler->addCommand(new BlinkLED(500));
	scheduler->addCommand(new BlinkLED(500));
	scheduler->addCommand(new BlinkLED(1000));
	scheduler->addCommand(new BlinkLED(1000));
	scheduler->addCommand(new BlinkLED(1000));
	scheduler->addCommand(new BlinkLED(500));
	scheduler->addCommand(new BlinkLED(500));
	scheduler->addCommand(new BlinkLED(500));
	scheduler->printCommands();
	Serial.println("Executing List");
}

/** Code to iteratively operate the robot **/
void loop() {
	//Serial.println("Iterating");
	scheduler->run();

}

