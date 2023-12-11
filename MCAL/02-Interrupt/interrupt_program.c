

#include "../../MCAL/02-Interrupt/INTERRUPT_INTERFACE.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../MCAL/01-DIO/DIO_private.h"
#include "../../MCAL/01-DIO/DIO_config.h"
#include<util/delay.h>
//volatile uint8 count=0;
void (*ptr) (void) = {NULL};
//void (*ptr1) (void) = {NULL};
//void (*ptr2) (void) = {NULL};
//static void (*ptrs[3]) (void) = {NULL};
void Interrupt_Intilize(void){
   //DIO_voidSetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PININPUT); //INT2
   DIO_voidSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PININPUT); //INT0
  // DIO_voidSetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PININPUT); //INT1
  // DIO_voidSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PINHIGH);
  // DIO_voidSetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PINHIGH);
   //DIO_voidSetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PINHIGH);
   //DIO_voidSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PINHIGH); //PULL UP FOR //INT0
   //DIO_voidSetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PINLOW); //da kda 3alt hena
}
void GIE_ENABLE(void){
	SET_BIT(SREG,GIE_PIN_ENABLE);  //gie enable //AT THE END
}
void Interrupt_vector(INTERRUPT_NUM INT_NUM ,INTERRUPT_SENSE_CONTROL INT_MODE){
	_delay_ms(350);
 //POST BUILD CHANGE IN RUN TIME
	switch(INT_NUM){

	case INTERR_INT0:
		switch(INT_MODE){
		case LOW_LEVEL:
			CLR_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
			break;
		case LOGICAL_CHANGE:
			CLR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
		case FALLING_EDGE:
			// SET INTERRUPT 0 TO FALLING EDGE
			SET_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
		}
		// Enable INT0
		SET_BIT(GICR,INT0); //PIE
		break;

		case INTERR_INT1:
			switch(INT_MODE){
			case LOW_LEVEL:
				CLR_BIT(MCUCR,ISC11);
				CLR_BIT(MCUCR,ISC10);
				break;
			case LOGICAL_CHANGE:
				CLR_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			case FALLING_EDGE:
				// SET INTERRUPT 1 TO FALLING EDGE
				SET_BIT(MCUCR,ISC11);
				CLR_BIT(MCUCR,ISC10);
				break;
			case RISING_EDGE:
				SET_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			}
			//Enable INT1
			SET_BIT(GICR,INT1);
			break;

			case INTERR_INT2 :
				switch(INT_MODE){
				case LOW_LEVEL:

					break;
				case LOGICAL_CHANGE:

					break;
				case FALLING_EDGE:
					// SET INTERRUPT 2 TO FALLING EDGE
					SET_BIT(MCUCR,ISC2);
					break;
				case RISING_EDGE:
					CLR_BIT(MCUCR,ISC2);
					break;
				}
				// Enable INT2
				SET_BIT(GICR,INT2);
				break;

	 default:                break;

	}

     _delay_ms(1000);
}

void EXIT_CALLBACK(void(*p(void))){
	//ptrs[Copy_Interrupt_var]=p;
	 ptr=p;
	//ptr2=p2;
}
/*
void __vector_1(void)__attribute__ ((signal));

void __vector_1(void){
	ptr();

}

void __vector_2(void)__attribute__ ((signal));

void __vector_2(void){
	ptr();

}
*/
