/*
 * INTERRUPT_PRIVATE.h
 *
 *  Created on: 18 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_02_INTERRUPT_INTERRUPT_PRIVATE_H_
#define MCAL_02_INTERRUPT_INTERRUPT_PRIVATE_H_

#define MCUCR (*((volatile uint8 *)0x55))
#define MCUCSR (*((volatile uint8 *)0x54))t2yubnmi0
#define GICR (*((volatile uint8 *)0x5B))
#define GIFR (*((volatile uint8 *)0x5A))
#define SREG (*((volatile uint8 *)0x5F))



#define ISC00   0U
#define ISC01   1U
#define ISC10   2U
#define ISC11   3U
#define INT0    6U
#define INT1    7U
#define INT2    5U
#define ISC2    6U

#endif /* MCAL_02_INTERRUPT_INTERRUPT_PRIVATE_H_ */
