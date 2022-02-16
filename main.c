#include "main.h"

uint32_t msTicks;
uint8_t dma_buffer [ 32];
uint8_t semihh [ 32];

int main(){
	
	config_clock();
	init_leds();
	led12_on();
	led15_toggle();

}

void vApplicationMallocFailedHook( void ){

}


