/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        SchM.h
* Instance:         RPL_1
* %version:         1 
* %created_by:      Diego Flores
* %date_created:    Wendsday July 01 10:55:01 2015 
*=============================================================================*/
/* DESCRIPTION : Macro definitios for Background task module                  */
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

#ifndef _SCHM_H                               /* To avoid double inclusion */
#define _SCHM_H

/* Includes */
/* -------- */
#include "SchM_Types.h"


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
extern void SchM_Init(const SchConfigType *SchM_Config);
extern void SchM_Stop(void);
extern void SchM_Start(void);
extern void SchM_OsTick(void);
extern void SchM_Background(void);
extern const SchConfigType (*SchM_ConfigGlobal);


/* Functions macros */


/* Exported defines */


#endif


