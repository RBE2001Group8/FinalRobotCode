#ifndef WAITUNTILPRESSED_H
#define WAITUNTILPRESSED_H

#include "UserButton.h"
#include "Command.h"

class WaitUntilPressed : public Command {
public:
	WaitUntilPressed(UserButton button);
	void initialize();
	void execute();
	void end();
	bool isFinished();
private:
	UserButton _button;
};

#endif
