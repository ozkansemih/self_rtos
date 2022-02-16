#ifndef se407_USART_H_

#define se407_USART_H_


#include "stm32f4xx_usart.h"            // Keil::Device:StdPeriph Drivers:USART
#include "stm32f4xx_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO



void usart2_init( void );

void init_usart2( void);
void init_usart1( void);
void init_usart4( void );

void USART_Puts(USART_TypeDef* USARTx, volatile char	 *data);

#endif
