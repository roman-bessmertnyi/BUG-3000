#ifndef CONTR_H
#define CONTR_H

#include "State.h"

class Controller {
	private: StateContext * _context;
	
	
	public:
		virtual void Execute() = 0;
		virtual IState * GetNextState() const = 0;
};
#endif
