#include "TubeProcessing.h"

/* Constructor */
TubeProcessing::TubeProcessing() {}

int TubeProcessing::getStorageTube(char bitmask, bool sideA) {
  int i;
  if (sideA) {
    for (i = 0; i<4; i++) {
      if ((bitmask>>i)^0x01) { // Looking for a zero, XOR with 1 will be 1/true if there is a zero there, 0 if there is a 1 in that position
        break;
      }
    }
  } else {
    for (i = 3; i>=0; i--) {
      if ((bitmask>>i)^0x01) { // Looking for a zero, XOR with 1 will be 1/true if there is a zero there, 0 if there is a 1 in that position
        break;
      }
    }
  }
  return i+1; //(Code assumes first storage tube is number 1)
}

int TubeProcessing::getFreshRodTube(char bitmask, bool sideA) {
  int i;
  if (sideA) {
    for (i = 0; i<4; i++) {
      if ((bitmask>>i)&0x01) { // Looking for a zero, AND with 1 will be 1/true if there is a 1, 0 otherwise
        break;
      }
    }
  } else {
    for (i = 3; i>=0; i--) {
      if ((bitmask>>i)&0x01) { // Looking for a zero, AND with 1 will be 1/true if there is a 1, 0 otherwise
        break;
      }
    }
  }
  return i+1; //(Code assumes first storage tube is number 1)
}