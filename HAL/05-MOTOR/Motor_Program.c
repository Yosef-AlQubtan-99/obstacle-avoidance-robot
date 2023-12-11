/*
 * Motor_Program.c
 *
 *  Created on: 12 Oct 2023
 *      Author: Me
 */

#include "Motor_Interface.h"
#include<avr/io.h>
#include<util/delay.h>
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/TIMER1/TIMER1_config.h"
#include "../../MCAL/TIMER1/TIMER1_private.h"
uint8 read_pin;
void APP_TIMER1_DC_INTILIZE(void){
	TIMER1_voidInit(TIMER1_FAST_PWM_10BIT_MODE,TIMER1_SCALER_64);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_NON_INVERTING_MODE ,TIMER1_OCR1B);
}


void Motor_void_Intilize(void){
	DIO_voidSetPinDirection(MOTOR_PORT,MOTOR1_1,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT,MOTOR1_2,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT,MOTOR2_1,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(MOTOR_PORT,MOTOR2_2,DIO_u8PINOUTPUT);
}

void Motor_void_ck(void){
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR1_1,DIO_u8PINHIGH);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR1_2,DIO_u8PINLOW);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR2_1,DIO_u8PINHIGH);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR2_2,DIO_u8PINLOW);
}
void Motor_void_cck(void){
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR1_1,DIO_u8PINLOW);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR1_2,DIO_u8PINHIGH);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR2_1,DIO_u8PINLOW);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR2_2,DIO_u8PINHIGH);
}

void Motor_void_stop(void){
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR1_1,DIO_u8PINLOW);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR1_2,DIO_u8PINLOW);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR2_1,DIO_u8PINLOW);
	DIO_voidSetPinValue(MOTOR_PORT,MOTOR2_2,DIO_u8PINLOW);
}
void DC_voidInit(void){
	//FROM MCAL---> DIO,TIMER1
	DIO_voidSetPinDirection(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PINOUTPUT);
	TIMER1_voidInit(TIMER1_FAST_PWM_ICR1_MODE, TIMER1_SCALER_8);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_NON_INVERTING_MODE, TIMER1_OCR1A);
	TIMER1_voidOutputCompareInit(TIMER1_OC1_NON_INVERTING_MODE ,TIMER1_OCR1B);
	TIMER1_voidSetICR1(256U);
}

void APP_FAST_DC1_TIMER1(uint16 Copy_uint16Speed){
	/* 20000us to get 50hz */
	TIMER1_voidSetOCR1A(Copy_uint16Speed);
}

void APP_FAST_DC2_TIMER1(uint16 Copy_uint16Speed)
{
	/* 2000us Ton to get angle zero */
		TIMER1_voidSetOCR1B(Copy_uint16Speed);
}
