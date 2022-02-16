#include "se407_GPIO.h"              // Keil::Device:StdPeriph Drivers:SPI


void init_user_button( void ){
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	GPIO_InitTypeDef gp;
	gp.GPIO_Pin = GPIO_Pin_0;
	gp.GPIO_Mode = GPIO_Mode_IN;
	gp.GPIO_PuPd = GPIO_PuPd_DOWN;
	gp.GPIO_OType = GPIO_OType_PP;
	gp.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gp);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

void init_leds( void ){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE);
	GPIO_InitTypeDef gp;
	gp.GPIO_Pin= GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;
	gp.GPIO_Mode = GPIO_Mode_OUT;
	gp.GPIO_OType= GPIO_OType_PP;
	gp.GPIO_PuPd= GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD,&gp);

}
