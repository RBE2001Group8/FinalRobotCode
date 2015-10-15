/** Abstraction for the Pololu Line sensor to detect
  * where the line is in relation to the sensor, intersections,
  * and if it is centered on the line
  * @author Jordan Burklund
  * @author Hans Johnson
  * @date Sept. 2015
  **/

#include "LineTracker.h"

LineTracker::LineTracker() {}

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

  //Compute the weigted sum to find the position
  return (m1*(s7-s0)+m2*(s6-s1)+m3*(s5-s2)+m4*(s4-s3))/(s0+s1+s2+s3+s4+s5+s6+s7);
}

/** Detects if the sensor is at an instersection
 * @return True if 3 or more sensors detect a line
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

/** Check if either of the two center sensors are on the line
  * @return True if the center of the sensor is on the line
  **/
bool LineTracker::centerOnLine () {
  int s3 = analogRead(3);
  int s2 = analogRead(2);
  return (s3 > 500) || (s2 > 500);
}