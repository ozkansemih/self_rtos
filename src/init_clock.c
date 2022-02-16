#include "init_clock.h"

void config_clock(){

	SystemCoreClockUpdate();
	SysTick_Config( SystemCoreClock /1000 );

}
