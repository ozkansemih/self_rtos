#include "se407_SPI.h"              // Keil::Device:StdPeriph Drivers:SPI

void init_SPI1_for_5510(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1  , ENABLE);

	GPIO_InitTypeDef gp_st;
	SPI_InitTypeDef spi_st;

	// 							sck 				 mosi 		miso
	gp_st.GPIO_Pin=GPIO_Pin_5|GPIO_Pin_7|GPIO_Pin_6;
	gp_st.GPIO_OType=GPIO_OType_PP;
	gp_st.GPIO_Mode=GPIO_Mode_AF;
	GPIO_Init(GPIOA,&gp_st);

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_SPI1);

//	SPI1->CR1 |= 0x4; // Master Mode
//	SPI1->CR1 |= 0x31; // fclk / 265
//	SPI1->CR2 |= 0x4;
//	SPI1->CR1 |= 0x40; 

	spi_st.SPI_Mode=SPI_Mode_Master;
	spi_st.SPI_Direction=SPI_Direction_1Line_Tx;
	spi_st.SPI_DataSize=SPI_DataSize_8b;
	spi_st.SPI_CPOL=SPI_CPOL_Low;
	spi_st.SPI_CPHA=SPI_CPHA_1Edge;
	spi_st.SPI_NSS=SPI_NSS_Soft;
	spi_st.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_128;
	spi_st.SPI_FirstBit=SPI_FirstBit_MSB;
	spi_st.SPI_CRCPolynomial = 10;
	SPI_Init(SPI1,&spi_st);
	SPI_Cmd(SPI1,ENABLE);
	
	
}


void init_SPI4_for_5510(){

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI4  , ENABLE);

	GPIO_InitTypeDef gp_st;
	SPI_InitTypeDef spi_st;

	// 							miso 				 sck 		mosi
	gp_st.GPIO_Pin=GPIO_Pin_5|GPIO_Pin_2|GPIO_Pin_6;
	gp_st.GPIO_OType=GPIO_OType_PP;
	gp_st.GPIO_Mode=GPIO_Mode_AF;
	GPIO_Init(GPIOE,&gp_st);

	GPIO_PinAFConfig(GPIOE,GPIO_PinSource5,GPIO_AF_SPI4);
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource6,GPIO_AF_SPI4);
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource2,GPIO_AF_SPI4);

//	SPI1->CR1 |= 0x4; // Master Mode
//	SPI1->CR1 |= 0x31; // fclk / 265
//	SPI1->CR2 |= 0x4;
//	SPI1->CR1 |= 0x40; 

	spi_st.SPI_Mode=SPI_Mode_Master;
	spi_st.SPI_Direction=SPI_Direction_1Line_Tx;
	spi_st.SPI_DataSize=SPI_DataSize_8b;
	spi_st.SPI_CPOL=SPI_CPOL_Low;
	spi_st.SPI_CPHA=SPI_CPHA_1Edge;
	spi_st.SPI_NSS=SPI_NSS_Soft;
	spi_st.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_256;
	spi_st.SPI_FirstBit=SPI_FirstBit_MSB;
	spi_st.SPI_CRCPolynomial = 10;
	SPI_Init(SPI4,&spi_st);
	SPI_Cmd(SPI4,ENABLE);
	
	
}




void init_SPI2_for_5510(){
	
/*
////////////////////////////////////////////
						B-12 CS
B-13 SCK
						B-14 MISO
	B-15 MOSI
////////////////////////////////////////////
*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC , ENABLE);



	GPIO_InitTypeDef gp;
	gp.GPIO_Pin= GPIO_Pin_2 | GPIO_Pin_3; //	C-3 mosi c 2 miso
	gp.GPIO_Mode= GPIO_Mode_AF;
	gp.GPIO_OType = GPIO_OType_PP;
	GPIO_Init( GPIOC, &gp);

	GPIO_PinAFConfig( GPIOC, GPIO_Pin_2, GPIO_AF_SPI2);
	GPIO_PinAFConfig( GPIOC, GPIO_Pin_3, GPIO_AF_SPI2);

	gp.GPIO_Pin= GPIO_Pin_10; //	C-3 mosi c 2 miso
	gp.GPIO_Mode= GPIO_Mode_AF;
	gp.GPIO_OType = GPIO_OType_PP;
	GPIO_Init( GPIOB, &gp);
	GPIO_PinAFConfig( GPIOB, GPIO_Pin_10, GPIO_AF_SPI2);

//	gp.GPIO_Pin=SD_CS_PIN; 	// chip select
//	gp.GPIO_OType=GPIO_OType_PP;
//	gp.GPIO_Mode=GPIO_Mode_OUT;
//	GPIO_Init(SD_CS_PORT,&gp);

	SPI_InitTypeDef spi_st;
	spi_st.SPI_Mode=SPI_Mode_Master;
	spi_st.SPI_Direction=SPI_Direction_1Line_Tx;
	spi_st.SPI_DataSize=SPI_DataSize_8b;
	spi_st.SPI_CPOL=SPI_CPOL_Low;
	spi_st.SPI_CPHA=SPI_CPHA_1Edge;
	spi_st.SPI_NSS=SPI_NSS_Soft;
	spi_st.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_256;
	spi_st.SPI_FirstBit=SPI_FirstBit_MSB;
	spi_st.SPI_CRCPolynomial = 10;
	SPI_Init(SPI2,&spi_st);
	SPI_Cmd(SPI2,ENABLE);







//	GPIO_InitTypeDef gp;
//	gp.GPIO_Pin= GPIO_Pin_13 | GPIO_Pin_15;
//	gp.GPIO_Mode= GPIO_Mode_AF;
//	gp.GPIO_OType = GPIO_OType_PP;
//	GPIO_Init( GPIOB, &gp);

//	GPIO_PinAFConfig( GPIOB, GPIO_Pin_13, GPIO_AF_SPI2);
//	GPIO_PinAFConfig( GPIOB, GPIO_Pin_15, GPIO_AF_SPI2);

//	SPI_InitTypeDef spi_st;
//	spi_st.SPI_Mode=SPI_Mode_Master;
//	spi_st.SPI_Direction=SPI_Direction_1Line_Tx;
//	spi_st.SPI_DataSize=SPI_DataSize_8b;
//	spi_st.SPI_CPOL=SPI_CPOL_Low;
//	spi_st.SPI_CPHA=SPI_CPHA_1Edge;
//	spi_st.SPI_NSS=SPI_NSS_Soft;
//	spi_st.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_128;
//	spi_st.SPI_FirstBit=SPI_FirstBit_MSB;
//	spi_st.SPI_CRCPolynomial = 10;
//	SPI_Init(SPI2,&spi_st);
//	SPI_Cmd(SPI2,ENABLE);
//	SPI2->CR1 |= 0x4; // Master Mode
//	SPI2->CR1 |= 0x31; // fclk / 265
//	SPI2->CR2 |= 0x4;
//	SPI2->CR1 |= 0x40; // Enabling SPI SPI periph

}





void init_SPI1_for_SD(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE , ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1  , ENABLE);

	GPIO_InitTypeDef gp_st;
	SPI_InitTypeDef spi_st;

	// 							sck 				 miso 		mosi
	gp_st.GPIO_Pin=GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	gp_st.GPIO_OType=GPIO_OType_PP;
	gp_st.GPIO_Mode=GPIO_Mode_AF;
	GPIO_Init( SD_CS_PORT , &gp_st);

	// chip select
	gp_st.GPIO_Pin=SD_CS_PIN;
	gp_st.GPIO_OType=GPIO_OType_PP;
	gp_st.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Init( SD_CS_PORT , &gp_st);

	GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_SPI1);
	
	spi_st.SPI_Mode=SPI_Mode_Master;
	spi_st.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	spi_st.SPI_DataSize=SPI_DataSize_8b;
	spi_st.SPI_CPOL=SPI_CPOL_Low;
	spi_st.SPI_CPHA=SPI_CPHA_1Edge;
	spi_st.SPI_NSS=SPI_NSS_Soft;
	spi_st.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_16;
	spi_st.SPI_FirstBit=SPI_FirstBit_MSB;
	spi_st.SPI_CRCPolynomial = 10;
	SPI_Init(SPI1,&spi_st);
	SPI_Cmd(SPI1,ENABLE);

	GPIO_SetBits(SD_CS_PORT , SD_CS_PIN);

}



void spi_send( SPI_TypeDef* spi, char data){

	while(!SPI_I2S_GetFlagStatus( spi , SPI_I2S_FLAG_TXE));
	SPI_I2S_SendData( spi , data);

}

void spi1_TX( char data){

	while(!SPI_I2S_GetFlagStatus( SPI1 , SPI_I2S_FLAG_TXE));
	SPI_I2S_SendData( SPI1 , data);
	delayms(1);

}

void spi4_TX( char data){

	while(!SPI_I2S_GetFlagStatus( SPI4 , SPI_I2S_FLAG_TXE));
	SPI_I2S_SendData( SPI4 , data);

}

uint8_t spi1_RX( uint8_t dump ) {
	uint8_t dummy, data;
	dummy = dump;
	data = 0;

	while(!SPI_I2S_GetFlagStatus( SPI1 , SPI_I2S_FLAG_TXE));
	SPI_I2S_SendData( SPI1 , dummy);
	while(!SPI_I2S_GetFlagStatus( SPI1 , SPI_I2S_FLAG_RXNE));
	data = SPI_I2S_ReceiveData( SPI1 );
	return data;
}

void spi1_RxBytePtr(uint8_t *buff , uint8_t dump) 
{
  *buff = spi1_RX( dump );
}

void spi2_TX( char data){
	while(!SPI_I2S_GetFlagStatus( SPI2 , SPI_I2S_FLAG_TXE));
	SPI_I2S_SendData( SPI2 , data);
}

uint8_t spi2_RX( uint8_t dump ) {
	uint8_t dummy, data;
	dummy = dump;
	data = 0;

	while(!SPI_I2S_GetFlagStatus( SPI2 , SPI_I2S_FLAG_TXE));
	SPI_I2S_SendData( SPI2 , dummy );
	while(!SPI_I2S_GetFlagStatus( SPI2 , SPI_I2S_FLAG_RXNE));
	data = SPI_I2S_ReceiveData( SPI2 );
	return data;
}

void spi2_RxBytePtr(uint8_t *buff , uint8_t dump) 
{
  *buff = spi2_RX( dump );
}


void init_SPI2(){

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC , ENABLE);

	GPIO_InitTypeDef gp;
	gp.GPIO_Pin= GPIO_Pin_2 | GPIO_Pin_3; //	C-3 mosi c 2 miso
	gp.GPIO_Mode= GPIO_Mode_AF;
	gp.GPIO_OType = GPIO_OType_PP;
	GPIO_Init( GPIOC, &gp);

	GPIO_PinAFConfig( GPIOC, GPIO_Pin_2, GPIO_AF_SPI2);
	GPIO_PinAFConfig( GPIOC, GPIO_Pin_3, GPIO_AF_SPI2);

	gp.GPIO_Pin= GPIO_Pin_10; //	C-3 mosi c 2 miso
	gp.GPIO_Mode= GPIO_Mode_AF;
	gp.GPIO_OType = GPIO_OType_PP;
	GPIO_Init( GPIOB, &gp);
	GPIO_PinAFConfig( GPIOB, GPIO_Pin_10, GPIO_AF_SPI2);

	gp.GPIO_Pin=SD_CS_PIN; 	// chip select
	gp.GPIO_OType=GPIO_OType_PP;
	gp.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Init(SD_CS_PORT,&gp);

	SPI_InitTypeDef sp;
	sp.SPI_Mode=SPI_Mode_Master;
	sp.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	sp.SPI_DataSize=SPI_DataSize_8b;
	sp.SPI_CPOL=SPI_CPOL_Low;
	sp.SPI_CPHA=SPI_CPHA_1Edge;
	sp.SPI_NSS=SPI_NSS_Soft;
	sp.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_16;
	sp.SPI_FirstBit=SPI_FirstBit_MSB;
	sp.SPI_CRCPolynomial = 10;
	SPI_Init(SPI2,&sp);
	SPI_Cmd(SPI2,ENABLE);
	
	GPIO_SetBits(SD_CS_PORT,SD_CS_PIN);

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);

//	GPIO_InitTypeDef gp;
//	gp.GPIO_Pin= GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15; //	B-12 CS & B-13 SCK & B-14 MISO & B-15 MOSI
//	gp.GPIO_Mode= GPIO_Mode_AF;
//	gp.GPIO_OType = GPIO_OType_PP;
//	GPIO_Init( GPIOB, &gp);

//	GPIO_PinAFConfig( GPIOB, GPIO_Pin_13, GPIO_AF_SPI2);
//	GPIO_PinAFConfig( GPIOB, GPIO_Pin_14, GPIO_AF_SPI2);
//	GPIO_PinAFConfig( GPIOB, GPIO_Pin_15, GPIO_AF_SPI2);

//	gp.GPIO_Pin=SD_CS_PIN; 	// chip select
//	gp.GPIO_OType=GPIO_OType_PP;
//	gp.GPIO_Mode=GPIO_Mode_OUT;
//	GPIO_Init(SD_CS_PORT,&gp);

	//	sp.SPI_FirstBit = SPI_FirstBit_MSB;
	//	sp.SPI_Mode = SPI_Mode_Master;
	//	sp.SPI_DataSize= SPI_DataSize_8b;
	//	sp.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	//	sp.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
	//	sp.SPI_CPHA = 1;
	//	sp.SPI_CPOL= 1;
	//	sp.SPI_NSS= SPI_NSS_Soft;
	//	SPI_Init(SPI2, &sp);
	//	SPI_Cmd(SPI2,ENABLE);
	
//	SPI_InitTypeDef sp;
//	sp.SPI_Mode=SPI_Mode_Master;
//	sp.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
//	sp.SPI_DataSize=SPI_DataSize_8b;
//	sp.SPI_CPOL=SPI_CPOL_Low;
//	sp.SPI_CPHA=SPI_CPHA_1Edge;
//	sp.SPI_NSS=SPI_NSS_Soft;
//	sp.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_32;
//	sp.SPI_FirstBit=SPI_FirstBit_MSB;
//	sp.SPI_CRCPolynomial = 10;
//	SPI_Init(SPI2,&sp);
//	SPI_Cmd(SPI2,ENABLE);
//	
//	
//	GPIO_SetBits(SD_CS_PORT,SD_CS_PIN);

//	SPI2->CR1 |= 0x4; // Master Mode
//	SPI2->CR1 |= 0x31; // fclk / 265
//	SPI2->CR2 |= 0x4;
//	SPI2->CR1 |= 0x40; // Enabling SPI SPI periph

}
