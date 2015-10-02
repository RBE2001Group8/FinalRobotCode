#include "LineTracker.h"

LineTracker::LineTracker() {
	
}

/** 
 * Computes the distance that the approximate distance that the line is away from the center of the line sensor in 1/16ths of an inch.
 * @return Float error in 1/16ths of an inch
 **/

float LineTracker::lineError () {
  int s0 = analogRead(0);
  int s1 = analogRead(1);
  int s2 = analogRead(2);
  int s3 = analogRead(3);
  int s4 = analogRead(4);
  int s5 = analogRead(5);
  int s6 = analogRead(6);
  int s7 = analogRead(7);

  return (m1*(s7-s0)+m2*(s6-s1)+m3*(s5-s2)+m4*(s4-s3))/(s0+s1+s2+s3+s4+s5+s6+s7);
}

/**
 * @return True if outer two sensors are on a black line
 **/
bool LineTracker::isAtCross () {
  int s0 = analogRead(0);
  int s7 = analogRead(7);
  return (s0 > 500) && (s7 > 500);
}