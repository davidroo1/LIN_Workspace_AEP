/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        Schm_Types.h
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

#ifndef _SCHMTYPES_H                               /* To avoid double inclusion */
#define _SCHMTYPES_H

/* Includes */
/* -------- */
#include "typedefs.h"


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */
typedef void (*TaskFunctionPtrType)(void);
typedef T_UBYTE SchTaskOffsetType;

typedef enum
{
	MASK_3P125MS= 3,
	MASK_6P25MS = 7,
	MASK_12P5MS = 15,
	MASK_25MS   = 31,
	MASK_50MS   = 63,
	MASK_100MS  = 127	
}SchTaskMaskType;

typedef enum
{
	TASK_BKG,
	TASK_3P125MS,
	TASK_6P25MS,
	TASK_12P5MS,
	TASK_25MS,
	TASK_50MS,
	TASK_100MS
}SchTaskIDType;

typedef enum
{
	TASK_STATE_SUSPENDED,
	TASK_STATE_READY,
	TASK_STATE_RUNNING
}SchTaskStateType;

typedef struct
{
	SchTaskStateType 	SchTaskState;
	TaskFunctionPtrType TaskFunctionControlPtr;
}SchTCB; /*Task Control Block*/

typedef struct
{
	SchTaskOffsetType 	SchTaskoffset;
	SchTaskMaskType 	SchTaskMask;
	SchTaskIDType 		SchTaskID;
	TaskFunctionPtrType TaskFunctionPtr;
}SchTaskDescriptorType;

typedef struct
{
	T_UBYTE 					SchNumberOfTasks;
	const SchTaskDescriptorType *SchTaskTable;
}SchConfigType;

typedef enum
{
	SCH_UNINIT,
	SCH_INIT,
	SCH_RUNNING,
	SCH_OVERLOAD,
	SCH_HALTED
}SchStateType;

typedef struct
{
	T_UBYTE 		SchCounter;
	SchTaskIDType 	SchTaskRunning;
	SchStateType 	SchStatus;
}SchControlType;

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


/* Functions macros */


/* Exported defines */


#endif


