/*
 * spi_program.c
 *
 *  Created on: 27 Oct 2023
 *      Author: Me
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SPI_CONFIG.h"
#include "SPI_PRIVATE.h"
#include "SPI_INTERFACE.h"
void SPI_MASTER_INTILIZE(void){
#if SPI_MODE==SPI_MASTER
 SET_BIT(SPCR,SPCR_MSTR);
#elif SPI_MODE==SPI_SLAVE
 CLR_BIT(SPCR,SPCR_MSTR);
#endif
 /*SPI C/K PRESCALER F/128*/
#if SPI_MODE==SPI_MASTER
 SET_BIT(SPCR,SPCR_SPR0);
 SET_BIT(SPCR,SPCR_SPR1);
 CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_MODE==SPI_SLAVE
//no generate clock
#endif
 /*SPI ENABLE*/
 SET_BIT(SPCR,SPCR_SPE);
}
void SPI_SEND_DATA(uint8 Copy_local_send_data){
	SPDR=Copy_local_send_data;
	while((GET_BIT(SPSR,SPSR_SPIF))==0){};  //if exit from while the data is send
}
uint8 SPI_READ_DATA(void){
	 uint8 local_read_data=SPDR;
	while((GET_BIT(SPSR,SPSR_SPIF))==0){};
	return local_read_data;
}
uint8 SPI_TRANS_RECIVE(uint8 Copy_local_send_slave){
	//send as master
	//recieve as slave
	//uint8 local_read_master;
	SPDR=Copy_local_send_slave;
	while((GET_BIT(SPSR,SPSR_SPIF))==0){};
   //SPI_DATA=Copy_local_send_slave;
	//FLAG
	//return SPI_DATA;
	return SPDR;
}
