#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Command.h"
#include "LinkedList.h"

class Scheduler {
public:
	static Scheduler* getInstance();
	void addCommand(Command *command);
	void printCommands();
	void run();
	//void addPersistent(Command cmd);
	//void addParallel(Command cmd);
	//void addSynchronized(Command cmd);
	//void remove(Command cmd);

private:
	Scheduler();
	static Scheduler* instance; 
	LinkedList<Command *> commands;


};

#endif