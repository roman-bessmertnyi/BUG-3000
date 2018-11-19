#include "tm1637.h"
#include "USART_lib.h"
#include "timer_lib.h"
#include "misc.h"
#include <string.h>

extern "C" void USART1_IRQHandler(void)
{
    if ((USART1->SR & USART_FLAG_RXNE) != (u16)RESET)
    {
            RXc = USART_ReceiveData(USART1);
            RX_BUF[RXi] = RXc;
            RXi++;
 
            if (RXc != 13) {
                if (RXi > RX_BUF_SIZE-1) {
                    clear_RXBuffer();
                }
            }
            else {
                RX_FLAG_END_LINE = 1;
            }
    }
}

int main()
{
	// Set System clock
	SetSysClockTo72();
	
	//usart init
	usart_init();
	
	//display init
	TM1637_init();	
  TM1637_brightness(BRIGHT_TYPICAL); 
	TM1637_display_all(404);
	
	while(1){
		if (RX_FLAG_END_LINE == 1) {
			// Reset END_LINE Flag
			RX_FLAG_END_LINE = 0;

			if (strncmp((char*)RX_BUF, "FORWARD\r", 8) == 0) {
					TM1637_display_all(1);
			}

			if (strncmp((char*)RX_BUF, "BACKWARD\r", 9) == 0) {
					TM1637_display_all(2);
			}
			
			if (strncmp((char*)RX_BUF, "RIGHT\r", 6) == 0) {
					TM1637_display_all(3);
			}
			
			if (strncmp((char*)RX_BUF, "LEFT\r", 5) == 0) {
					TM1637_display_all(4);
			}
			
			if (strncmp((char*)RX_BUF, "STOP\r", 5) == 0) {
					TM1637_display_all(5);
			}

			clear_RXBuffer();
		}
	}
}
