/** An example Pausable Command that drives the drivetrain 
  * forward for 8 seconds, and allows itself to be paused
  * @author Jordan Burklund
  * @date Oct. 2015
  **/

#include "ExamplePauseCommand.h"

ExamplePauseCommand::ExamplePauseCommand() : PausableCommand("ExamplePausable") {
}

/** Initialization **/
void ExamplePauseCommand::initialize() {
	// lazy initialization
	drivetrain = Robot::getInstance()->drivetrain;
}

/** Keep on truckin! **/
void ExamplePauseCommand::execute() {
	drivetrain->drive(0.5, 0);
}

/** Stop the drivetrain when done **/
void ExamplePauseCommand::end() {
	drivetrain->stop();
}

/** Command is finished when 8 unpaused seconds have elapsed **/
bool ExamplePauseCommand::isFinished() {
	return getTime() > 8000;
}

/** Stop the drivetrain when paused **/
void ExamplePauseCommand::onPause() {
	drivetrain->stop();
}

/** Do nothing special on resume **/
void ExamplePauseCommand::onResume() {

}