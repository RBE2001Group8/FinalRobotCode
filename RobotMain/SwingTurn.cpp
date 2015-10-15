/** Command to execute a swing turn with the robot where only the outer wheel spins
  * for a given amount of time
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "SwingTurn.h"

/** Constructor 
 * @param turn Turning rate of robot -1.0 is full left turn, 1.0 is full right
 * @param duration Length of time in milliseconds to turn for
 **/
SwingTurn::SwingTurn(float turn, int duration) : PausableCommand("SwingTurn") {
	_turn = turn;
	_duration = duration;
	curie = Robot::getInstance();
}

void SwingTurn::initialize() {}

void SwingTurn::execute() {
	curie->drivetrain->swingTurn(_turn);
}

void SwingTurn::end() {
	curie->drivetrain->stop();
}

bool SwingTurn::isFinished() {
	return getTime() > _duration; 
}

/** Stop the drivetrain when paused **/
void SwingTurn::onPause() {
	curie->drivetrain->stop();
}

/** Nothing special on resume **/ 
void SwingTurn::onResume() {}
