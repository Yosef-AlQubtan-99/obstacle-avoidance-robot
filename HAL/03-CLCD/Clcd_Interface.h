#ifndef CLCD_INTERFACE_H

#define CLCD_INTERFACE_H
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../03-CLCD/Clcd_private.h"
#include "../03-CLCD/Clcd_config.h"
#define CLCD_RS_PIN  DIO_u8PIN1
#define CLCD_CONTROL_PORT DIO_u8PORTB
#define CLCD_DATA_8_PORT  DIO_u8PORTA
#define CLCD_EN_PIN  DIO_u8PIN3
#define CLCD_DATA_PIN4 DIO_u8PIN4
#define CLCD_DATA_PIN5 DIO_u8PIN5
#define CLCD_DATA_PIN6 DIO_u8PIN6
#define CLCD_DATA_PIN7 DIO_u8PIN7
/*
typedef struct {
#if CLCD_MODE==8


#elif CLCD_MODE==4

#else
#error
#endif
}lcd_mode;
*/
void Clcd_void_send_en(void);
void Clcd_void_send_data(char Clcd_u8data);
void Clcd_void_send_command(char Clcd_u8command);
void Clcd_void_Intilization(void);
void Clcd_set_cursor(uint8 row, uint8 col);
void Clcd_write_string(char *ptr_string);
void lcd_sed_string_pos(uint8 row, uint8 col, char *info);
void lcd_WritNumber(uint64 NUM);
void lcd_WritNumber_16(uint32 NUM);
static void Clcd_void_8bit_intilize(void);
static void Clcd_void_4bit_intilize(void);
static void Clcd_void_send_4bit(char Clcd_u8data);
static void Clcd_void_send_4bit_Command(char Clcd_u8command);
void Clcd_void_send_4bit_Data(char Clcd_u8data);
static void Clcd_void_4bit_Display(void);

//void Clcd_Go_to(uint8 row ,uint8 col);
void Clcd_Display_name_sin(void);
//void Clcd_Display_name_sin(void);
//void Clcd_Display_name_arabic_incr(void);

//uint64 lcd_convert_to_binary(uint8 num);



#endif

