/*
 * SPI_PRIVATE.h
 *
 *  Created on: 27 Oct 2023
 *      Author: Me
 */

#ifndef MCAL_06_SPI_SPI_PRIVATE_H_
#define MCAL_06_SPI_SPI_PRIVATE_H_
#include "SPI_CONFIG.h"
#define SPI_MASTER 1u
#define SPI_SLAVE 2u




#define SPCR (*((volatile uint8 *)0x2D))
#define SPCR_SPR0 0U
#define SPCR_SPR1 1U
#define SPCR_CPHA 2U
#define SPCR_CPOL 3U
#define SPCR_MSTR 4U
#define SPCR_DORD 5U
#define SPCR_SPE 6U
#define SPCR_SPIE 7U
#define SPSR (*((volatile uint8 *)0x2E))
#define SPSR_SPI2X 0U
#define SPSR_WCOL 6U
#define SPSR_SPIF 7U
#define SPDR (*((volatile uint8 *)0x2F))
#define SPDR_LSB 0U
#define SPDR_MSB 7U

#endif /* MCAL_06_SPI_SPI_PRIVATE_H_ */
