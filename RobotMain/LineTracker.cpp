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
  //Read all of the sensors
  int values[8];
  values[0] = analogRead(0);
  values[1] = analogRead(1);
  values[2] = analogRead(2);
  values[3] = analogRead(3);
  values[4] = analogRead(4);
  values[5] = analogRead(5);
  values[6] = analogRead(6);
  values[7] = analogRead(7);

  //Sum all of the sensors that detect a line
  int numSensorsOnLine = 0;
  for(int i=0; i<8; i++) {
    if(values[i] > 500) {
      numSensorsOnLine++;
    }
  }
  //Sensor is on the line if 3 or more detect a line
  return numSensorsOnLine >= 3;
}

bool LineTracker::rearOnLine () {
  int left = analogRead(10);
  int right = analogRead(9);
  return (left > 500 && right > 500);
}

bool LineTracker::oneRearOnLine () {
  int left = analogRead(10);
  int right = analogRead(9);
  return (left > 500 || right > 500);
}

int LineTracker::leftRear() {
  return analogRead(10);
}

int LineTracker::rightRear() {
  return analogRead(9);
}

bool LineTracker::centerOnLine () {
  int s3 = analogRead(3);
  int s4 = analogRead(4);
  int s2 = analogRead(2);
  int s5 = analogRead(5);
  return (s3 > 500) || (s2 > 500);// || (s4 > 500) || (s5 > 500);
}