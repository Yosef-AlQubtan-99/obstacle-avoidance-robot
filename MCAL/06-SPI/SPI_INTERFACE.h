/*
 * SPI_INTERFACE.h
 *
 *  Created on: 27 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_06_SPI_SPI_INTERFACE_H_
#define MCAL_06_SPI_SPI_INTERFACE_H_

void SPI_SEND_DATA(uint8 Copy_local_send_data);
uint8 SPI_READ_DATA(void);
uint8 SPI_TRANS_RECIVE(uint8 Copy_local_send_slave);

#endif /* MCAL_06_SPI_SPI_INTERFACE_H_ */
