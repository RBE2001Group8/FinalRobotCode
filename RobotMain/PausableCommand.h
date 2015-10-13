/** Extension of the Command class that can be paused
  * at any given time.  When paused, the internal timer
  * does not increment.  When switching between paused or resumed
  * the respective onPause and onResume methods are calld.  When
  * paused, the execute method does not get called
  **/

#ifndef PAUSABLECOMMAND_H
#define PAUSABLECOMMAND_H

#include "Command.h"
#include "RobotPauser.h"
#include "PausableTimer.h"

//#TODO could switch to register a listener to RobotPauser
//So that onPause was called exactly when RobotPauser.pauseRobot was called
//RobotPauser would then need a list of "pausable" objects to call onPause and onResume methods

class PausableCommand : public Command {
public:
	/* Constructors */
	PausableCommand();
	PausableCommand(const String name);

	virtual void initialize() = 0;
	virtual void execute() = 0;
	virtual void end() = 0;
	virtual bool isFinished() = 0;
	/* Event to run when robot is paused */
	virtual void onPause() = 0;
	/* Event to run when robot is resumed */
	virtual void onResume() = 0;

	/* Override methods from the Command class to use PausableTimer */
	virtual void _initialize();
	virtual unsigned long getTime();
	virtual bool cycle();
private:
	bool wasPaused;
	RobotPauser* robotPauser;
};

#endif
