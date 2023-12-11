/*
 * KEYPAD_INTERFACE.h
 *
 *  Created on: 11 Oct 2023
 *      Author: Me
 */

#ifndef HAL_04_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_04_KEYPAD_KEYPAD_INTERFACE_H_

#include "../../LIB/BIT_MATH.h"
#include "KEYPAD_CONFIG.h"
#include "KEYPAD_PRIVATE.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../HAL/03-CLCD/Clcd_Interface.h"

#define KEYPAD_DATA_PORT DIO_u8PORTD

#define ROW1 DIO_u8PIN0
#define ROW2 DIO_u8PIN1
#define ROW3 DIO_u8PIN2
#define ROW4 DIO_u8PIN3

#define COL1 DIO_u8PIN4
#define COL2 DIO_u8PIN5
#define COL3 DIO_u8PIN6
#define COL4 DIO_u8PIN7

#define KEYPAD_ROW 4
#define KEYPAD_COL 4
typedef struct{
	uint8 port_name;
	uint8 pin_number;
}keypad_bit;

typedef struct{
	keypad_bit keypad_row[KEYPAD_ROW];
	keypad_bit keypad_col[KEYPAD_COL];
}keypad_t;

void __Keypad_Initilize(void);
uint8 __Keypad_void_getkey(void);
uint8 __Keypad__Check(void);
//void lcd_display_number(void);

#endif /* HAL_04_KEYPAD_KEYPAD_INTERFACE_H_ */
