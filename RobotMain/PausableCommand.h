/** Extension of the Command class that can be paused
  * at any given time.  When paused, the internal timer
  * does not increment
  **/

#ifndef PAUSABLECOMMAND_H
#define PAUSABLECOMMAND_H

#include "Command.h"
#include "PausableTimer.h"

class PausableCommand : public Command {
public:
	virtual void initialize() = 0;
	virtual void execute() = 0;
	virtual void end() = 0;
	virtual bool isFinished() = 0;
	virtual void onPause() = 0;
	virtual void onResume() = 0;

	virtual void _initialize();
	virtual void _execute();
	virtual void _end();
private:
	bool wasPaused;
};

#endif