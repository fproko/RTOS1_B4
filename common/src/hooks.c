/*=============================================================================
 * Author: Fernando Prokopiuk <fernandoprokopiuk@gmail.com>
 * Date: 2021/09/10
 *===========================================================================*/

#include <FreeRTOS.h>
#include <task.h>
#include "config.h"

extern print_t debugPrint;
extern TaskHandle_t task_handles[2];

/**
   @brief   This hook function is called if a stack overflow is detected.
			More information is provided in the book text.
			Run time stack overflow checking is performed if
			configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.

   @param pxTask
   @param pcTaskName
 */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    PRINTF( "\r\nApplication Stack Overflow!! on Task: %s\r\n", ( char* )pcTaskName );

    taskENTER_CRITICAL();
    configASSERT( 0 );   /* hang the execution for debugging purposes */
    taskEXIT_CRITICAL();
}

void vApplicationIdleHook()
{

}
