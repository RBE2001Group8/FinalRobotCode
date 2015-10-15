/** Subsystem that gets available storage/supply tubes to the given
  * reactor 
  * @author Hans Johnson
  * @date Oct. 2015
  **/

#include "TubeProcessing.h"

/* Constructor */
TubeProcessing::TubeProcessing() {}

int TubeProcessing::getStorageTube(char bitmask, bool sideA) {
  int i;
  if (sideA) {
    for (i = 0; i<4; i++) {
      //Looking for a zero, XOR with 1 will be 1/true if there is a zero there, 0 if there is a 1 in that position
      if (((~bitmask)>>i)&0x01) { 
        break;
      }
    }
  } else {
    for (i = 3; i>=0; i--) {
      //Looking for a zero, XOR with 1 will be 1/true if a zero is there, 0 if a 1 is in that position
      if (((~bitmask)>>i)&0x01) {
        break;
      }
    }
  }
  //(Code assumes first storage tube is number 1)
  return i+1;
}

int TubeProcessing::getFreshRodTube(char bitmask, bool sideA) {
  int i;
  if (sideA) {
    for (i = 0; i<4; i++) {
      //Looking for a zero, AND with 1 will be 1/true if there is a 1, 0 otherwise
      if ((bitmask>>i)&0x01) {
        break;
      }
    }
  } else {
    for (i = 3; i>=0; i--) {
      //Looking for a zero, AND with 1 will be 1/true if there is a 1, 0 otherwise
      if ((bitmask>>i)&0x01) { 
        break;
      }
    }
  }
  return i+1; //(Code assumes first storage tube is number 1)
}