#include "../../HAL/02-BUTTON/BUTTON_INTERFACE.h"
#include "util/delay.h"
#include <util/delay_basic.h>



void Button_Initilize(void){
	DIO_voidSetPinDirection(BUTTON_PORT,BUTTON_PIN1,DIO_u8PININPUT);
	DIO_voidSetPinDirection(BUTTON_PORT,BUTTON_PIN2,DIO_u8PININPUT);
	DIO_voidSetPinDirection(BUTTON_PORT,BUTTON_PIN3,DIO_u8PININPUT);
}

void Button_Press_Motor_Forward(void){
	uint8 local_read=0;
	local_read=GET_BIT(PINB,BUTTON_PIN1);
	        if(local_read==1){
	        	_delay_ms(350);
	        	if(local_read==1){
	        		Motor_void_ck();
	        	}

	        }
	        else{

	        }

}

void Button_Press_Motor_Backward(void){
	uint8 local_read=0;
	local_read=GET_BIT(PINB,BUTTON_PIN2);
	        if(local_read==1){
	        	_delay_ms(350);
	        	if(local_read==1){
	        		Motor_void_cck();
	        	}

	        }
	        else{

	        }

}

void Button_Press_Motor_Stop(void){
	uint8 local_read=0;
	local_read=GET_BIT(PINB,BUTTON_PIN3);
	        if(local_read==1){
	        	_delay_ms(350);
	        	if(local_read==1){
	        		 Motor_void_stop();
	        	}

	        }
	        else{

	        }

}

