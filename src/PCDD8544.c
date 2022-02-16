
#include "PCD8544.H"
#include "delayy.H"



void init_LCD_pins( void ){

	if( PCD8544_PORT == GPIOA)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
	else if( PCD8544_PORT == GPIOB)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB , ENABLE);
	else if( PCD8544_PORT == GPIOC)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC , ENABLE);
	else if( PCD8544_PORT == GPIOD)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE);
	else if( PCD8544_PORT == GPIOE)
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE , ENABLE);
		
	if ( PCD8544_PORT != PCD8544_CE_PORT ) {
		if( PCD8544_CE_PORT == GPIOA)
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
		else if( PCD8544_CE_PORT == GPIOB)
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB , ENABLE);
		else if( PCD8544_CE_PORT == GPIOC)
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC , ENABLE);
		else if( PCD8544_CE_PORT == GPIOD)
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE);
		else if( PCD8544_CE_PORT == GPIOE)
			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE , ENABLE);
	}	
		
	GPIO_InitTypeDef gp;
	gp.GPIO_Pin= PCD8544_RST_PIN | PCD8544_DC_PIN |PCD8544_BL_PIN;
	gp.GPIO_Mode = GPIO_Mode_OUT;
	gp.GPIO_OType= GPIO_OType_PP;
	gp.GPIO_PuPd= GPIO_PuPd_NOPULL;
	GPIO_Init(PCD8544_PORT,&gp);
	
	// chip select
	gp.GPIO_Pin=PCD8544_CE_PIN;
	gp.GPIO_OType=GPIO_OType_PP;
	gp.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_Init(PCD8544_CE_PORT,&gp);
}


void clear_Screen(){
	GPIO_SetBits( PCD8544_PORT , PCD8544_DC_PIN);
	GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);
	int i=0;
	for ( i =0; i<504;i++){
//		spi1_TX( 0x00);
	#if SPI_2
		spi2_TX( 0x00);

	#elif SPI_1
		spi1_TX( 0x00);
	#elif SPI_4
		spi4_TX( 0x00);
	#endif	
	}
}

uint32_t get_RNG( int top_lim, int bot_lim ){
	while( RNG_GetFlagStatus(RNG_FLAG_DRDY) != SET );
	return bot_lim + RNG_GetRandomNumber()%(top_lim-bot_lim);
}

void PCD8544_set_contrast(){
	GPIO_ResetBits( PCD8544_PORT, PCD8544_DC_PIN);
	GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);

	#if SPI_2
	spi2_TX( 0x21);
	spi2_TX( 0xC6);
	#elif SPI_1
	spi1_TX( 0x21);
	spi1_TX( 0xC6);
		#elif SPI_4
	spi4_TX( 0x21);
	spi4_TX( 0xC6);
	#endif	
}
void PCD8544_set_display(){
	GPIO_ResetBits( PCD8544_PORT, PCD8544_DC_PIN);
	GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);

	#if SPI_2
	spi2_TX( 0x20);
	spi2_TX( 0x0C);
	#elif SPI_1
	spi1_TX( 0x20);
	spi1_TX( 0x0C);
		#elif SPI_4
	spi4_TX( 0x20);
	spi4_TX( 0x0C);
	#endif	
}

void reset_Screen(){
	GPIO_SetBits ( PCD8544_PORT , PCD8544_RST_PIN);   // reset screen start
	GPIO_ResetBits ( PCD8544_PORT , PCD8544_RST_PIN);
	GPIO_SetBits ( PCD8544_PORT , PCD8544_RST_PIN);
	clear_Screen();
}

void init_Screen( void ){
	reset_Screen();
//	clear_Screen();
	GPIO_SetBits( PCD8544_PORT , PCD8544_BL_PIN);
	PCD8544_set_contrast();
	PCD8544_set_display();
	delayms(1);

}

void put_char_nOKIA ( char ch){
	GPIO_SetBits( PCD8544_PORT , PCD8544_DC_PIN);
	GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);
	int i=0;
	while( i< 6){
	#if SPI_2
		spi2_TX( ASCII[ch-0x20][i]);
	#elif SPI_1
		spi1_TX( ASCII[ch-0x20][i]);
			#elif SPI_4
		spi4_TX( ASCII[ch-0x20][i]);
	#endif	
		i++;
	}
}

void put_str_nOKIA ( char* ch){
	while( *ch ){
		put_char_nOKIA(*ch++);
	}

}

void set_adress(int x, int y){

	int new_X =0;
	int new_Y =0;
	
	new_Y = 0x40 | y;
	new_X = 0x80 | x;
	GPIO_ResetBits( PCD8544_PORT, PCD8544_DC_PIN);
	GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);
	
	#if SPI_2
	spi2_TX( new_Y);
	spi2_TX( new_X);	
	#elif SPI_1
	spi1_TX( new_Y);
//		GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);
//	GPIO_SetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);
//		GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);
	GPIO_ResetBits(PCD8544_CE_PORT , PCD8544_CE_PIN);

	spi1_TX( new_X);		
		#elif SPI_4
	spi4_TX( new_Y);
	spi4_TX( new_X);	
	#endif	
}

void put_str_wAdress(int x, int y, char * str){
	set_adress( x,y);
	put_str_nOKIA( str);
}

void put_char_wAdress(int x, int y, char str){
	set_adress( x,y);
	put_char_nOKIA( str);
}
void put_str_07( char * str ){
	int y_a= get_RNG(7,0);
	int x_a = get_RNG(14,0);
	put_str_wAdress(x_a*6, y_a, str);
}

void put_char_07( char str ){
	int y_a= get_RNG(7,0);
	int x_a = get_RNG(14,0);
	put_char_wAdress(x_a*6, y_a, str);
}

void shift_forward ( int * x , int * y , char * str){

	 *y %= 6;
	 *x %= 14;
	(*x)++;
	if ( *x == 14 ){
		*x = 0;
		(*y)++;
		*y = (*y)%6;
	}
	put_str_wAdress ( *x*6 , *y , str ) ;

}
void shift_backward ( int * x , int * y , char * str){
	( *x )--;
//	( *x ) %= 14;
//	( *y ) %= 6;
	
	if ( *x <= 0 || ( *x )  == 255){
		*x = 13;
		if( *y == 0 ){
			*y = 5;
		}
		else (*y)--;
	}
	put_str_wAdress ( *x*6 , *y , str ) ;
}
