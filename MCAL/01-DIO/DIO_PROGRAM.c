/*
 * main.c
 *
 *  Created on: 5 Oct 2023
 *      Author: Me
 */


#include "DIO_INTERFACE.h"


ret_status DIO_voidSetPinDirection(uint8 __Copy__u8PortNum , uint8 __Copy__u8PinNum , uint8 __Copy__u8Mode)
{
	ret_status ret=R_NOK ;

	if(__Copy__u8Mode== DIO_u8PINOUTPUT){
		switch(__Copy__u8PortNum){
		case DIO_u8PORTA : SET_BIT(DDRA, __Copy__u8PinNum);  break;
		case DIO_u8PORTB : SET_BIT(DDRB, __Copy__u8PinNum); break;
		case DIO_u8PORTC : SET_BIT(DDRC, __Copy__u8PinNum); break;
		case DIO_u8PORTD : SET_BIT(DDRD, __Copy__u8PinNum); break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	else if(__Copy__u8Mode== DIO_u8PININPUT){
		switch(__Copy__u8PortNum){
		case DIO_u8PORTA : CLR_BIT(DDRA, __Copy__u8PinNum); break;
		case DIO_u8PORTB : CLR_BIT(DDRB, __Copy__u8PinNum); break;
		case DIO_u8PORTC : CLR_BIT(DDRC, __Copy__u8PinNum); break;
		case DIO_u8PORTD : CLR_BIT(DDRD, __Copy__u8PinNum); break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	else{
		//return error
	}
	return ret;
}//END FUNC DIO_voidSetPinDirection

ret_status DIO_voidSetPinValue(uint8 __Copy__u8PortNum , uint8 __Copy__u8PinNum , uint8  __Copy__u8Val ){
	ret_status ret=R_NOK ;
	if(DIO_u8PINHIGH== __Copy__u8Val){
		switch(__Copy__u8PortNum){
		case DIO_u8PORTA : SET_BIT(PORTA, __Copy__u8PinNum);  break;
		case DIO_u8PORTB : SET_BIT(PORTB, __Copy__u8PinNum); break;
		case DIO_u8PORTC : SET_BIT(PORTC, __Copy__u8PinNum); break;
		case DIO_u8PORTD : SET_BIT(PORTD, __Copy__u8PinNum); break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	else if(DIO_u8PINLOW== __Copy__u8Val){
		switch(__Copy__u8PortNum){
		case DIO_u8PORTA : CLR_BIT(PORTA, __Copy__u8PinNum);  break;
		case DIO_u8PORTB : CLR_BIT(PORTB, __Copy__u8PinNum); break;
		case DIO_u8PORTC : CLR_BIT(PORTC, __Copy__u8PinNum); break;
		case DIO_u8PORTD : CLR_BIT(PORTD, __Copy__u8PinNum); break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	return ret;
}//END FUNC DIO_voidSetPinValue

ret_status DIO_voidTogllePinValue(uint8 __Copy__u8PortNum , uint8 __Copy__u8PinNum  ){
	ret_status ret=R_NOK ;
	if(__Copy__u8PortNum){
		switch(__Copy__u8PortNum){
		case DIO_u8PORTA : TOG_BIT(PORTA, __Copy__u8PinNum);  break;
		case DIO_u8PORTB : TOG_BIT(PORTB, __Copy__u8PinNum); break;
		case DIO_u8PORTC : TOG_BIT(PORTC, __Copy__u8PinNum); break;
		case DIO_u8PORTD : TOG_BIT(PORTD, __Copy__u8PinNum); break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	return ret;

}//END FUNC DIO_voidSetPinValue

uint8 DIO_voidGetPinValue(uint8 __Copy__u8PortNum, uint8 __Copy__u8PinNum)
{

	uint8 local_u8Result=0;
	switch(__Copy__u8PortNum){
	case DIO_u8PORTA : local_u8Result=GET_BIT(PINA, __Copy__u8PinNum);  break;
	case DIO_u8PORTB : local_u8Result=GET_BIT(PINB, __Copy__u8PinNum); break;
	case DIO_u8PORTC : local_u8Result=GET_BIT(PINC, __Copy__u8PinNum); break;
	case DIO_u8PORTD : local_u8Result=GET_BIT(PIND, __Copy__u8PinNum); break;
	default:             break;
	}
	return local_u8Result;

}//END FUNC DIO_voidGetPinValue


ret_status DIO_voidSetPortDirection(uint8 __Copy__u8PortNum , uint8 __Copy__u8PortsName , uint8 __Copy__u8Mode) {
	ret_status ret=R_NOK ;
	if (__Copy__u8Mode == DIO_u8PORTOUTPUT) {
		switch (__Copy__u8PortNum) {
		case DIO_u8PORTA:  SET_PORT(DDRA);     break;
		case DIO_u8PORTB:  SET_PORT(DDRB);     break;
		case DIO_u8PORTC:  SET_PORT(DDRC);     break;
		case DIO_u8PORTD:  SET_PORT(DDRD);     break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	else if (__Copy__u8Mode == DIO_u8PORTINPUT) {
		switch (__Copy__u8PortNum) {
		case DIO_u8PORTA:  CLR_PORT(DDRA);     break;
		case DIO_u8PORTB:  CLR_PORT(DDRB);     break;
		case DIO_u8PORTC:  CLR_PORT(DDRC);     break;
		case DIO_u8PORTD:  CLR_PORT(DDRD);     break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	return ret;
}//END FUNC DIO_voidSetPortDirection

ret_status DIO_voidSetPortValue(uint8 __Copy__u8PortNum , uint8 __Copy__u8PortsName , uint8 __Copy__u8Val) {
	ret_status ret=R_NOK ;
	if (DIO_u8PORTHIGH == __Copy__u8Val) {
		switch (__Copy__u8PortNum) {
		case DIO_u8PORTA:  SET_PORT(PORTA);     break;
		case DIO_u8PORTB:  SET_PORT(PORTB);     break;
		case DIO_u8PORTC:  SET_PORT(PORTC);     break;
		case DIO_u8PORTD:  SET_PORT(PORTD);     break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	else if (DIO_u8PORTLOW == __Copy__u8Val) {
		switch (__Copy__u8PortNum) {
		case DIO_u8PORTA:  CLR_PORT(PORTA);     break;
		case DIO_u8PORTB:  CLR_PORT(PORTB);     break;
		case DIO_u8PORTC:  CLR_PORT(PORTC);     break;
		case DIO_u8PORTD:  CLR_PORT(PORTD);     break;
		default : ret=R_NOK; break;
		}
		ret=R_OK;
	}
	return ret;
}//END FUNC DIO_voidSetPortValue


uint8 DIO_voidGetPortValue(uint8 __Copy__u8PortNum, uint8 __Copy__u8PortsName)
{

	uint8 local_u8Result=0;
	switch(__Copy__u8PortNum){
	case DIO_u8PORTA : local_u8Result=GET_PORT(PORTA);  break;
	case DIO_u8PORTB : local_u8Result=GET_PORT(PORTB); break;
	case DIO_u8PORTC : local_u8Result=GET_PORT(PORTC); break;
	case DIO_u8PORTD : local_u8Result=GET_PORT(PORTD); break;
	default:             break;
	}
	return local_u8Result;

}//END FUNC DIO_voidGetPinValue
