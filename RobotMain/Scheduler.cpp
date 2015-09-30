/** A Scheduler schedules iterative commands to be run, and then executes them
  * in order.  Commands can be added, and removed, can be scheduled to run in parallel
  * with other commands, and can be scheduled to run persistently.  Credits to PeterMitrano
  * for most of the code
  * @version 1.0
  * @date Sept. 2015
  **/

#include "Scheduler.h"

Scheduler* Scheduler::instance = NULL;

/** Constructor **/
Scheduler::Scheduler() {
}

/** Get the singleton instance of the scheduler
  * @return The instance of the scheduler
  **/
Scheduler* Scheduler::getInstance() {
	if(instance == NULL) {
		instance = new Scheduler();
	}
	return instance;
}

/** Adds a command to the end of the scheduled
  * list of commands.
  * @param command Pointer to the command to add
  **/
void Scheduler::addCommand(Command* command) {
	/* #TODO Should we prevent scheduling the same command?
	if(!commands.contains(command)) {
		commands.add(command);
	} */
	commands.add(command);
}

/** Execute and iteration of the scheduled commands
  **/
void Scheduler::run() {
	//Execute the first scheduled command
	if(commands.size() > 0) {
		Command* command = commands.get(0);
		bool isFinished = command->cycle();
		if(isFinished) {
			commands.remove(0);
		}
	}
	
}


/** Print out the current list of scheduled commands
  **/
void Scheduler::printCommands() {
	if(commands.size() > 0) {
		for(int i=0, n=commands.size(); i<n; i++) {
			Serial.println(commands.get(i)->name);
		}
	} else {
		Serial.println("Scheduler: No Commands Scheduled");
	}
}






/** #TODO

Scheduler.addPersistent
	//Adds a command that is persistent, and will always run.
	//Adds the item to an array, and the array is always iterated through and each run method is called.
	//e.g. a heartbeat command
	//e.g. a Status Light for bluetooth, system state, etc.

Scheduler.add
	//make a new struct, and make the last element point to this
Scheduler.addParallel
	//call add, and set the parallel member variable to true
Scheduler.addSynchronized\
	//call add, and set the parallel member variable to false
Scheduler.remove

Scheduler.run
	//call the first command in the list and call the run method
	if the first command has parallel set to true, call the next command as well, etc.
			//or add both to a dynamically allocated array, and end when all elements have finished=true

	//While iterating through parallel commands, if the command is finished, remove it from the array.  Execution will not contiue
		until the last command is removed.  Not true.  If the synchronized command is removed, the parallel command will still run while the next command is run

	when the command returns finished = true
		remove the current command **/