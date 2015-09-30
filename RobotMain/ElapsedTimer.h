#ifndef ELAPSEDTIMER_H
#define ELAPSEDTIMER_H

class ElapsedTimer {
public:
	ElapsedTimer();
	unsigned long getTimeMillis();
	unsigned long getTimeMicros();
	void resetTimer();

private:
	unsigned long startTimeMillis;
	unsigned long startTimeMicros;

};

#endif
