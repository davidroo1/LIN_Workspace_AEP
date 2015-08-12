/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         main.c
* Instance:         RPL_1
* version:          4
* created_by:       Diego Flores/David Rosales 
* date_created:     July 2015
*=============================================================================*/
/* DESCRIPTION : Main C source that initializes and calls scheduler           */
/*============================================================================*/
/* FUNCTION COMMENT : initializes and calls scheduler                         */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.15      | 21/07/2015  |                               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/
#include "MCU_derivative.h"


/** GPIO funtion prototypes  */
#include    "GPIO.h"
#include    "PIT.h"
#include    "SchM.h"
#include    "SchM_Cfg.h"
#include    "MemAlloc_Cfg.h"
#include    "LIN_Driver.h"

/*****************************************************************************************************
* Definition of module wide VARIABLEs 
*****************************************************************************************************/

#define BAUDRATE_9600 9600
/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}

T_UBYTE Function1(T_UBYTE *rpub_U8Ptr)
{
	return (*rpub_U8Ptr);
}   



/*****************************************************************************************************
* Definition of global wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPEs 
*****************************************************************************************************/
    
T_UBYTE (*rpfu_PtrToFctn)(T_UBYTE *); /* Our pointer to function */ 

/******************************************************************************************************
* Definition of module wide VARIABLEs 
******************************************************************************************************/

 T_UBYTE rub_Var1 = 0xFA; 
 T_UBYTE rub_Var2; 
 T_UBYTE * rpub_PtrToU8;

 
/******************************************************************************************************
* Code of module wide FUNCTIONS
******************************************************************************************************/



/*~~~~~~~ Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main(void) 

{
	MemAllocInit(&MemAllocConfig);
	
	
	initModesAndClock();
	/*Enable peri set 1 sysclk divided by 1 */
	initPeriClkGen();
	/* Disable Watchdog */
	disableWatchdog();
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init();
	/*Initialize BUTTONs on TRK-MPC560xB board */
	vfnGPIO_BUTTON_Init();	
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	
	IntcInterruptLINFLEXHandlers();
	
  
  
  	initLINFlex_0(BAUDRATE_9600);         /* Initialize FLEXCAN 0 as slave */
    
    
   SchM_Init(&SchConfig);
    /* Enable External Interrupts*/
    
    
    SchM_Start();
    
	
	/* Infinite loop */
	for (;;) 
	{


        
	}
}

/*~~~~~~~ End of Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


