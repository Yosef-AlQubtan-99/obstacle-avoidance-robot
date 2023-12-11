/*
 * KEYPAD_PROGRAM.c
 *
 *  Created on: 11 Oct 2023
 *      Author: Me
 */
#include "KEYPAD_INTERFACE.h"
#include"../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../HAL/03-CLCD/Clcd_Interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "util/delay.h"
#define FIRST_COL  DIO_u8PIN4
#define FIRST_ROW   DIO_u8PIN0
uint8 arr[KEYPAD_ROW][KEYPAD_COL]={{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'c','0','=','+'}};
void __Keypad_Initilize(void)
{
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,ROW1,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,ROW2,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,ROW3,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,ROW4,DIO_u8PINOUTPUT);
	////////////////////////////////////////////////////////
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,COL1,DIO_u8PININPUT);
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,COL2,DIO_u8PININPUT);
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,COL3,DIO_u8PININPUT);
	DIO_voidSetPinDirection(KEYPAD_DATA_PORT,COL4,DIO_u8PININPUT);
	for(int i=0;i<KEYPAD_ROW;i++){
		DIO_voidSetPinValue(KEYPAD_DATA_PORT,FIRST_ROW+i,DIO_u8PINHIGH);
	}
	//PULL UP COL
	for(int F=0;F<KEYPAD_COL;F++){
		DIO_voidSetPinValue(KEYPAD_DATA_PORT,FIRST_COL+F,DIO_u8PINHIGH);
	}
}

uint8 __Keypad_void_getkey(void)
{

	uint8 key;
	uint8 RETURN_VAL='n';
	for(int r=0;r<KEYPAD_ROW;r++){

		DIO_voidSetPinValue(KEYPAD_DATA_PORT,r,DIO_u8PINLOW);
		for(int j=4;j<8;j++){
			//DIO_voidSetPinValue(KEYPAD_DATA_PORT,j,DIO_u8PINLOW);
			key=(GET_BIT(PIND,j));
			if(key==0){
				RETURN_VAL=arr[r][j-4];
			}
			//key=(GET_BIT(PIND,j));
			while((GET_BIT(PIND,j))==0){};
		}

		DIO_voidSetPinValue(KEYPAD_DATA_PORT,r,DIO_u8PINHIGH);
	}

	return RETURN_VAL;
}

uint8 __Keypad__Check(void)
{
	uint8 val='n';
	while(val=='n'){
		val= __Keypad_void_getkey();
	}
	return val;
}


/*
void lcd_display_number(void){
	uint8 num_keypad='n';
	uint64 B_num;
	while(num_keypad=='n'){
		num_keypad=__Keypad_void_getkey();
		B_num=lcd_convert_to_binary(num_keypad);
		lcd_sed_string_pos(2,1,&B_num);
	}


}
*/
