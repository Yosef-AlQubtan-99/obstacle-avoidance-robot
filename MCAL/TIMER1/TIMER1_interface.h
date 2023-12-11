#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H
#include "../../MCAL/TIMER1/TIMER1_private.h"
#include "../../MCAL/TIMER1/TIMER1_config.h"
/******************************************************************************
*********************************** Typedef ***********************************
******************************************************************************/

/******************************************************************************
* !comment  :  TIMER1 Mode Options.  							 			  *   
******************************************************************************/

typedef enum{

	TIMER1_NORMAL_MODE = 0,
	TIMER1_PHASE_CORRECT_8BIT_MODE,
	TIMER1_PHASE_CORRECT_9BIT_MODE,
	TIMER1_PHASE_CORRECT_10BIT_MODE,
	TIMER1_CTC_OCR1A_MODE,
	TIMER1_FAST_PWM_8BIT_MODE,
	TIMER1_FAST_PWM_9BIT_MODE,
	TIMER1_FAST_PWM_10BIT_MODE,
	TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_MODE,
	TIMER1_PWM_PHASE_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TIMER1_CTC_ICR1_MODE,
	TIMER1_FAST_PWM_ICR1_MODE,
	TIMER1_FAST_PWM_OCR1A_MODE,

}Timer1_Mode_t;

/******************************************************************************
* !comment  :  TIMER1 Prescaler Value Options.  							  *   
******************************************************************************/

typedef enum{

	TIMER1_STOP = 0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	TIMER1_EXTERNAL_FALLING,
	TIMER1_EXTERNAL_RISING,

}Timer1_Scaler_t;

/******************************************************************************
* !comment  :  TIMER1 Output Compare Mode Options.  						  *   
******************************************************************************/

typedef enum{

	TIMER1_OC1_DISCONNECTED_MODE = 0,
	TIMER1_OC1_TOGGLE_MODE,
	TIMER1_OC1_NON_INVERTING_MODE,
	TIMER1_OC1_INVERTING_MODE,

}Timer1_OutputCompareMode_t;

/******************************************************************************
* !comment  :  TIMER1 Channel Options.  							          *   
******************************************************************************/

typedef enum{

	TIMER1_OCR1A = 0,
	TIMER1_OCR1B,

}Timer1_Channel_t;

/******************************************************************************
* !comment  :  TIMER1 ICU Edge Options.  							          *   
******************************************************************************/

typedef enum{

	ICU_RISING_EDGE = 0,
	ICU_FALLING_EDGE,

}ICU_Edge_t;


/******************************************************************************
***************************** Function Prototypes *****************************
******************************************************************************/

/******************************************************************************
* Description 	: TIMER1 Initialization Function to select timer mode         *
*			      & Prescaler vale.                                           *
*                                                                             *
* Parameters  	: Timer1 Mode , Timer1 Scaler.                                *
* Return type 	: void                       								  *
*******************************************************************************
* Pre_condition : none.      												  *
******************************************************************************/

void TIMER1_voidInit(Timer1_Mode_t Mode, Timer1_Scaler_t Prescaler);
/******************************************************************************
* Description 	: TIMER1 Output Compare initialization Function to            *
*                 Select Output Compare Mode & Channel.                       *
* Parameters  	: Timer1 Output Compare Mode , Timer1 Channel.		          *
* Return type 	: void                       								  *
*******************************************************************************
* Pre_condition : This function must be used after timer1 initialization.     *
******************************************************************************/

void TIMER1_voidOutputCompareInit(Timer1_OutputCompareMode_t OC1_Mode, Timer1_Channel_t OC1_Channel);
void Timer1_U8_SET_CALL_BACK(void(*p1(void)));
void Timer1_U8_SET_CALL_BACK2(void(*p1(void)));

/******************************************************************************
* Description 	: TIMER1 Get Input Capture Register1 Value Function.          *
* Parameters  	: none.                                                       *
* Return type 	: uint16.                                                  	  *
*******************************************************************************
* Pre_condition : This function must be used after timer1 initialization.     *
******************************************************************************/

uint16 TIMER1_u16GetICR1(void);

/******************************************************************************
* Description 	: TIMER1 Set Output Compare Register1 A Value.	              *
* Parameters  	: Compare Value ( 0 ---> 65535 ).                             *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidSetOCR1A(uint16 Copy_u16Value);

/******************************************************************************
* Description 	: TIMER1 Set Output Compare Register1 B Value.	              *
* Parameters  	: Compare Value ( 0 ---> 65535 ).                             *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidSetOCR1B(uint16 Copy_u16Value);

/******************************************************************************
* Description 	: TIMER1 Set Input Capture Register1 Value.	                  *
* Parameters  	: Compare Value ( 0 ---> 65535 ).                             *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidSetICR1(uint16 Copy_u16Value);

/******************************************************************************
* Description 	: TIMER1 Set TCNT1 Value.	                                  *
* Parameters  	: Compare Value ( 0 ---> 65535 ).                             *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidSetTCNT1(uint16 Copy_u16Value);

/******************************************************************************
* Description 	: TIMER1 Overflow Interrupt Enable Function.		          *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidOVF_InterruptEnable(void);

/******************************************************************************
* Description 	: TIMER1 Overflow Interrupt Disable Function.				  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidOVF_InterruptDisable(void);

/******************************************************************************
* Description 	: TIMER1 Input Capture Unit Interrupt Enable Function.		  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidICU_InterruptEnable(void);

/******************************************************************************
* Description 	: TIMER1 Input Capture Unit Interrupt Disable Function.		  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidICU_InterruptDisable(void);

/******************************************************************************
* Description 	: TIMER1 Output Compare A Interrupt Enable Function.		  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidOCA_InterruptEnable(void);

/******************************************************************************
* Description 	: TIMER1 Output Compare A Interrupt Disable Function.		  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidOCA_InterruptDisable(void);

/******************************************************************************
* Description 	: TIMER1 Output Compare B Interrupt Enable Function.		  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidOCB_InterruptEnable(void);

/******************************************************************************
* Description 	: TIMER1 Output Compare B Interrupt Disable Function.		  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void TIMER1_voidOCB_InterruptDisable(void);

/******************************************************************************
* Description 	: TIMER1 PWM initialization Function.		                  *
* Parameters  	: none   		                                    	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/

void PWM1_voidInit(void);

/******************************************************************************
* Description 	: TIMER1 Generate PWM @ Frequency (KHZ) Function.		      *
* Parameters  	: Frequency (KHZ).   		                           	 	  *
* Return type 	: void                                                  	  *
*******************************************************************************
* Pre_condition : none.                                                       *
******************************************************************************/
#endif
