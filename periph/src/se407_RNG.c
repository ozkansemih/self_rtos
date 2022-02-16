#include "se407_RNG.h"          


void init_RNG(){
    RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);
	RNG_Cmd( ENABLE);
}
