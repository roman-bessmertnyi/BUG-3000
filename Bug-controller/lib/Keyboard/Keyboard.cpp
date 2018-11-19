#include "Keyboard.h"	

void init_keyboard(void){
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);// BUS is ON
    
    GPIO_InitTypeDef      KEYPAD_COL_B_STRUCT; // REDY for struct 
    KEYPAD_COL_B_STRUCT.GPIO_Pin =     GPIO_Pin_13 |    // KEEP HARD PINS 
                                       GPIO_Pin_14 |
                                       GPIO_Pin_15;
    KEYPAD_COL_B_STRUCT.GPIO_Mode = GPIO_Mode_Out_OD;
	KEYPAD_COL_B_STRUCT.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &KEYPAD_COL_B_STRUCT);
    
     // Init row
    GPIO_InitTypeDef KEYPAD_ROW_B_STRUCT;
	KEYPAD_ROW_B_STRUCT.GPIO_Pin =     GPIO_Pin_12 |    // KEEP HARD PINS 
                                       GPIO_Pin_11 |
                                       GPIO_Pin_10 |
                                       GPIO_Pin_1;
	KEYPAD_ROW_B_STRUCT.GPIO_Mode = GPIO_Mode_IPU;
	KEYPAD_ROW_B_STRUCT.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &KEYPAD_ROW_B_STRUCT);
}


uint8_t keypadGetKey(void)
{
	// Scan column 0 (column 0 pin is grounded, other column pins is open drain)
	GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	GPIO_SetBits(GPIOB,GPIO_Pin_14);
	GPIO_SetBits(GPIOB, GPIO_Pin_15);
	// Read rows
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1))
		return '1';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10))
		return '4';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11))
		return '7';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12))
		return '*';
		
	// Scan column 1 (column 1 pin is grounded, other column pins is open drain)
	GPIO_SetBits(GPIOB, GPIO_Pin_13);
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	GPIO_SetBits(GPIOB, GPIO_Pin_15);
	// Read rows
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1))
		return '2';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10))
		return '5';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11))
		return '8';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12))
		return '0';
		
	// Scan column 2 (column 2 pin is grounded, other column pins is open drain)
	GPIO_SetBits(GPIOB, GPIO_Pin_13);
	GPIO_SetBits(GPIOB, GPIO_Pin_14);
	GPIO_ResetBits(GPIOB, GPIO_Pin_15);
	// Read rows
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1))
		return '3';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10))
		return '6';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11))
		return '9';
	if (!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12))
		return '#';
	
	return 'e';
}

void btn_init_RED (void){
    //кнопка
   
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); // (1)
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

// for tetsing this lib !!!
uint32_t btn_RED_test_GND_connect_A0(void){
	if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))// Catch from GND 
	{//slow, press and connect GPIOC 13 to GND 
		 return 1;
	}		
	else 
	{//fast no press !!!
		return 0;    
	}
	
}

uint32_t btn_RED_test_GND_connect_A1(void){
	if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1))// Catch from GND 
	{//slow, press and connect GPIOC 13 to GND 
		 return 1;
	}		
	else 
	{//fast no press !!!
		return 0;    
	}
	
} 

uint32_t btn_RED_test_GND_connect_A2(void){
	if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2))// Catch from GND 
	{//slow, press and connect GPIOC 13 to GND 
		 return 1;
	}		
	else 
	{//fast no press !!!
		return 0;    
	}
	
} 

uint32_t btn_RED_test_GND_connect_A3(void){
	if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3))// Catch from GND 
	{//slow, press and connect GPIOC 13 to GND 
		 return 1;
	}		
	else 
	{//fast no press !!!
		return 0;    
	}
	
}

int buttonHandler(void)
{
	if (btn_RED_test_GND_connect_A0()) 
	{
		return 1;
	}
	
	
	if (btn_RED_test_GND_connect_A1()) 
	{
		return 2;
	}
	
	
	if (btn_RED_test_GND_connect_A2()) 
	{
		return 3;
	}
	//2
	
	if (btn_RED_test_GND_connect_A3()) 
	{
		return 4;
	}
	return 0;
}
