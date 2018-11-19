#include "Services.h"
#include "Keyboard.h"
#include "tm1637.h"
#include "USART_lib.h"
#include "timer_lib.h"
#include "misc.h"
#include <string.h>

int main()
{
	// Set System clock
	SetSysClockTo72();
	
	//usart init
	usart_init();
	
	//void init_keyboard(void); //complex keyboard
	btn_init_RED(); //simple buttons
	
	while(1){
		controlStateContext.Execute();
		controlStateContext.NextState();
	}
}
