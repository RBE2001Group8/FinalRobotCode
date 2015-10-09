#ifndef PERSISTENTGETPACKETS_H
#define PERSISTENTGETPACKETS_H

#include "Command.h"
#include "Robot.h"
#include "ReactorLink.h"

class PersistentGetPackets : public Command {
public:
	PersistentGetPackets();
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	ReactorLink* rLink;
};

#endif
