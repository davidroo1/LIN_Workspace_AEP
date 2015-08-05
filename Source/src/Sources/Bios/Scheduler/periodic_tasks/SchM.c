/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         SchM.c
* Instance:         RPL_1
* %version:         1
* %created_by:      Diego Flores
* %date_created:    Mon Jul  13 10:20:00 2015 		
*=============================================================================*/
/* DESCRIPTION : SchM                                                         */
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
#include "SchM.h"
#include "SchM_Cfg.h"
#include "PIT.h"
#include "MemAlloc_Cfg.h"


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

SchControlType SchControl=
{
	 0, TASK_BKG, SCH_UNINIT 	
};

SchTCB *SchTCBPtr;

/* WORD RAM variables */

/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */
const SchConfigType *SchM_ConfigGlobal;

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

void SchM_Init(const SchConfigType *SchM_Config)
{
	/*inicializar todo en suspended task control estado y la funcion a donde tiene que ir*/
	
	T_UBYTE lub_index;
	SchM_ConfigGlobal=SchM_Config;
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , &SchM_OsTick);
    
     SchTCBPtr=(SchTCB*)MemAlloc(SchM_ConfigGlobal->SchNumberOfTasks*sizeof(SchTCB));
	/*crear una variable global inicializarla con SchM_Config*/
	for(lub_index=0; lub_index<SchM_ConfigGlobal->SchNumberOfTasks;lub_index++)
	{
		SchTCBPtr[lub_index].SchTaskState=TASK_STATE_SUSPENDED;
		SchTCBPtr[lub_index].TaskFunctionControlPtr= SchM_ConfigGlobal->SchTaskTable[lub_index].TaskFunctionPtr;
	}
	
	
	SchControl.SchStatus=SCH_INIT;
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void SchM_Stop(void)
{
	PIT_channel_stop(PIT_CHANNEL_0);
	SchControl.SchStatus=SCH_HALTED;	
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
/*const SchMConfigType *schmconfigglobal;*/
void SchM_Start(void)
{
	/*arrancar el timer pit*/
	
		
    PIT_channel_start(PIT_CHANNEL_0);
	enableIrq();
	SchControl.SchStatus=SCH_RUNNING;
	SchM_Background();
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void SchM_OsTick(void)
{
	T_UBYTE lub_index;
	
	SchControl.SchCounter++;
	
	for(lub_index=0; lub_index<SchM_ConfigGlobal->SchNumberOfTasks;lub_index++)
	{
		
		if(((SchM_ConfigGlobal->SchTaskTable[lub_index].SchTaskMask) & (SchControl.SchCounter)) == (SchM_ConfigGlobal->SchTaskTable[lub_index].SchTaskoffset))
		{
				SchTCBPtr[lub_index].SchTaskState=TASK_STATE_READY;
		}	
	}
}


/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void SchM_Background(void)
{   
    /*checar el estado de las tareas a raves del task control type*/
	for (;;) 
	{
			T_UBYTE lub_index;
		
		
		for(lub_index=0; lub_index<SchM_ConfigGlobal->SchNumberOfTasks;lub_index++)
		{
			if(SchTCBPtr[lub_index].SchTaskState==TASK_STATE_READY)
			{
				SchTCBPtr[lub_index].SchTaskState = TASK_STATE_RUNNING;
				SchControl.SchTaskRunning=SchM_ConfigGlobal->SchTaskTable[lub_index].SchTaskID;
				SchTCBPtr[lub_index].TaskFunctionControlPtr();
				SchTCBPtr[lub_index].SchTaskState = TASK_STATE_SUSPENDED;
				SchControl.SchTaskRunning=TASK_BKG;
			}
			else
			{
				/*Do nothing*/
			}	
		}   
	}
}