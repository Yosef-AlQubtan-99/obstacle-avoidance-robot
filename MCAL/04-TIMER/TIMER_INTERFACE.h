/*
 * TIMER_INTERFACE.h
 *
 *  Created on: 22 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_04_TIMER_TIMER_INTERFACE_H_
#define MCAL_04_TIMER_TIMER_INTERFACE_H_
#include "../04-TIMER/TIMER_CONFIG.h"
#include "../04-TIMER/TIMER_PRIVATE.h"
#include "../01-DIO/DIO_INTERFACE.h"
typedef enum{
	TIMER0_OVERFLOW=0,
	TIMER0_COMPARE
}TIMER0_INTERRUPT;

void Timer0_void_Compare_Value(uint8 Copy_u8CompareVal);
void Timer0_void_Intilize_Overflow(void);
void Timer0_void_Intilize_Compare(void);
void Timer0_U8_SET_CALL_BACK(TIMER0_INTERRUPT Copy_u8Timer0,void(*p1(void)));
void Timer0_void_Intilize_Pwm(void);

#endif /* MCAL_04_TIMER_TIMER_INTERFACE_H_ */
