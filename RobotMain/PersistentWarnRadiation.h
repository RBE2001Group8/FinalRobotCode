#ifndef PERSISTENTWARNRADIATION_H
#define PERSISTENTWARNRADIATION_H

#include "Command.h"
#include "Robot.h"
#include "RadiationIndicator.h"

class PersistentWarnRadiation : public Command {
public:
	PersistentWarnRadiation(Robot *robot, RadiationIndicator *radInd);
	void initialize();
	void execute();
	void end();
	bool isFinished();

private:
	Robot *_robot;
	RadiationIndicator *_radInd;
};

#endif