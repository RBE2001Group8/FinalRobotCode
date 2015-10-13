#ifndef COMMANDGROUP_H
#define COMMANDGROUP_H

#include "Command.h"
#include "LinkedList.h"

class CommandGroup : public Command {
public:
	/* Constructor */
	CommandGroup();
	CommandGroup(const String name);

	/* Require the subclass to implement all of these */
	virtual void initialize() = 0;
	virtual void execute() = 0;
	virtual void end() = 0;
	virtual bool isFinished() = 0;

	/* Override these methods from Command */
	virtual void _initialize();
	virtual void _execute();
	virtual void _end();

	void addParallel(Command* command);
	void addSequential(Command* command);

private:
	LinkedList<Command*> commands;

};

#endif