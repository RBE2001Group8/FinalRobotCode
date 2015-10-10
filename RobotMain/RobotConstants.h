#ifndef ROBOTCONSTANTS_H
#define ROBOTCONSTANTS_H

const int USER_BUTTON_PIN = 29;

const int LEFT_MOTOR_PIN = 6;
const int RIGHT_MOTOR_PIN = 5;
const int ARM_MOTOR_PIN = 7;
const int POTPIN = 11;
const int ROLLER_MOTOR_PIN = 8;
const int ALIGNMENT_SWITCH_PIN = 22;
const int RADIATION_LED_PIN = 24;

const bool SIDE_A = true;
const bool SIDE_B = false;

//Enumerations for robot radiation levels
//note: different than radiation levels in
//the reactor link class
const int RAD_LEVEL_NEW = 2;
const int RAD_LEVEL_SPENT = 1;
const int RAD_LEVEL_NONE = 0;

//Pins for the Serial3 ports
const int SERIAL3_RX_PIN = 15;
const int SERIAL3_TX_PIN = 14;

const int ARM_POT_OFFSET = 665;


#endif
