/*
 * HardFault.cpp
 *
 * Created: 1/30/2020 9:40:33 PM
 *  Author: Brice
 */ 

#include "HardFault.h"
IRQn_Type interrupts [MAXIMUM_INTERRUPTS] ={};
uint32_t currentInterruptIndex = 0;

/*The Hardfault ISR runs when the processor 
 *Encounters one of three things:
 *1) Unknown Op-codes are encountered
 *2) A memory read or write operation fails
 *3) Memory Write attempts that are misaligned
 *
 *This code should close all communications,
 *disable all ISRs, and run system critical code.
 */
void handleHardFault(){
	while(currentInterruptIndex>0){
		__NVIC_DisableIRQ(interrupts[currentInterruptIndex]);
		currentInterruptIndex--;
	}
	
	while(1){
		
	}
}
/*This should be called when any non-critical
* interrupt is registered in the system.
* Anything added to this registry will automatically
* be un-registered during fault time.
**/
bool registerInterrupt(IRQn_Type type){
	if(currentInterruptIndex >= MAXIMUM_INTERRUPTS){
		return false;
	}else{
		interrupts[currentInterruptIndex] = type;
		currentInterruptIndex++;
		return true;
	}
}
/*Registers a hard Fault in the interrupt system.
* This should be the first thing called after SystemInit()*/
void registerHardFault(){
	__NVIC_SetVector(HardFault_IRQn, ((uint32_t) *handleHardFault));
	__NVIC_EnableIRQ(HardFault_IRQn);
}