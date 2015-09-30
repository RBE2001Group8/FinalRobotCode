#ifndef ROBOT_H
#define ROBOT_H

#include "Drivetrain.h"
#include "LineTracker.h"
#include "Scheduler.h"

class Robot {
public:
	static Robot* getInstance();
	Scheduler *scheduler; 
	Drivetrain *drivetrain;
	LineTracker *lineTracker;

private:
	Robot();
	static Robot* instance;

};

#endif