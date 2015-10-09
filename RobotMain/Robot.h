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

//#TODO Hack to fix cyclical dependency
class RadiationIndicator;

class Robot {
public:
	static Robot* getInstance();
	//#TODO Code Clean up: switch classes to pointers, like RadInd
	Scheduler *scheduler; 
	Drivetrain drivetrain = *new Drivetrain(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);
	UserButton button = *new UserButton(USER_BUTTON_PIN);
	Roller roller = *new Roller(); //#TODO add parameter for pin
	RadiationIndicator* radInd = new RadiationIndicator(RADIATION_LED_PIN, 750);
	LineTracker lineTracker = *new LineTracker(); //#TODO add parameter for sensor pins
	AlignmentDetector alignmentDetector = *new AlignmentDetector(); //#TODO add switch pin parameter
	TubeProcessing tubeProcessor = *new TubeProcessing();
	ReactorLink* reactorLink = new ReactorLink();
	int currentPos = 2;

	void setRadLevel(int newRadLevel);
	int getRadLevel();

	void initializeSubsystems();

private:
	Robot();
	static Robot* instance;
	int radLevel = RAD_LEVEL_NONE;

};

#endif