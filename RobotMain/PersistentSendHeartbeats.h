#ifndef PERSISTENTSENDHEARTBEATS_H
#define PERSISTENTSENDHEARTBEATS_H

#include "Command.h"
#include "Robot.h"
#include "ReactorLink.h"
#include "ElapsedTimer.h"

class PersistentSendHeartbeats : public Command {
public:
	PersistentSendHeartbeats();
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	ElapsedTimer hbTimer;
	ReactorLink* rLink;
	const int period = 1500;  //Time between heartbeats in msec
	
};

#endif