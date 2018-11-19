#include "ControllerStates.h"

#define BUTTON_FORWARD 0
#define BUTTON_BACKWARD 1
#define BUTTON_RIGHT 2
#define BUTTON_LEFT 3


ReadButton readButton;
GoForward goForward;
GoBackward goBackward;
TurnLeft turnLeft;
TurnRight turnRight;
Stop stop;


IState * ReadButton::GetNextState() const {
	if(_action == 0)
	{
		return &stop;
	}
	else
	{
		return _action;
	}
};

IState * IActionState::GetNextState() const {
	return &readButton;
};

void ReadButton::Execute(){
	//Get button placeholder
	//int button = BUTTON_LEFT;
	
	//Get button simple
	int button = buttonHandler() - 1;
	
	switch (button) 
	{
		case BUTTON_FORWARD:
			_action = &goForward;
			break;
		case BUTTON_BACKWARD:
			_action = &goBackward;
			break;
		case BUTTON_RIGHT:
			_action = &turnRight;
			break;
		case BUTTON_LEFT:
			_action = &turnLeft;
			break;
		default:
			_action = 0;
	}
};

void GoForward::Execute(){
	USARTSend((char*)"FORWARD\r");
};

void GoBackward::Execute(){
	USARTSend((char*)"BACKWARD\r");
};

void TurnLeft::Execute(){
	USARTSend((char*)"LEFT\r");
};

void TurnRight::Execute(){
	USARTSend((char*)"RIGHT\r");
};

void Stop::Execute(){
	USARTSend((char*)"STOP\r");
};
