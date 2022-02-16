
#ifndef LEDS_H
#define  LEDS_H


#include "se407_GPIO.h"              // Keil::Device:StdPeriph Drivers:SPI

void led12_on( void );
void led12_off( void );

void led13_on( void );
void led13_off( void );

void led14_on( void );
void led14_off( void );

void led15_on( void );
void led15_off( void );


void led12_toggle( void );
void led13_toggle( void );
void led14_toggle( void );
void led15_toggle( void );


#endif
