/*
 * Ultrasonic_program.c
 *
 *  Created on: Nov 6, 2023
 *      Author: yosef
 */

#include "Ultrasonic_config.h"
#include "Ultrasonic_interface.h"
#include <stdio.h>
#include "avr/delay.h"
#include "string.h"
#include "avr/interrupt.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../MCAL/04-TIMER/TIMER_INTERFACE.h"
#include "../../MCAL/02-Interrupt/INTERRUPT_INTERFACE.h"
#include "../../HAL/03-CLCD/Clcd_Interface.h"

//uint16 Global_uint16Counts=0;
//uint16 *global_puint16Counts=&Global_uint16Counts;

//uint16 Global_uint16Distance=0;
uint8 sensor_working=0;
uint8 rising_edge=0;
uint32 timer_counter=0;
uint32 distance;
uint8 distance_str[10];

void ultrasonic_init(void){

  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  Interrupt_vector(INTERR_INT1,LOGICAL_CHANGE);
  Timer0_void_Intilize_Overflow();

  return;
}

uint32 ultra_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
    //while(GET_BIT(TIFR,TIFR_TOV0)==1){};
  }
  return distance;
}
ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT0)/466;
   // Clcd_set_cursor(1,1);
    //lcd_WritNumber_16( distance);
  	_delay_ms(40);
    timer_counter=0;
    rising_edge=0;
  }
}}

ISR(TIMER0_OVF_vect){
    timer_counter++;
    if(timer_counter >730){
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}

/*
void APP_ULTRA1(void){  //ISR INTERRUPT 0
	if(sensor_working==1){
	    if(rising_edge==0){
	      TCNT0=0x00;
	      rising_edge=1;
	      timer_counter=0;
	    }
	  else{
	    distance=(((timer_counter*256U)+TCNT0)/466U);
	    Clcd_set_cursor(1,1);
	  	lcd_WritNumber_16(distance);
	  	_delay_ms(40);
	    timer_counter=0;
	    rising_edge=0;
	  }
	}
}
void APP_ULTRA2(void){ //TIMER0 OVERFLOW
timer_counter++;
    if(timer_counter >733){  //1953
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}
void APP_GO(void){

}
/*
void APP_ULTRA(void){
	if(sensor_working==1){
	    if(rising_edge==0){
	      TCNT0=0x00;
	      rising_edge=1;
	      timer_counter=0;
	    }
	  else{
	    distance=(timer_counter*256+TCNT0)/466;
	    Clcd_set_cursor(1,1);
	  	lcd_WritNumber_16(distance);
	  	_delay_ms(40);
	    timer_counter=0;
	    rising_edge=0;
	  }
	}
}
/*
uint8 Ultrasonic_uint8TimerCount(void)
{
	uint8 Local_uint8Errorstate=0;
	static uint16 Local_uint8Counter=0;
	Local_uint8Counter++;
	*global_puint16Counts=Local_uint8Counter;
	if (Local_uint8Counter== sizeof(uint16))
	{
		Local_uint8Errorstate=1;
	}
	return Local_uint8Errorstate;
}



uint8 Ultrasonic_uint8Timecalc(void)
{
	uint8 local_uint8ErrorState=0;
	Global_uint16Distance=(uint16)(343*Global_uint16Counts/(40*2));                  //Distance in cm. , every timer count = 250 usec
	if (Global_uint16Distance==sizeof(uint16))
	{
		local_uint8ErrorState=1;
	}
	return local_uint8ErrorState;
}


void Ultrasonic_uint8DistCalc(uint8 Copy_uint8DIO_Port , uint8 Copy_uint8DIO_Pin , uint32* Global_uint16Distance)   //Trigger pins
{

	DIO_voidSetPinDirection(Copy_uint8DIO_Port , Copy_uint8DIO_Pin , DIO_u8PINOUTPUT);
	DIO_voidSetPinValue(Copy_uint8DIO_Port , Copy_uint8DIO_Pin , DIO_u8PINHIGH);

		_delay_us(10);
		DIO_voidSetPinValue(Copy_uint8DIO_Port , Copy_uint8DIO_Pin , DIO_u8PINLOW);
		EXIT_CALLBACK(&APP_ULTRA);

}
*/
