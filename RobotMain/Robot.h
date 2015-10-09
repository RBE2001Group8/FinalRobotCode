#ifndef ROBOT_H
#define ROBOT_H

#include "RobotConstants.h"
#include "Drivetrain.h"
#include "LineTracker.h"
#include "Scheduler.h"
#include "UserButton.h"
#include "Roller.h"
#include "RadiationIndicator.h"
#include "ReactorLink.h"

//#TODO Hack to fix cyclical dependency
class RadiationIndicator;

class Robot {
public:
	static Robot* getInstance();
	//#TODO Code Clean up: switch classes to pointers, like RadInd
	Scheduler *scheduler; 
	Drivetrain drivetrain = *new Drivetrain(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);
	LineTracker lineTracker = *new LineTracker();
	UserButton button = *new UserButton(USER_BUTTON_PIN);
	Roller roller = *new Roller();
	RadiationIndicator* radInd = new RadiationIndicator(RADIATION_LED_PIN, 750);
	ReactorLink* reactorLink = new ReactorLink();


	void setRadLevel(int newRadLevel);
	int getRadLevel();

	void initializeSubsystems();

private:
	Robot();
	static Robot* instance;
	int radLevel = RAD_LEVEL_NONE;

};

#endif