
//#ifdef z

#include "../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../MCAL/02-Interrupt/INTERRUPT_INTERFACE.h"
#include "../HAL/01-LED/LED_INTERFACE.h"
#include "../MCAL/03-ADC/ADC_INTERFACE.h"
#include "../HAL/03-CLCD/Clcd_Interface.h"
#include "../HAL/04-Keypad/KEYPAD_INTERFACE.h"
#include "../HAL/05-MOTOR/Motor_Interface.h"
#include "../HAL/02-BUTTON/BUTTON_INTERFACE.h"
#include "../MCAL/04-TIMER/TIMER_INTERFACE.h"
#include "../HAL/UltraSonic/Ultrasonic_interface.h"
#include "../UART/UART_interface.h"
//#include "../HAL/06-DC MOTORS/DC_interface.h"

#include "util/delay.h"
#include <util/delay_basic.h>
#include <stdio.h>
#include <math.h>
//volatile uint64 counter0=0;
volatile uint64 counter1=0;
//uint8 i=1;
//uint8 j=1;
volatile uint32 d=0;
uint8 Data=0;
//void func_void_over_flow (void);
//void func_void_compare_match (void);
//void func_void_compare_match_lcd_timer (void);
//void func_void_compare_match_lcd_Password (void);
//void func_void_pwm (void);
void func_Start_Pwm_Timer1 (void);
void BT_motion (void);

//void func_WATCH_Timer (void);
//void func_toggle_Timer_COMPARE (void);
//void func_toggle_Timer_Overflow (void);
//void func_servo_motor(void);
int main() {
	Motor_void_Intilize();
	Motor_void_cck();
	Motor_void_stop();

//	//for soft start
//	for (uint8 i=0; i<=250 ; i+=5)
//	{
//		APP_FAST_DC1_TIMER1(i);
//		APP_FAST_DC2_TIMER1(i);
//		_delay_ms(5);
//	}
	DC_voidInit();
	Timer1_U8_SET_CALL_BACK(&func_Start_Pwm_Timer1);

	Clcd_void_Intilization();
	ultrasonic_init();
	GIE_ENABLE();
	_delay_ms(15);
	while(1){

		d=ultra_triger();
		_delay_ms(15);
		Clcd_set_cursor(1,1);
		lcd_WritNumber_16(d);
		while (d == ultra_triger());
		_delay_ms(15);
		__vector_9();

		if(d>60)
		{
			Motor_void_cck();
		}
//		else if(d<90 && d>60)
//		{
//			Motor_void_stop();
////			Motor_void_ck();     		//Reverse for instead of brakes
////			_delay_ms(15);
//			Motor_void_stop();
//		}
		else if(d<=60)
		{
			Motor_void_stop();
			//Turn
		}
//
//		//BT_motion();

	}
}

void func_Start_Pwm_Timer1 (){
	counter1++;
	APP_FAST_DC1_TIMER1((uint16)191);
	APP_FAST_DC2_TIMER1((uint16)191);
	if(counter1==3906){

		counter1=0;
	}
}

void BT_motion (void)
{
	Data=UART_u8ReceiveData();
	switch(Data)
	{
	case 'F':
		Motor_void_cck();
		break;
	case 'B':
		Motor_void_ck();
		break;
	}
}





/*
void func_servo_motor(void){
	DIO_voidSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PINOUTPUT);
}
void func_void_over_flow (void){

	counter0++;
	if(counter0==1953){
		led_togg();
		TCNT0=233; //INTIAL VALUE FOR OVERFLOW
		counter0=0;
	}
}
void func_void_compare_match (void){
	counter0++;
	if(counter0==499){
		led_togg();
		//OCR0=125u; //INTIAL VALUE FOR ctc
		Timer0_void_Compare_Value(625u); //INTIAL VALUE FOR ctc
		counter0=0;
	}
}

void func_Start_Pwm_Timer1 (void){
	counter1++;
	APP_FAST_DC1_TIMER1();
	APP_FAST_DC2_TIMER1();
	if(counter1==3906){

		counter1=0;
	}
}

void func_void_pwm (void){
	counter0++;
	DIO_voidSetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PINOUTPUT);
	//func_servo_motor();
	//Timer0_void_Compare_Value(63u);  //duty 25%  //90
	Timer0_void_Compare_Value(127u); //duty 50%  //
	//Timer0_void_Compare_Value(191u);  //duty 75%
	if(counter0==3906){

		counter0=0;
	}
	counter0=0;
}

void func_void_compare_match_lcd_Password (void){
	counter0++;

	if(counter0==999){
		OCR0=125; //INTIAL VALUE FOR ctc
		counter0=0;
	}
}
void func_void_compare_match_lcd_timer (void){
	counter0++;
	for(int hours=0;hours<24;hours++){
		for(int minute=0;minute<60;minute++){
			for(int second=0;second<60;second++){
				//lcd_sed_string_pos(i,j,"00:00:00");
				//lcd_sed_string_pos(i,8," ");
				Clcd_set_cursor(1,7);
				lcd_WritNumber(second);
				//lcd_sed_string_pos(i,7,"  ");
				counter0=0;
				//lcd_sed_string_pos(i,7,"   ");
				if(second==59){
					lcd_sed_string_pos(i,7,"   ");
					lcd_sed_string_pos(i,4,"  ");
					//lcd_sed_string_pos(i,4,"  ");
				}
				Clcd_set_cursor(1,4);
				lcd_WritNumber(minute);
				if(minute==59){
					lcd_sed_string_pos(i,4,"  ");
					lcd_sed_string_pos(i,1,"  ");
				}
				Clcd_set_cursor(1,4);
				lcd_WritNumber(hours);
				if(hours==23){
					lcd_sed_string_pos(i,1,"  ");
				}
				//lcd_sed_string_pos(i,4,"  ");
				//Clcd_set_cursor(1,4);
				//lcd_WritNumber(minute);
				//counter0=0;
				//lcd_sed_string_pos(i,j,"  ");
				//Clcd_set_cursor(i,j);
				//lcd_WritNumber(hours);
				//counter0=0;

			}
		}
	}
	if(counter0==999){
		OCR0=125; //INTIAL VALUE FOR ctc
		counter0=0;
	}
}
void func_toggle_Timer_Overflow (void){
	__led_void_intilize();
	Timer0_void_Intilize_Overflow();
	Timer0_U8_SET_CALL_BACK(TIMER0_OVERFLOW,&func_void_over_flow);
}

void func_toggle_Timer_COMPARE (void){
	__led_void_intilize();
	Timer0_void_Intilize_Compare();
	Timer0_U8_SET_CALL_BACK(TIMER0_COMPARE,&func_void_compare_match);
}

void func_WATCH_Timer (void){
	Clcd_void_Intilization();
	lcd_sed_string_pos(i,j,"00:00:00");
	Timer0_void_Intilize_Compare();
	Timer0_U8_SET_CALL_BACK(TIMER0_COMPARE,&func_void_compare_match_lcd_timer);
	lcd_sed_string_pos(i,7,"    ");
}


*/

//#endif
