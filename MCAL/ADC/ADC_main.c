/*
 * ADC_main.c
 *
 *  Created on: Aug 30, 2023
 *      Author: yosef
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "ADC_interface.h"

int main (void)
{
	u16 Reading;
	DIO_voidSetPinDirection(DIO_u8PORTA, 0 , DIO_u8INPUT);      //no pullup resistance in analog
	DIO_voidSetPortDirection(DIO_u8PORTC,0xff);

	ADC_voidInit();

	while(1)
	{
		Reading=(ADC_u16ReadChannel(0)*500)/1024;

		if(Reading < 10){
			DIO_voidSetPortValue(DIO_u8PORTC , 0x00);
		}

		else if(Reading < 20){
			DIO_voidSetPortValue(DIO_u8PORTC , 0b00000011);
		}

		else if(Reading < 30){
			DIO_voidSetPortValue(DIO_u8PORTC , 0b00001111);
		}
		else if(Reading < 50){
			DIO_voidSetPortValue(DIO_u8PORTC , 0b00111111);
		}
//		else if(Reading < 1000){
//			DIO_voidSetPortValue(DIO_u8PORTC , 0b01111111);
//		}
		else
		{
			DIO_voidSetPortValue(DIO_u8PORTC , 0b11111111);
		}
	}
}
