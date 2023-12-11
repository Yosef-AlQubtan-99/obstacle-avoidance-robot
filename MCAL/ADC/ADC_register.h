/*
 * ADC_register.h
 *
 *  Created on: Aug 30, 2023
 *      Author: yosef
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_


#define   ADMUX         *(volatile u8*)(0x27)
#define   ADCSRA        *(volatile u8*)(0x26)
#define   ADC           *(volatile u16*)(0x24)                       //ADCL+ADCH = 10bits -> u16 with the address of the first byte in the two registers
#define   SFIOR         *(volatile u8*)(0x50)


#endif /* ADC_REGISTER_H_ */
