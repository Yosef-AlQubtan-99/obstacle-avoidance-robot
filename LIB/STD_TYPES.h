/*
 * STD_TYPES.h
 *
 *  Created on: 15 Oct 2023
 *      Author: Me
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


typedef unsigned char          uint8  ;
typedef signed char            sint8  ;
typedef unsigned short         uint16 ;
typedef signed short           sint16 ;
typedef unsigned long    	   uint32 ;
typedef signed long            sint32 ;
typedef unsigned long long     uint64 ;
typedef signed long long       sint64 ;
typedef float     		       float32;
typedef double       	       float64;


#define NULL	(void *) 0
#define TRUE 1
#define FALSE 1
typedef enum {
  R_NOK=0,
  R_OK
 }ret_status;

#endif /* LIB_STD_TYPES_H_ */
