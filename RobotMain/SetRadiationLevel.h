#ifndef SETRADIATIONLEVEL_H
#define SETRADIATIONLEVEL_H

#include "Command.h"
#include "Robot.h"
class SetRadiationLevel : public Command {
public:
	SetRadiationLevel(Robot* robot, int radiationLevel);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	Robot* _robot;
	int _radLevel;
};

#endif