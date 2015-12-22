#ifndef ROBOT_H
#define ROBOT_H

#include "RobotConstants.h"
#include "Drivetrain.h"
#include "LineTracker.h"
#include "Scheduler.h"
#include "UserButton.h"
#include "Roller.h"
#include "RadiationIndicator.h"
#include "LineTracker.h"
#include "AlignmentDetector.h"
#include "TubeProcessing.h"
#include "ReactorLink.h"
#include "PausableTimer.h"

//#TODO Change all of the things to allocate memory on the stack or in the global space
class Robot {
public:
	//Get the singleton instance
	static Robot* getInstance();
	//All of the subsytem in the robot
	Scheduler scheduler; 
	Drivetrain drivetrain(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);
	UserButton button(USER_BUTTON_PIN);
	Roller roller; //#TODO add parameter for pin
	RadiationIndicator radInd(RADIATION_LED_PIN, 750);
	LineTracker lineTracker; //#TODO add parameter for sensor pins
	AlignmentDetector alignmentDetector; //#TODO add switch pin parameter
	TubeProcessing tubeProcessor;
	ReactorLink reactorLink;
	int currentPos = 2;

	void setRadLevel(int newRadLevel);
	int getRadLevel();

	void initializeSubsystems();

private:
	//Constructor is private so it cannot be invoked
	Robot();
	static Robot instance;
	int radLevel = RAD_LEVEL_NONE;

};

#endif