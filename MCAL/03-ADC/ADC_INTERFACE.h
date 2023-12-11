/*
 * ADC_INTERFACE.h
 *
 *  Created on: 20 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_03_ADC_ADC_INTERFACE_H_
#define MCAL_03_ADC_ADC_INTERFACE_H_
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../MCAL/03-ADC/ADC_INTERFACE.h"
#include "../../MCAL/03-ADC/ADC_CONFIG.h"
#include "../../MCAL/03-ADC/ADC_PRIVATE.h"

#define ADC_SINGLE_ENDED_CH0 0
#define ADC_SINGLE_ENDED_CH1 1
#define ADC_SINGLE_ENDED_CH2 2
#define ADC_SINGLE_ENDED_CH3 4
#define ADC_SINGLE_ENDED_CH4 4
#define ADC_SINGLE_ENDED_CH5 5
#define ADC_SINGLE_ENDED_CH6 6
#define ADC_SINGLE_ENDED_CH7 7


void ADC_void_Intilize(void);
uint32 ADC_u32_Get_CHannel_Reading(uint8 Copy_u8Channel);
uint8 ADC_u8_Start_Convertion(uint8 Copy_u8Channel_number);


#endif /* MCAL_03_ADC_ADC_INTERFACE_H_ */
