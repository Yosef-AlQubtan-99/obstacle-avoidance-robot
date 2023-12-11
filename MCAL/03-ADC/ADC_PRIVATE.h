/*
 * ADC_PRIVATE.h
 *
 *  Created on: 20 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_03_ADC_ADC_PRIVATE_H_
#define MCAL_03_ADC_ADC_PRIVATE_H_
#define ENABLED  1
#define DISABLED 0
#define SFIOR (*((volatile uint8 *)0x50))

#define SFIOR_ADTS0 5
#define SFIOR_ADTS1 6
#define SFIOR_ADTS2 7

#define ADMUX (*((volatile uint8 *)0x27))
#define ADMUX_ADLAR 5
#define ADMUX_REFS0 6
#define ADMUX_REFS1 7


#define ADCSRA (*((volatile uint8 *)0x26))
#define ADCSRA_ADPS0 0
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS2 2
#define ADCSRA_ADIE  3
#define ADCSRA_ADIF  4
#define ADCSRA_ADATE 5
#define ADCSRA_ADSC  6
#define ADCSRA_ADEN  7

//IF INTERRUPT  -->  0b11111000
#define ADCH (*((volatile uint8 *)0x25))
#define ADCL (*((volatile uint8 *)0x24))
#define ADC (*((volatile uint16 *)0x24))
/* ADC RESOLUTION */
#define EIGHT_BITS 1u
#define TEN_BITS   2u
/* ADC REFERANCE */
#define ARREF_REF  1u
#define AVCC_REF   2u
#define INTERRUPT_256VOLT 4u
/* ADC PRESCALER */
#define ADC_DIV_BY_2     1u
#define ADC_DIV_BY_4     2u
#define ADC_DIV_BY_8     3u
#define ADC_DIV_BY_16    4u //IF EXTERNAL C/K =16 --> ADC WORK SPEED 8
#define ADC_DIV_BY_32    5u
#define ADC_DIV_BY_64    6u
#define ADC_DIV_BY_128   7u
#define ADC_PRES_MUSK    0b11111000
#define ADC_CHANNEL_MUSK 0b11100000
#define ADC_CHANNEL_A0   0b00000

//LW HT4A3AL 3BIT JUST  #define ADC_PRES_MUSK 0b11111000

#endif /* MCAL_03_ADC_ADC_PRIVATE_H_ */
