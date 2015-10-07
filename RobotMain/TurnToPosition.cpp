#include "TurnToPosition.h"

/* Constructor */
/** Turns toward the next position based on where the robot is currently
 * @param turn Turning rate of robot
 * @param duration Length of time in milliseconds to turn for
 * @param drivetrain Drivetrain object to use for driving
 * @param currentPos Position of robot on the field at the beginning of the command
 * @param nextPos Position the robot should be pointing toward when the command finishes
 **/
TurnToPosition::TurnToPosition(float turn, int duration, Drivetrain drive, int *currentPos, int *nextPos) : Command("TurnToPosition"), drivetrain(drive) {
	deltaPos = *nextPos-*currentPos;
	if (deltaPos != 0) {
		_turn = abs(turn)*deltaPos/abs(deltaPos);
		_duration = duration;
	} else {
		_turn = turn;
		_duration = duration*0.75;
	}
	
}

void TurnToPosition::initialize() {
	drivetrain.initialize();
	Serial.begin(9600);
	pinMode(24, OUTPUT);
}

void TurnToPosition::execute() {
	prevCenter = lineTracker.centerOnLine();
	if (deltaPos != 0) {
		drivetrain.swingTurn(_turn);
	} else {
		drivetrain.pointTurn(_turn);
	}
}

void TurnToPosition::end() {
	drivetrain.stop();
}

bool TurnToPosition::isFinished() {
	if(getTime() > 1000) {
		digitalWrite(24, HIGH);
	} else {
		digitalWrite(24, LOW);
	}
	return (getTime() > 1000) && (lineTracker.centerOnLine() && (!prevCenter)); 
}
