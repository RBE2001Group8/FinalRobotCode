/** Encapsulates functionality of several commands
  **/

#include "CommandGroup.h"

CommandGroup::CommandGroup() : Command() {

}

CommandGroup::CommandGroup(const String name) : Command(name) {

}

void CommandGroup::_initialize() {

}

void CommandGroup::_execute() {
	//Execute commands until there is a command that is not parallel
	int size = commands.size();

	Command* command;
	bool isFinished;
	int i = 0;
	while(i<size) {
		//Get the command
		command = commands.get(i);
		isFinished = command->cycle();
		//Remove the command if it is finished
		if(isFinished) {
			commands.remove(i);
			size = commands.size();
			if(command->isParallel()) {
				//don't increment, since just removed
			} else {
				//command was sequential, done with this loop
				break;
			}
		} else {
			if(command->isParallel()) {
				//Command is parallel, increment the pointer
				i++;
			} else {
				//Command is sequential, done with this loop
				break;
			}
		}
	}

}

void CommandGroup::_end() {

}

/** Schedule a command to run in parallel in this group
  * @param cmd Pointer to a command to schedule
  **/
void CommandGroup::addParallel(Command* command) {
	command->setParallel(true);
	commands.add(command);
}

/** Schedule a command to run sequentially in this group
  * @param cmd Pointer to a command to schedule
  **/
void CommandGroup::addSequential(Command* command) {
	command->setParallel(false);
	commands.add(command);
}