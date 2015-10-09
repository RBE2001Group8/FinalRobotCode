#ifndef PERSISTENTSENDRADALERTS_H
#define PERSISTENTSENDRADALERTS_H

#include "Command.h"
#include "Robot.h"
#include "RobotConstants.h"
#include "ReactorLink.h"
#include "ElapsedTimer.h"

class PersistentSendRadAlerts : public Command {
public:
	PersistentSendRadAlerts();
	void initialize();
	void execute();
	void end();
	bool isFinished();

private:
	ElapsedTimer alertTimer;
	Robot* robot;
	ReactorLink* rLink;
	const int period = 2000; //Time between radiation broadcasts in msec
};

#endif
