#include "LineFollowToSwitch.h"

/* Constructor */
LineFollowToSwitch::LineFollowToSwitch(int speed) : Command("LineFollowToSwitch") {
	_speed = speed;
}

void LineFollowToSwitch::initialize() {
	pinMode(12, INPUT_PULLUP);
}

void LineFollowToSwitch::execute() {
	drivetrain.drive(0.5, lineTracker.lineError());
}

void LineFollowToSwitch::end() {
	drivetrain.stop();
}

bool LineFollowToSwitch::isFinished() {
	return !digitalRead(12); // Is finished if limit switch is triggered
}
