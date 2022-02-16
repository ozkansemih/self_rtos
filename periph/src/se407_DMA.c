

#include "se407_DMA.h"
extern uint8_t dma_buffer [ 32];
extern uint8_t semihh [ 32];

void init_DMA1_for_USART2 ( void ) {

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

	NVIC_InitTypeDef NVIC_InitStructure;
	/* Configure the Priority Group to 2 bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	/* Enable the UART4 RX DMA Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	DMA_InitTypeDef dma_st;
	DMA_DeInit( DMA1_Stream5);

	dma_st.DMA_BufferSize = sizeof( semihh );
	dma_st.DMA_Channel = DMA_Channel_4;
	dma_st.DMA_DIR = DMA_DIR_PeripheralToMemory ;
	dma_st.DMA_FIFOMode = DMA_FIFOMode_Enable ;
	dma_st.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
	dma_st.DMA_Memory0BaseAddr = (uint32_t )semihh;
	dma_st.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	dma_st.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	dma_st.DMA_MemoryInc = DMA_MemoryInc_Enable ;
	dma_st.DMA_Mode = DMA_Mode_Circular;
	dma_st.DMA_PeripheralBaseAddr = (uint32_t) &USART2->DR;
	dma_st.DMA_PeripheralBurst =  DMA_PeripheralBurst_Single;
	dma_st.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	dma_st.DMA_PeripheralInc = DISABLE;
	dma_st.DMA_Priority = DMA_Priority_High;
	DMA_Init(DMA1_Stream5 , &dma_st );
	USART_DMACmd( USART2, USART_DMAReq_Rx,ENABLE );
	DMA_ITConfig(DMA1_Stream5, DMA_IT_TC, ENABLE);
	DMA_ITConfig(DMA1_Stream5, DMA_IT_HT, ENABLE);
	DMA_Cmd ( DMA1_Stream5 , ENABLE );

}

void init_DMA2_for_USART1 ( void ) {

	//	RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_DMA1 ,ENABLE );
	RCC_AHB1PeriphResetCmd(RCC_AHB1Periph_DMA2, ENABLE);
	NVIC_InitTypeDef NVIC_InitStructure;
	/* Configure the Priority Group to 2 bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	/* Enable the UART4 RX DMA Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	DMA_InitTypeDef dma_st;
	DMA_DeInit( DMA2_Stream2);

	dma_st.DMA_BufferSize = sizeof( semihh );
	dma_st.DMA_Channel = DMA_Channel_4;
	dma_st.DMA_DIR = DMA_DIR_PeripheralToMemory ;
	dma_st.DMA_FIFOMode = DMA_FIFOMode_Enable ;
	dma_st.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
	dma_st.DMA_Memory0BaseAddr = (uint32_t )semihh;
	dma_st.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	dma_st.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	dma_st.DMA_MemoryInc = DMA_MemoryInc_Enable ;
	dma_st.DMA_Mode = DMA_Mode_Circular;
	dma_st.DMA_PeripheralBaseAddr = (uint32_t) &USART1->DR;
	dma_st.DMA_PeripheralBurst =  DMA_PeripheralBurst_Single;
	dma_st.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	dma_st.DMA_PeripheralInc = DISABLE;
	dma_st.DMA_Priority = DMA_Priority_High;
	DMA_Init(DMA2_Stream2 , &dma_st );
	USART_DMACmd( USART1, USART_DMAReq_Rx,ENABLE );
	DMA_ITConfig(DMA2_Stream2, DMA_IT_TC, ENABLE);
	DMA_ITConfig(DMA2_Stream2, DMA_IT_HT, ENABLE);
	DMA_Cmd ( DMA2_Stream2 , ENABLE );

}

uint8_t Buffer[32];

void init_DMA1_for_USART4( void ) {

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
	NVIC_InitTypeDef NVIC_InitStructure;
	/* Configure the Priority Group to 2 bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	/* Enable the UART4 RX DMA Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	DMA_InitTypeDef DMA_InitStructure;
	DMA_DeInit(DMA1_Stream2);
	DMA_InitStructure.DMA_Channel = DMA_Channel_4;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory; // Receive
	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Buffer;
	DMA_InitStructure.DMA_BufferSize = (uint16_t)sizeof(Buffer);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&UART4->DR;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Enable;
	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
	DMA_Init(DMA1_Stream2, &DMA_InitStructure);
	/* Enable the USART Rx DMA request */
	USART_DMACmd(UART4, USART_DMAReq_Rx, ENABLE);
	/* Enable DMA Stream Half Transfer and Transfer Complete interrupt */
	DMA_ITConfig(DMA1_Stream2, DMA_IT_TC, ENABLE);
	DMA_ITConfig(DMA1_Stream2, DMA_IT_HT, ENABLE);
	/* Enable the DMA RX Stream */
	DMA_Cmd(DMA1_Stream2, ENABLE);

}












