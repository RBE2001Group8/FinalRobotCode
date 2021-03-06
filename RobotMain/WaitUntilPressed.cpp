/** Command to wait until a button is pressed 
  * @author Jordan Burklund
  **/
#include "WaitUntilPressed.h"

/** Constructor
  * @param button Button to wait for
  **/
WaitUntilPressed::WaitUntilPressed() : Command("WaitUntilPressed") {
  curie = Robot::getInstance();
}

/** Does nothing.  Assumes the button is
  * already initialized
  **/
void WaitUntilPressed::initialize() {

}

/** Does nothing while waiting for the button
  **/
void WaitUntilPressed::execute() {

}

/** Does nothing when the button is pressed
  **/
void WaitUntilPressed::end() {

}

/** Command is finished when the button is pressed
  **/
bool WaitUntilPressed::isFinished() {
	return curie->button->isPressed();
}

