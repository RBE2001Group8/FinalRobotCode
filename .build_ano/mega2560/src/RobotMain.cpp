#include <Arduino.h>
#include "BlinkLED.h"
#include "Robot.h"
#include "Scheduler.h"
void setup();
void loop();
#line 1 "src/RobotMain.ino"
/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
//#include "BlinkLED.h"
//#include "Robot.h"
//#include "Scheduler.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

/** Code to initialize the robot **/
void setup() {

}

/** Code to iteratively operate the robot **/
void loop() {
	scheduler->run();

}

