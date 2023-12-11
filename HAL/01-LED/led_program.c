/*
 * led_program.c
 *
 *  Created on: 18 Oct 2023
 *      Author: Me
 */

#include "../../HAL/01-LED/LED_INTERFACE.h"
#include <util/delay_basic.h>
#include "util/delay.h"
void __led_void_intilize(void){
	DIO_voidSetPinDirection(LED_PORT,LED_PIN0,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(LED_PORT,LED_PIN1,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(LED_PORT,LED_PIN2,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(LED_PORT,LED_PIN3,DIO_u8PINOUTPUT);
	DIO_voidSetPinValue(LED_PORT,DIO_u8PIN0,DIO_u8PINLOW);
}


void led_void_ON(void){
	DIO_voidSetPinValue(LED_PORT,LED_PIN0,DIO_u8PINHIGH);
	DIO_voidSetPinValue(LED_PORT,LED_PIN1,DIO_u8PINHIGH);
	DIO_voidSetPinValue(LED_PORT,LED_PIN2,DIO_u8PINHIGH);
	DIO_voidSetPinValue(LED_PORT,LED_PIN3,DIO_u8PINHIGH);
}

void led_void_OFF(void){
	DIO_voidSetPinValue(LED_PORT,LED_PIN0,DIO_u8PINLOW);
	DIO_voidSetPinValue(LED_PORT,LED_PIN1,DIO_u8PINLOW);
	DIO_voidSetPinValue(LED_PORT,LED_PIN2,DIO_u8PINLOW);
	DIO_voidSetPinValue(LED_PORT,LED_PIN3,DIO_u8PINLOW);
}
void led_togg(void){
	DIO_voidTogllePinValue(LED_PORT,LED_PIN1);

	//DIO_voidTogllePinValue(LED_PORT,LED_PIN0);
	//_delay_ms(300);
}

void led_interrupt(void){
	DIO_voidSetPinValue(LED_PORT,DIO_u8PIN0,DIO_u8PINHIGH);
	//DIO_voidSetPinValue(LED_PORT,LED_PIN1,DIO_u8PINHIGH);

}
