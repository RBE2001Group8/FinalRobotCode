#include "LineFollowToSwitch.h"

/* Constructor */
LineFollowToSwitch::LineFollowToSwitch(int speed) : Command("LineFollowToSwitch") {
	_speed = speed;
}

void LineFollowToSwitch::initialize() {
	pinMode(12, INPUT_PULLUP);
}

void LineFollowToSwitch::execute() {
	leftMotor.write(1500-lineError()*30-300*_speed);
    rightMotor.write(1500-lineError()*30+300*_speed);
}

void LineFollowToSwitch::end() {
	leftMotor.write(1500);
	rightMotor.write(1500);
}

bool LineFollowToSwitch::isFinished() {
	return !digitalRead(12); // Is finished if limit switch is triggered
}

float lineError () {
  int s0 = analogRead(0);
  int s1 = analogRead(1);
  int s2 = analogRead(2);
  int s3 = analogRead(3);
  int s4 = analogRead(4);
  int s5 = analogRead(5);
  int s6 = analogRead(6);
  int s7 = analogRead(7);

  return (m1*(s0-s7)+m2*(s1-s6)+m3*(s2-s5)+m4*(s3-s4))/(s0+s1+s2+s3+s4+s5+s6+s7);
}