/*
 * BUTTON_INTERFACE.h
 *
 *  Created on: 16 Oct 2023
 *      Author: Me
 */

#ifndef HAL_02_BUTTON_BUTTON_INTERFACE_H_
#define HAL_02_BUTTON_BUTTON_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../HAL/03-CLCD/Clcd_Interface.h"
#include "../../HAL/05-MOTOR/Motor_Interface.h"
#define BUTTON_PORT DIO_u8PORTB
#define BUTTON_PIN1 DIO_u8PIN0
#define BUTTON_PIN2 DIO_u8PIN1
#define BUTTON_PIN3 DIO_u8PIN2

void Button_Initilize(void);
void Button_Press_Motor_Forward(void);
void Button_Press_Motor_Backward(void);
void Button_Press_Motor_Stop(void);



#endif /* HAL_02_BUTTON_BUTTON_INTERFACE_H_ */
