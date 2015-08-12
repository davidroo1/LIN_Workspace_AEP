/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        GPIO.c
* Instance:         RPL_1
* %version:         1
* %created_by:      Diego Flores
* %date_created:    monday July  13 08:26:50 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : General purpose IO functions                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */

/****************************************************************************************************/


/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
/* UART routines prototypes */ 
#include "UART.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */

/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : 	vfnGPIO_Output
 *  Description          : 	Drive the logical output value to the pin
 *  Parameters           :  uint8_t channel - GPIO channel to be configured
 							uint8_t logical_value - select the output value
 *  Return               :	void
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	vfnGPIO_Init_channel
 *  Description          :  Configures individual GPIO pins to either input or output functionality.
 *  Parameters           :  uint8_t channel - GPIO channel to be configured
 							uint8_t input_output - selection of input/output functionality (has impact on output impedance selection)
 							uint8_t Open_drain - Push pull or open drain selection modes	
 *  Return               :	void
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void UART_setBaudRate(T_ULONG lul_BaudRate)
{
		T_UWORD luw_LINIBRR=0;
		T_UWORD luw_LINFBRR=0;
		T_UWORD luw_CalculateBaud=0;
		T_SLONG lsl_CalculateBaud=0;
		T_UBYTE lub_Counter=0; 
		
		luw_LINIBRR=(T_UWORD)(16000000/(lul_BaudRate*16));
		luw_CalculateBaud=luw_LINIBRR*100;
		lsl_CalculateBaud=(T_SLONG)((16000000*100)/(lul_BaudRate*16));
		lsl_CalculateBaud=(lsl_CalculateBaud-luw_CalculateBaud)*16;
		luw_CalculateBaud=0;
		while(lsl_CalculateBaud>0)
		{
			if(lsl_CalculateBaud>100)
			{
			    lsl_CalculateBaud=lsl_CalculateBaud-100;
                luw_CalculateBaud++;
			}
			else
            {
                lsl_CalculateBaud=lsl_CalculateBaud-1;
                lub_Counter++;
                if(lub_Counter>=50)
                {
                    luw_CalculateBaud++;
                    lsl_CalculateBaud=0;
                }
                else
                {
                	/* Do nothing */
                }
            }
		}
		if(luw_CalculateBaud>=16)
		{
			luw_LINIBRR++;
			luw_LINFBRR=0;
		}
		else
		{
			luw_LINFBRR=luw_CalculateBaud;
		}
		
		LINFLEX_2.LINIBRR.R=luw_LINIBRR;
		LINFLEX_2.LINFBRR.R=luw_LINFBRR;	
}