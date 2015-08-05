/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         SchM_Cfg.c
* Instance:         RPL_1
* %version:         1
* %created_by:      Diego Flores
* %date_created:    Mon Jul  13 10:20:00 2015 		
*=============================================================================*/
/* DESCRIPTION : SchM_Cfg                                                     */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/01/2015  |       descripcion de modulo   | Diego Flores     */
/* Integration under Continuus CM                                             */
	/*============================================================================*/

/* Includes */
/* -------- */
#include "SchM_Cfg.h"
#include "SchM_Tasks.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
const SchTaskDescriptorType SchTaskDescConfig [] =
{
/*  offset, Mask,        Task ID,    Function Pointer   */ 
	{ 0, MASK_3P125MS, TASK_3P125MS, &SchM_Task_3p125ms },
	{ 1, MASK_6P25MS,  TASK_6P25MS,  &SchM_Task_6p25ms  },
	{ 2, MASK_12P5MS,  TASK_12P5MS,  &SchM_Task_12p5ms  },
	{ 3, MASK_25MS,    TASK_25MS,    &SchM_Task_25ms  	},
	{ 5, MASK_50MS,    TASK_50MS,    &SchM_Task_50ms  	},
	{ 6, MASK_100MS,   TASK_100MS,   &SchM_Task_100ms 	}    	
};

const SchConfigType SchConfig =
{
	(sizeof(SchTaskDescConfig)/sizeof(SchTaskDescConfig[0])),
	SchTaskDescConfig	
};

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
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
