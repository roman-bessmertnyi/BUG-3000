#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "misc.h"
#include <string.h>
 
#define RX_BUF_SIZE 80
extern volatile char RX_FLAG_END_LINE;
extern volatile char RXi;
extern volatile char RXc;
extern volatile char RX_BUF[RX_BUF_SIZE];
extern volatile char buffer[80];

void clear_RXBuffer(void);

void usart_init(void);

void USARTSend(char *pucBuffer);
