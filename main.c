/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "Board_LED.h"
#include "Board_Buttons.h"

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_Name': Sample thread
 *---------------------------------------------------------------------------*/
 
void Thread (void const *argument);                             // thread function
osThreadId tid_Thread;                                          // thread id
osThreadDef (Thread, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread (void) {

  tid_Thread = osThreadCreate (osThread(Thread), NULL);
  if (!tid_Thread) return(-1);
  
  return(0);
}

void Thread (void const *argument) {

  while (1) {
     // Insert thread code here...
		
		LED_On(0);
		LED_On(1);
		LED_On(2);
		LED_On(3);

    osThreadYield ();                                           // suspend thread
  }
}


/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize ();                    // initialize CMSIS-RTOS
	LED_Initialize();
	Buttons_Initialize();

  // initialize peripherals here

  // create 'thread' functions that start executing,
  // example: tid_name = osThreadCreate (osThread(name), NULL);
	Init_Thread();
  osKernelStart ();                         // start thread execution 
}
