/*
 * Motor_Interface.h
 *
 *  Created on: 12 Oct 2023
 *      Author: Me
 */

#ifndef HAL_05_MOTOR_MOTOR_INTERFACE_H_
#define HAL_05_MOTOR_MOTOR_INTERFACE_H_
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#define MOTOR_PORT DIO_u8PORTC
#define MOTOR1_1  DIO_u8PIN0
#define MOTOR1_2  DIO_u8PIN1
#define MOTOR2_1  DIO_u8PIN2
#define MOTOR2_2  DIO_u8PIN3


typedef enum{
    MOT_OFF,
    MOT_ON
}mot_status;


void Motor_void_Intilize(void);
void Motor_void_ck(void);
void Motor_void_cck(void);
void Motor_void_stop(void);
void DC_voidInit(void);
void APP_FAST_DC1_TIMER1(uint16 Copy_uint16Speed);
void APP_FAST_DC2_TIMER1(uint16 Copy_uint16Speed);
#endif /* HAL_05_MOTOR_MOTOR_INTERFACE_H_ */
