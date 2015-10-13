/** An example of using the PausableCommand interface
  * for defining a command that is pausable
  **/

#ifndef EXAMPLEPAUSECOMMAND_H
#define EXAMPLEPAUSECOMMAND_H

#include "PausableCommand.h"
#include "Robot.h"
#include "Drivetrain.h"

class ExamplePauseCommand : public PausableCommand {
public:
	ExamplePauseCommand();
	void initialize();
	/** Drive the drivetrain forward for 8 seconds **/
	void execute();
	void end();
	/** Done when 8 unpaused seconds have elapsed **/
	bool isFinished();
	/** Stop the drivetrain **/
	void onPause();
	/** Nothing special to do on resume **/
	void onResume();
private:
	Drivetrain* drivetrain;
};

#endif