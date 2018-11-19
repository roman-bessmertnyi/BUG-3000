#include "stm32f10x.h"
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "misc.h"												// Framework

void init_keyboard(void);
uint8_t keypadGetKey(void);

void btn_init_RED (void);
uint32_t btn_RED_test_GND_connect_A0(void);
uint32_t btn_RED_test_GND_connect_A1(void);
uint32_t btn_RED_test_GND_connect_A2(void);
uint32_t btn_RED_test_GND_connect_A3(void);
int buttonHandler(void);
