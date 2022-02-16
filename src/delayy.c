
#include "stdint.h"
#include "delayy.h"

extern uint32_t msTicks;

void delayms(int ms){
	uint32_t currTicks=msTicks;
	while( msTicks-currTicks < ms ){
	} 
	
}


