/*
 * LED_INTERFACE.h
 *
 *  Created on: 18 Oct 2023
 *      Author: Me
 */

#ifndef HAL_01_LED_LED_INTERFACE_H_
#define HAL_01_LED_LED_INTERFACE_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"



#define LED_PORT DIO_u8PORTC
#define LED_PIN0 DIO_u8PIN0
#define LED_PIN1 DIO_u8PIN1
#define LED_PIN2 DIO_u8PIN2
#define LED_PIN3 DIO_u8PIN3

void __led_void_intilize(void);
void led_void_ON(void);
void led_void_OFF(void);
void led_togg(void);
void led_interrupt(void);

#endif /* HAL_01_LED_LED_INTERFACE_H_ */
