/*
 * TIMER_PRIVATE.h
 *
 *  Created on: 22 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_04_TIMER_TIMER_PRIVATE_H_
#define MCAL_04_TIMER_TIMER_PRIVATE_H_
#define TIMER_PRES_MUSK_COMP 0b11111000
#define TIMER_PRES_MUSK_PWM 0b11100000
#define TIMER_DIV_BY_64 0b00000011
#define TIMER_DIV_BY_8 0b00000010
#define TCNT0 (*((volatile uint8 *)0x52))
#define OCR0  (*((volatile uint8 *)0x5C))

////////////
#define TIMSK  (*((volatile uint8 *)0x59))
#define TIMSK_OCIE0 1
#define TIMSK_TOIE0 0
///////////
#define TIFR  (*((volatile uint8 *)0x58))
#define TIFR_OCF0   1
#define TIFR_TOV0   0
///////////
#define TCCR0  (*((volatile uint8 *)0x53))
#define TCCR0_FOC0  7
#define TCCR0_WGM00 6  //pwm 0
#define TCCR0_WGM01 3  //ctc 0
#define TCCR0_COM01 5
#define TCCR0_COM00 4
#define TCCR0_CS02 2
#define TCCR0_CS01 1
#define TCCR0_CS00 0

#define TCNT1L  (*((volatile uint8 *)0x4C))
#define TCNT2  (*((volatile uint8 *)0x44))
#endif /* MCAL_04_TIMER_TIMER_PRIVATE_H_ */
