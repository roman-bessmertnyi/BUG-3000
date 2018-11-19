#include "State.h"

StateContext::StateContext(IState *initialState):_state(initialState) {	
};

void StateContext::NextState(void){
	_state = _state->GetNextState();
};

void StateContext::Execute() const {
	_state -> Execute();
};

IState * StateContext::GetState(void) const{
	return _state;
};
