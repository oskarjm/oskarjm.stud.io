/*
 * GccApplication3.c
 *
 * Created: 19.03.2019 08.58.18
 * Author : Oskar J Martinsen
 */ 

#include <avr/io.h>
#include "USART.h"

#define SPI_MASTER 0
#define DDR_SPI DDRB
#define DD_MISO DDB4

	uint8_t data;		

void SPI_SLAVE_INIT(void)
{
	DDR_SPI=(1<<DD_MISO); //Pull-up on DDB4
	SPCR = (1<<SPE); //Pull-up on SPE
{
	//SPDR= data;
	while(!(SPSR & (1<<SPIF)));
	;
	/* Return Data Register */
	return SPDR;

int main(void)
{
	uint8_t data;
	initUSART();
	   
    while (1) 
    {
		if(SPI_MASTER){
			
		SPI_SlaveReceive();			//Recive text from Master
		transmitByte(data);
		
    }
	else 
	{
		UDR0=SPDR;		//
		SPDR=UDR0;		//Reset to start
		while(!(SPSR & (1<<SPIF)));
	}
	}
		
}
