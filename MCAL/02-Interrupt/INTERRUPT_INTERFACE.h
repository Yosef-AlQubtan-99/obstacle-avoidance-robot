/*
 * INTERRUPT_INTERFACE.h
 *
 *  Created on: 18 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_02_INTERRUPT_INTERRUPT_INTERFACE_H_
#define MCAL_02_INTERRUPT_INTERRUPT_INTERFACE_H_

#include "../../MCAL/02-Interrupt/INTERRUPT_CONFIG.h"
#include "../../MCAL/02-Interrupt/INTERRUPT_PRIVATE.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"

#define GIE_PIN_ENABLE DIO_u8PIN7
typedef enum{
   INTERR_INT0=0,
   INTERR_INT1,
   INTERR_INT2
}INTERRUPT_NUM;

typedef enum{
	LOW_LEVEL=0,
	LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}INTERRUPT_SENSE_CONTROL;
void GIE_ENABLE(void);
void Interrupt_Intilize(void);
void Interrupt_vector(INTERRUPT_NUM INT_NUM ,INTERRUPT_SENSE_CONTROL INT_MODE);
void __vector_1(void)__attribute__ ((signal));
void EXIT_CALLBACK(void(*p(void)));

#endif /* MCAL_02_INTERRUPT_INTERRUPT_INTERFACE_H_ */
