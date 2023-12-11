#include<avr/io.h>
#include<util/delay.h>
#include "../../MCAL/01-DIO/DIO_INTERFACE.h"
#include "../../HAL/03-CLCD/Clcd_Interface.h"
#include"math.h"
#define DIO_u8PORTHIGH 0xff
#define DIO_u8PORTLOW 0x00
#define DIO_u8PINHIGH 1
#define DIO_u8PINLOW 0
#define CLCD_DATA PORTC
//char b[7]={0x10,0x10,0x16,0x19,0x11,0x11,0x1E};

void Clcd_void_send_en(void){
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8PINHIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8PINLOW);
	_delay_ms(2);
}
void Clcd_void_send_data(char Clcd_u8data){
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINHIGH);
	//DIO_voidSetPortValue(CLCD_DATA_8_PORT,PORTA,Clcd_u8data);
	CLCD_DATA=DIO_u8PORTLOW;
	CLCD_DATA=Clcd_u8data;
	Clcd_void_send_en();
}
void Clcd_void_send_command(char Clcd_u8command){
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINLOW);
	//DIO_voidSetPortValue(CLCD_DATA_8_PORT,PORTA,Clcd_u8command);
	CLCD_DATA=DIO_u8PORTLOW;
	CLCD_DATA=Clcd_u8command;
	Clcd_void_send_en();
}
#if CLCD_MODE==8
static void Clcd_void_8bit_intilize(void){
	DIO_voidSetPortDirection(CLCD_DATA_8_PORT,DDRC,DIO_u8PORTOUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8PINOUTPUT);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8PORTLOW);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PORTLOW);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINLOW);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8PINLOW);
	DIO_voidSetPortValue(CLCD_DATA_8_PORT,PORTC,DIO_u8PORTLOW);
}
#endif
#if CLCD_MODE==4
static void Clcd_void_send_4bit(char Clcd_u8data){
	//DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINHIGH);
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN4,((Clcd_u8data>>0 & 0x01)) );
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN5,((Clcd_u8data>>1 & 0x01)) );
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN6,((Clcd_u8data>>2 & 0x01)) );
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN7,((Clcd_u8data>>3 & 0x01)) );
}
static void Clcd_void_send_4bit_Command(char Clcd_u8command){
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINLOW);
	Clcd_void_send_4bit(Clcd_u8command>>4); //SEND 4BIT HIGH
	Clcd_void_send_en();
	Clcd_void_send_4bit(Clcd_u8command & 0x0F ); //SEND 4BIT LOW
	Clcd_void_send_en();
}
void Clcd_void_send_4bit_Data(char Clcd_u8data){
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINHIGH); //data
	Clcd_void_send_4bit(Clcd_u8data>>4); //SEND 4BIT HIGH
	Clcd_void_send_en();
	Clcd_void_send_4bit(Clcd_u8data & 0x0F ); //SEND 4BIT LOW
	Clcd_void_send_en();
}
static void Clcd_void_4bit_intilize(void){
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8PINOUTPUT);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PINLOW);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8PINLOW);
	DIO_voidSetPinDirection(CLCD_DATA_8_PORT,CLCD_DATA_PIN4,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_8_PORT,CLCD_DATA_PIN5,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_8_PORT,CLCD_DATA_PIN6,DIO_u8PINOUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_8_PORT,CLCD_DATA_PIN7,DIO_u8PINOUTPUT);
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN4,DIO_u8PINLOW);
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN5,DIO_u8PINLOW);
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN6,DIO_u8PINLOW);
	DIO_voidSetPinValue(CLCD_DATA_8_PORT,CLCD_DATA_PIN7,DIO_u8PINLOW);
}


#endif
void Clcd_void_Intilization(void){
#if CLCD_MODE==8
	Clcd_void_8bit_intilize();
	/////////////////////////
	Clcd_void_send_command(CLCD_CLEAR_DISPLAY); //CLEAR LCD
	Clcd_void_send_en();
	_delay_ms(2);
	Clcd_void_send_command(CLCD_RETURN_HOME);
	Clcd_void_send_en();
	_delay_ms(2);
	Clcd_void_send_command(CLCD_CURSOR_OFF_DISPLAY_ON); //AUTO INCREMENT
	Clcd_void_send_en();
	_delay_ms(2);
	Clcd_void_send_command(CLCD_8BIT_MODE_2LINE); //AUTO INCREMENT
	Clcd_void_send_en();
	_delay_ms(2);
	Clcd_void_send_command(CLCD_SET_DDRAM); //START WRITE FROM 0 , 0
	Clcd_void_send_en();
	_delay_ms(2);
#elif CLCD_MODE==4
	Clcd_void_4bit_intilize();
	Clcd_void_send_4bit_Command(CLCD_CLEAR_DISPLAY); //CLEAR LCD
	_delay_ms(2);
	Clcd_void_send_4bit_Command(CLCD_RETURN_HOME);
	_delay_ms(2);
	Clcd_void_send_4bit_Command(CLCD_CURSOR_OFF_DISPLAY_ON); //AUTO INCREMENT
	_delay_ms(2);
	Clcd_void_send_4bit_Command(CLCD_4BIT_MODE_2LINE);
	_delay_ms(2);
	Clcd_void_send_4bit_Command(CLCD_SET_DDRAM); //START WRITE FROM 0 , 0
	_delay_ms(2);
#else
#error
#endif


}
void Clcd_set_cursor(uint8 row, uint8 col){
	row--;
	col--;
#if CLCD_MODE==8
	Clcd_void_send_command((CLCD_SET_DDRAM + ((0x40 * row) + col)));
	_delay_ms(5);
#endif
#if CLCD_MODE==4
	Clcd_void_send_4bit_Command((CLCD_SET_DDRAM + ((0x40 * row) + col)));
	_delay_ms(5);
#endif
}

void Clcd_write_string(char *ptr_string){
	while(*ptr_string){
#if CLCD_MODE==8
		Clcd_void_send_data(*ptr_string++);
		_delay_ms(5);
#endif
#if CLCD_MODE==4
		Clcd_void_send_4bit_Data(*ptr_string++);
		_delay_ms(5);
#endif
	}
}

void lcd_sed_string_pos(uint8 row, uint8 col, char *info){
	Clcd_set_cursor(row,col);
	Clcd_write_string(info);
}


void lcd_WritNumber(uint64 NUM)
{
	uint64 reverse=1;
	while(NUM!=0)
	{
		reverse=(reverse*10)+(NUM%10);
		NUM/=10;
	}
	while(reverse!=1)
	{
#if CLCD_MODE==8
		Clcd_void_send_data((reverse%10)+48);
		reverse/=10;
#endif
#if CLCD_MODE==4
		Clcd_void_send_4bit_Data((reverse%10)+48);
		reverse/=10;
#endif

	}
}
void lcd_WritNumber_16(uint32 NUM)
{
	uint32 reverse=1;
	while(NUM!=0)
	{
		reverse=(reverse*10)+(NUM%10);
		NUM/=10;
	}
	while(reverse!=1)
	{
#if CLCD_MODE==8
		Clcd_void_send_data((reverse%10)+48);
		reverse/=10;
#endif
#if CLCD_MODE==4
		Clcd_void_send_4bit_Data((reverse%10)+48);
		reverse/=10;
#endif

	}
}
/*
void Clcd_Display_name_arabic_incr(void){
	//uint8 s=6;
	//uint8 name[6]= {'M','O','H','A','M','E','D'};
	char names[]={ 0x00,
			  0x02,
			  0x02,
			  0x0E,
			  0x00,
			  0x00,
			  0x00,
			  0x00};
	//for(uint8 i=1;i<2;i++){
	//	for(uint8 j=1;j<=16;j++){
			//lcd_sed_string_pos(1,1,&names);
	          Clcd_void_send_data(names);
			_delay_ms(500);
			Clcd_void_send_data(" ");
			_delay_ms(500);
		//}
	//}
}


void Clcd_Display_name_sin(void){
	char namess[6]={'M','O','H','A','M','E','D'};
	for(uint8 i=1;i<2;i++){
		//for(uint8 j=1;j<=10;j++){
		lcd_sed_string_pos(i,i,&namess);
		_delay_ms(200);
		lcd_sed_string_pos(i,i+6," ");
		lcd_sed_string_pos(i+1,i+6,&namess);
		_delay_ms(200);
		lcd_sed_string_pos(i+1,i+6," ");
		lcd_sed_string_pos(i,i+12,&namess);
		_delay_ms(200);
		}

		//lcd_sed_string_pos(1,13,"  ");

	}


/*
void Clcd_Display_name_increment(void){
	uint8 s=6;
	//uint8 name[6]= {'M','O','H','A','M','E','D'};
	char names[6]={'M','O','H','A','M','E','D'};
	for(uint8 i=1;i<2;i++){
		for(uint8 j=1;j<=16;j++){
			lcd_sed_string_pos(i,j,&names);
			_delay_ms(100);
			lcd_sed_string_pos(i,j," ");
			_delay_ms(100);
			if(j==16 ){
				for(s=6;s>=1;s--){
					lcd_sed_string_pos(i,i,&names[s]);
					_delay_ms(100);
					lcd_sed_string_pos(i,i," ");
					_delay_ms(100);
				}
			}
		}
	}
}
 */
