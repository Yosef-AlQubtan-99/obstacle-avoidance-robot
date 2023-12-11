#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "DIO_config.h"
#include "DIO_private.h"
#define DIO_u8PORTA 1
#define DIO_u8PORTB 2
#define DIO_u8PORTC 3
#define DIO_u8PORTD 4

#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7

#define DIO_u8PINOUTPUT 1
#define DIO_u8PININPUT 0

#define DIO_u8PORTOUTPUT 0xff
#define DIO_u8PORTINPUT 0x00

#define DIO_u8PINHIGH 1
#define DIO_u8PINLOW 0

#define DIO_u8PORTHIGH 0xff
#define DIO_u8PORTLOW 0x00

///////////////////////////bit////////////////////////////////
//FUNC SET DIRECTION (DDDR)
ret_status DIO_voidSetPinDirection(uint8 __Copy__u8PortNum , uint8 __Copy__u8PinNum , uint8 __Copy__u8Mode);
ret_status DIO_voidSetPinValue(uint8 __Copy__u8PortNum , uint8 __Copy__u8PinNum , uint8  __Copy__u8Val );
ret_status DIO_voidTogllePinValue(uint8 __Copy__u8PortNum , uint8 __Copy__u8PinNum  );
uint8 DIO_voidGetPinValue(uint8 __Copy__u8PortNum, uint8 __Copy__u8PinNum);
///////////////////////////port////////////////////////////////////
ret_status DIO_voidSetPortDirection(uint8 __Copy__u8PortNum , uint8 __Copy__u8PortsNum , uint8 __Copy__u8Mode);
ret_status DIO_voidSetPortValue(uint8 __Copy__u8PortNum , uint8 __Copy__u8PortsNum , uint8 __Copy__u8Val);
uint8 DIO_voidGetPortValue(uint8 __Copy__u8PortNum, uint8 __Copy__u8PortsNum);

#endif

