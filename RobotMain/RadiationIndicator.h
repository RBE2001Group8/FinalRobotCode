#ifndef RADIATIONINDICATOR_H
#define RADIATIONINDICATOR_H

#include <Arduino.h>

class RadiationIndicator {
public:
	RadiationIndicator(int pin, int period);
	void initialize();
	void update();
	void setBlink();
	void setNotBlink();

private:
	const int _ledPin;
	int _period;
	int _onTime;
	bool shouldBlink;
};

#endif
