/** Main Code for the RBE2001 Final Project
   * @author Jordan Burklund
   * @author Andrew Lewis
   * @author Hans Johnson
   **/
#include "BlinkLED.h"
#include "Robot.h"
#include "Scheduler.h"
#include "LineTracker.h"
#include "LineFollowToSwitch.h"
#include "AlignmentDetector.h"
#include "Drivetrain.h"

//#TODO This got moved to the robot class.  Will be removed soon
Scheduler* scheduler = Scheduler::getInstance();

//AlignmentDetector alignmentDetector;
//LineTracker lineTracker;
//LineFollowToSwitch lineFollowToSwitch(0.0);
Drivetrain drivetrain;
/** Code to initialize the robot **/
void setup() {
	//lineFollowToSwitch.initialize();
	//scheduler->addCommand(&lineFollowToSwitch);

	Serial.begin(115200);
	drivetrain.initialize();
	for(float i=0; i<1.0; i+=0.1) {
		drivetrain.drive(0, i);
		delay(500);
	}
	drivetrain.drive(0,0);


}

/** Code to iteratively operate the robot **/
void loop() {
	//scheduler->run();
	//Serial.println(lineTracker.lineError());
}

