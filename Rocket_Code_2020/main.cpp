/*
 * Rocket_Code_2020.cpp
 *
 * Created: 1/29/2020 11:30:58 AM
 * Author : Brice Johnson 
 */ 


#define CPU_CLK 48000000 //CPU Clock Speed in Hz
//External modules
#include "sam.h"
#include "samd21g18a.h"
//Local modules
#include "Kernel/Interrupts/HardFault.h"
#include "Kernel/Interrupts/SysTick.h"






int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
	registerHardFault();
	//ConfigureSERCOM2();
	//registerSercom2();
	registerSysTick();	
	
	
		
	//configure this to be sleepytime code;
    while (1) 
    {
		//SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    }
}

	
