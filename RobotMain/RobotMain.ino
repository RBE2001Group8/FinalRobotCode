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

}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();

}

