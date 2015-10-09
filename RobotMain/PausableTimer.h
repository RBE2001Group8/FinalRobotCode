#ifndef PAUSABLETIMER_H
#define PAUSABLETIMER_H

#include <TimerOne.h>

static volatile bool _SHOULD_PAUSE = false;
static volatile unsigned long _PAUSE_TIME_COUNT = 0;

unsigned long getPauseMillis();
void initializePauseTimer();
void incrementPauseTime();
void pauseTimer();
void resumeTimer();

#endif