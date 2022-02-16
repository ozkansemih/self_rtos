#ifndef se407_SPI_H_
#define se407_SPI_H_


#include "stm32f4xx_spi.h"              // Keil::Device:StdPeriph Drivers:SPI
#include "stm32f4xx_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "delayy.h"              // Keil::Device:StdPeriph Drivers:SPI

#define SD_CS_PIN GPIO_Pin_0
#define SD_CS_PORT GPIOA

void init_SPI2( void );

void init_SPI1_for_5510( void );
void init_SPI2_for_5510( void );
void init_SPI4_for_5510( void );

void init_SPI1_for_SD( void );

void spi_send( SPI_TypeDef* spi, char data);
void spi1_TX( char data);
uint8_t spi1_RX( uint8_t dump );

void spi2_TX( char data);
uint8_t spi2_RX( uint8_t dump );

void spi4_TX( char data);

#endif


