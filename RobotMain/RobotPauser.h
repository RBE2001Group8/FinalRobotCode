/** Singleton class that abstracts pausing and resuming a robot
  * and holding the current paused/resumed state of the robot.
  * This class also interfaces with PausableTimer and pauses/resumes
  * the timer appropriately.  It is intended to be the only class that
  * should pause/resume the PausableTimer
  * @author Jordan Burklund
  * @date Oct. 2015S
  **/

#ifndef ROBOTPAUSER_H
#define ROBOTPAUSER_H

#include "PausableTimer.h"
#include "Arduino.h"

class RobotPauser {
public:
	/** Get an instance of the Robot Pauser
	  * @return Pointer to the singleton instance
	  **/
	static RobotPauser* getInstance();

	/** Set the flag to pause the robot **/
	void pauseRobot();

	/** Set the flag to resume the robot **/
	void resumeRobot();

	/** Check if the flag is set to be paused
	  * @return True if the robot is paused
	  **/
	bool isPaused();

private:
	/* Private constructor for Singleton instance */
	RobotPauser();
	/* Pointer to the singleton instance */
	static RobotPauser* instance;
	/* Flag for current pause/resume state */
	static bool paused;
};

#endif