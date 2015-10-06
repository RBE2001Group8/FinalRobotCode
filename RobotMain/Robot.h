#ifndef ROBOT_H
#define ROBOT_H

#include "RobotConstants.h"
#include "Drivetrain.h"
#include "LineTracker.h"
#include "Scheduler.h"
#include "UserButton.h"
#include "Roller.h"

class Robot {
public:
	static Robot* getInstance();
	Scheduler *scheduler; 
	Drivetrain drivetrain = *new Drivetrain(LEFT_MOTOR_PIN, RIGHT_MOTOR_PIN);
	LineTracker lineTracker = *new LineTracker();
	UserButton button = *new UserButton(USER_BUTTON_PIN);
	Roller roller = *new Roller();

	void initializeSubsystems();

private:
	Robot();
	static Robot* instance;

};

#endif