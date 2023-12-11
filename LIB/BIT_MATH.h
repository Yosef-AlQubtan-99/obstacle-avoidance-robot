/*
 * BIT_MATH.h
 *
 *  Created on: 15 Oct 2023
 *      Author: Me
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define START_BIT (0)
#define SET_BIT(REG, BIT)          REG |=  (1 << (BIT))
#define CLR_BIT(REG, BIT)          REG &= ~(1 << (BIT))
#define TOG_BIT(REG, BIT)          REG ^=  (1 << (BIT))
#define GET_BIT(REG, BIT)           ( (REG >> BIT) & 1 )


#define SET_PORT(REG) (REG=REG | (255<<START_BIT));
#define CLR_PORT(REG) (REG=REG &~ (255<<START_BIT));
#define TOG_PORT(REG) (REG=REG ^ (255<<START_BIT));
#define GET_PORT(REG)           ( (REG >> START_BIT) & 1 )


#endif /* LIB_BIT_MATH_H_ */
