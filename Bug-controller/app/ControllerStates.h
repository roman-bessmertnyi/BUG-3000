#ifndef CS_H
#define CS_H

#include "State.h"
#include "Keyboard.h"
#include "Services.h"
#include "USART_lib.h"

class IActionState: public IState{
	public:
		virtual void Execute() = 0;
		virtual IState * GetNextState() const;
};

class ReadButton: public IState{
	private:
		IActionState * _action;
	public:
		virtual void Execute();
		virtual IState * GetNextState() const;
};

class GoForward: public IActionState{
	public:
		virtual void Execute();
};

class GoBackward: public IActionState{
	public:
		virtual void Execute();
};

class TurnLeft: public IActionState{
	public:
		virtual void Execute();
};

class TurnRight: public IActionState{
	public:
		virtual void Execute();
};

class Stop: public IActionState{
	public:
		virtual void Execute();
};

extern ReadButton readButton;
extern GoForward goForward;
extern GoBackward goBackward;
extern TurnLeft turnLeft;
extern TurnRight turnRight;
extern Stop stop;

#endif
