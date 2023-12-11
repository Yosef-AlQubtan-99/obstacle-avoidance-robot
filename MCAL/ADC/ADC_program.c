/*
 * ADC_program.c
 *
 *  Created on: Aug 30, 2023
 *      Author: yosef
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_privte.h"
#include "ADC_register.h"

void ADC_voidInit(void)
{
	#if(VREF==AREF)
		CLR_BIT(ADMUX , 7);
		CLR_BIT(ADMUX , 6);
	#elif(VREF==AVCC)
		CLR_BIT(ADMUX , 7);
		SET_BIT(ADMUX , 6);
	#elif(VREF==AVCC)
		SET_BIT(ADMUX , 7);
		SET_BIT(ADMUX , 6);


#endif


	/*Set normal Adjustment (right Adjustment)*/
	CLR_BIT(ADMUX , 5);                        //ADLR=0

	//Select prescalar: Divide by 2
	CLR_BIT(ADCSRA,2);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,0);

	//Enable ADC
	SET_BIT(ADCSRA,7);                   //As PIE


}



u16 ADC_u16ReadChannel(u8 Copy_u8Channel)
{
	//Select the channel
	ADMUX &= 0b11100000;                   //masking the first 5 bits in ADMUX register
	ADMUX |= Copy_u8Channel;			   //for assigning the channel

	//Start Conversion  ADSC bit in ADCSRA register
	SET_BIT(ADCSRA , 6);

	//Polling on the ADC Flag
	while(GET_BIT(ADCSRA,4)==0)
	{
		asm("NOP");                     // assembly code :do nothing
	}

	SET_BIT(ADCSRA,4);                  //Clear flag like interrupt with SREG

	return ADC;
}
