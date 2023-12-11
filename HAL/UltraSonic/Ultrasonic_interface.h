/*
 * Ultrasonic_interface.h
 *
 *  Created on: Nov 6, 2023
 *      Author: yosef
 */


#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

#include "Ultrasonic_config.h"
#include "Ultrasonic_interface.h"
#include <stdio.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"

#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   ECHO_PULLUP   PORTD
#define   TRIGER        7U
#define   ECHO          3U


void ultrasonic_init(void);
uint32 ultra_triger(void);
void APP_ULTRA1(void);
void APP_ULTRA2(void);
void APP_GO(void);
//uint8 Ultrasonic_uint8DistCalc(uint8 Copy_uint8DIO_Port , uint8 Copy_uint8DIO_Pin , uint16* Copy_puint8Distance);
//uint8 Ultrasonic_uint8TimerCount(void);
//uint8 Ultrasonic_uint8Timecalc(void);





#endif //Ultrasonic_INTERFACE_H_
