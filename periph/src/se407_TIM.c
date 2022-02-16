
#include "se407_TIM.h"

void init_tim6( void ){

RCC_APB1PeriphClockCmd ( RCC_APB1Periph_TIM6, ENABLE );

 TIM_TimeBaseInitTypeDef tim;
 NVIC_InitTypeDef nvi;
 tim.TIM_CounterMode = TIM_CounterMode_Up;
 tim.TIM_Period =  1999;
 tim.TIM_Prescaler = 41999;
 tim.TIM_RepetitionCounter = 0;
 tim.TIM_ClockDivision = TIM_CKD_DIV1;
TIM_TimeBaseInit( TIM6 , &tim);
TIM_Cmd( TIM6, ENABLE );
TIM_ITConfig( TIM6 , TIM_IT_Update , ENABLE );

nvi.NVIC_IRQChannel = TIM6_DAC_IRQn;
nvi.NVIC_IRQChannelSubPriority = 0;
nvi.NVIC_IRQChannelPreemptionPriority = 0;
nvi.NVIC_IRQChannelCmd = ENABLE ;
NVIC_Init( &nvi );


}
