/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        Scheduler task callback functions.h
* Instance:         RPL_1
* %version:         1 
* %created_by:      Diego Flores
* %date_created:    Wendsday July 01 10:55:01 2015 
*=============================================================================*/
/* DESCRIPTION : Macro definitios for Scheduler task callback functions module*/
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  | SAR/SIF/SCN_xxx               | Diego Flores     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef _SCHMTASK_H                               /* To avoid double inclusion */
#define _SCHMTASK_H

/* Includes */
/* -------- */


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void SchM_Task_1p563ms(void);
extern void SchM_Task_3p125ms(void);
extern void SchM_Task_6p25ms(void);
extern void SchM_Task_12p5ms(void);
extern void SchM_Task_25ms(void);
extern void SchM_Task_50ms(void);
extern void SchM_Task_100ms(void);

/* Functions macros */


/* Exported defines */


#endif


