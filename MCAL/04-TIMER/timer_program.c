/*
 * timer_program.c
 *
 *  Created on: 22 Oct 2023
 *      Author: Me
 */

#include "../04-TIMER/TIMER_CONFIG.h"
#include "../04-TIMER/TIMER_PRIVATE.h"
#include "../04-TIMER/TIMER_INTERFACE.h"
#include "../01-DIO/DIO_INTERFACE.h"
static void (*ptrs[8]) (void) = {NULL}; //global for just this file
#define HIGH 1
#define LOW 0

void Timer0_void_Compare_Value(uint8 Copy_u8CompareVal){
	OCR0=Copy_u8CompareVal;
}

void Timer0_void_Intilize_Overflow(void){

	//CLR_BIT(TCCR0,TCCR0_WGM01);
	//SET_BIT(TCCR0,TCCR0_CS01); //PRESCALER 8
	//SET_BIT(TCCR0,TCCR0_COM00); //PRESCALER 64
	//TCCR0=0x00;
	//TCCR0=0x01; //PRESCALER 8
	//TCNT0=192; //NORAML MODE
	//TCNT0=0x00;
	/* Disable Timer 0 */
		    	TCCR0 = DISABLE_MODULE_VALUE;
		    	/* Setting pre scaler */
		    	TCCR0 = (PRESCLR1_VALUE);
		    	/* Initializing the timer with zero */
		    	TCNT0 = ZER0_INITIALIZER;
					/* Timer overflow interrupt enable*/
					TIMSK |=(1<<TIMSK_TOIE0);

	//OCR0=DIO_u8PORTLOW; //NORMAL MODE

	//SET_BIT(TIFR,TIFR_TOV0); //OVERFLOW INTERRUPT FLAG


	//SET_BIT(TIMSK,TIMSK_TOIE0); //OVERFLOW INTERRUPT ENABLE IN THE END
}



void Timer0_void_Intilize_Compare(void){
	//by bit masking
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	//by bit PRESCALER 64
	TCCR0=TCCR0 & TIMER_PRES_MUSK_COMP;
	TCCR0=TCCR0 | TIMER_DIV_BY_64;
	//SET COMPARE VALUE
	//Timer0_void_Compare_Value(250u);
	//Timer0_void_Compare_Value(625u);
	//OCR0=250u; //CTC MODE
	//enable
	SET_BIT(TIFR,TIFR_OCF0); //enable compare match INTERRUPT FLAG
	SET_BIT(TIMSK,TIMSK_OCIE0);//enable compare match INTERRUPT ENABLE IN THE END
}

void Timer0_U8_SET_CALL_BACK(TIMER0_INTERRUPT Copy_u8Timer0,void(*p1(void))){
	if(p1!=NULL){
		ptrs[Copy_u8Timer0]=p1;
	}
	else{

	}
}
void Timer0_void_Intilize_Pwm(void){

	////FAST PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	//FAST PWM clear COMPARE
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
	//clr bit PRESCALER 64
	TCCR0=TCCR0 & TIMER_PRES_MUSK_PWM;
	//set bit PRESCALER 64
	TCCR0=TCCR0 | TIMER_DIV_BY_64;
	//SET COMPARE VALUE
	Timer0_void_Compare_Value(63U); //25% DUTY CYCLE 64 PRESCALER //16 MHZ CRYSTAL
	//TCNT0=205; //NORAML MODE
	//enable NO NEEDING
	//SET_BIT(TIFR,TIFR_OCF0); //enable compare match INTERRUPT FLAG
	//SET_BIT(TIMSK,TIMSK_OCIE0);//enable compare match INTERRUPT ENABLE IN THE END
}
/*
void __vector_10(void)__attribute__ ((signal));
void __vector_10(void){  //TIMER0 COMPARE MATCH
	ptrs[TIMER0_COMPARE]();

}



void __vector_11(void)__attribute__ ((signal));

void __vector_11(void){  //TIMER0 overflow
	ptrs[TIMER0_OVERFLOW]();

}
*/

