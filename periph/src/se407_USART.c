#include "se407_USART.h"              // Keil::Device:StdPeriph Drivers:SPI


void usart2_init(){

	//GPIO and USART global structures 
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//USART2 is connected to APB1 Periph Clock Bus and we enabled it.
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	//GPIOA is connected to AHB1 Periph Clock Bus and we enabled it.
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	//Configuration of the GPIO pin for communication
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF; //This is important. We will this pin except of INPUT, OUTPUT and ANALOG so we set as Alternate Function
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2 | GPIO_Pin_3;   //Communicate on PA2 and PA3
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//We set the pin as Push Pull
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP; //And Pull Up. Keep it always on HIGH
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz; //And pin frequency
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//When we set a pin as Alternate Function, we need to specify what function do we use for, here we specified it as USART 2
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

	USART_InitStructure.USART_BaudRate 	              = 9600; //Set the baudrate. Hw many datas will be sent in a second.
	USART_InitStructure.USART_HardwareFlowControl     = USART_HardwareFlowControl_None;  //Do not check the data transmitted 
	USART_InitStructure.USART_Mode                    = USART_Mode_Tx | USART_Mode_Rx;//Data tansmission modes
	USART_InitStructure.USART_Parity                  = USART_Parity_No; // USART parity settings
	USART_InitStructure.USART_StopBits                = USART_StopBits_1; //Set the stop bits
	USART_InitStructure.USART_WordLength              = USART_WordLength_8b;  //we will send the 8bit data
	USART_Init(USART2, &USART_InitStructure);   //and started the this configuration

	USART_Cmd(USART2, ENABLE); //USART is activated and ready to use
	
	#if USART2_USE_IRQ
		USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
		NVIC_InitTypeDef NVIC_InitStructure; //NVIC structure variable

		/* Enable the USARTx Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; // We will use this channel to use USART2 NVIC
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //set the this NVIC priority
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ENABLE the NVIC
		NVIC_Init(&NVIC_InitStructure); //And submit the NVIC with USART2
		USART_Cmd(USART2, ENABLE); //USART is activated and ready to use
	#endif
}

void init_usart1( void){  //PB 6   PB 7 

	//GPIO and USART global structures 
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	//USART2 is connected to APB1 Periph Clock Bus and we enabled it.
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	//GPIOA is connected to AHB1 Periph Clock Bus and we enabled it.
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	//Configuration of the GPIO pin for communication
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF; //This is important. We will this pin except of INPUT, OUTPUT and ANALOG so we set as Alternate Function
	GPIO_InitStructure.GPIO_Pin   =  GPIO_Pin_6 | GPIO_Pin_7;   //Communicate on PB6 and PB7
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//We set the pin as Push Pull
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP; //And Pull Up. Keep it always on HIGH
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz; //And pin frequency
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//When we set a pin as Alternate Function, we need to specify what function do we use for, here we specified it as USART 1
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

	USART_InitStructure.USART_BaudRate 	              = 9600; //Set the baudrate. Hw many datas will be sent in a second.
	USART_InitStructure.USART_HardwareFlowControl     = USART_HardwareFlowControl_None;  //Do not check the data transmitted 
	USART_InitStructure.USART_Mode                    = USART_Mode_Rx | USART_Mode_Tx;//Data tansmission modes
	USART_InitStructure.USART_Parity                  = USART_Parity_No; // USART parity settings
	USART_InitStructure.USART_StopBits                = USART_StopBits_1; //Set the stop bits
	USART_InitStructure.USART_WordLength              = USART_WordLength_8b;  //we will send the 8bit data
	USART_Init(USART1, &USART_InitStructure);   //and started the this configuration

	USART_Cmd(USART1, ENABLE); //USART is activated and ready to use
	
	#if USART1_USE_IRQ
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
		
		NVIC_InitTypeDef NVIC_InitStructure; //NVIC structure variable

		/* Enable the USARTx Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; // We will use this channel to use USART2 NVIC
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //set the this NVIC priority
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ENABLE the NVIC
		NVIC_Init(&NVIC_InitStructure); //And submit the NVIC with USART2
	#endif

}

void init_usart2( void){

	//GPIO and USART global structures 
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	//USART2 is connected to APB1 Periph Clock Bus and we enabled it.
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//GPIOA is connected to AHB1 Periph Clock Bus and we enabled it.
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	//Configuration of the GPIO pin for communication
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF; //This is important. We will this pin except of INPUT, OUTPUT and ANALOG so we set as Alternate Function
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2 | GPIO_Pin_3;   //Communicate on PA2 and PA3
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//We set the pin as Push Pull
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP; //And Pull Up. Keep it always on HIGH
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz; //And pin frequency
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//When we set a pin as Alternate Function, we need to specify what function do we use for, here we specified it as USART 2
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	
	USART_InitStructure.USART_BaudRate 	              = 9600; //Set the baudrate. Hw many datas will be sent in a second.
	USART_InitStructure.USART_HardwareFlowControl     = USART_HardwareFlowControl_None;  //Do not check the data transmitted 
	USART_InitStructure.USART_Mode                    = USART_Mode_Tx | USART_Mode_Rx;//Data tansmission modes
	USART_InitStructure.USART_Parity                  = USART_Parity_No; // USART parity settings
	USART_InitStructure.USART_StopBits                = USART_StopBits_1; //Set the stop bits
	USART_InitStructure.USART_WordLength              = USART_WordLength_8b;  //we will send the 8bit data
	USART_Init(USART2, &USART_InitStructure);   //and started the this configuration

	USART_Cmd(USART2, ENABLE); //USART is activated and ready to use
	
	#if USART2_USE_IRQ
		USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
		NVIC_InitTypeDef NVIC_InitStructure; //NVIC structure variable
	  
		/* Enable the USARTx Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; // We will use this channel to use USART2 NVIC
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4; //set the this NVIC priority
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ENABLE the NVIC
		NVIC_Init(&NVIC_InitStructure); //And submit the NVIC with USART2
		USART_Cmd(USART2, ENABLE); //USART is activated and ready to use
	#endif
}

void init_usart4( void ) {

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	/*-------------------------- GPIO Configuration ----------------------------*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource0, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_UART4);
	/* Connect USART pins to AF */

	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(UART4, &USART_InitStructure);
	USART_Cmd(UART4, ENABLE);
	
	#if USART4_USE_IRQ
		USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
		NVIC_InitTypeDef NVIC_InitStructure; //NVIC structure variable
	  
		/* Enable the USARTx Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn; // We will use this channel to use USART2 NVIC
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4; //set the this NVIC priority
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ENABLE the NVIC
		NVIC_Init(&NVIC_InitStructure); //And submit the NVIC with USART2
		USART_Cmd(UART4, ENABLE); //USART is activated and ready to use
	#endif
}


void USART_Puts(USART_TypeDef* USARTx, volatile char	 *data){
		while(*data){
		while(!(USARTx->SR & 0x00000040));
		USART_SendData(USARTx, *data);
			data++;
		}
}
