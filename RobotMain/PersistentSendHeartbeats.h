#ifndef PERSISTENTSENDHEARTBEATS_H
#def PERSISTENTSENDHEARTBEATS_H

#include "Robot.h"
#include "ReactorLink.h"

class PersistentSendHeartbeats : public Command {
public:
	PersistentSendHeartbeats();
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	
};

#endif