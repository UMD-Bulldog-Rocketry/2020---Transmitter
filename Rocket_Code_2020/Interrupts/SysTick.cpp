/*
 * SysTick.cpp
 *
 * Created: 1/30/2020 10:43:15 PM
 *  Author: Brice Johnson
 */ 
#include "SysTick.h"
#include "sam.h"

void registerSysTick(){
	//Configuration of the OS tick interval.
	SysTick->CTRL = 0x05;
	SysTick->LOAD = SYSTICK_INTERVAL_CYCLES;
	__NVIC_SetVector(SysTick_IRQn, ((uint32_t) *handleSysTick));
	__NVIC_EnableIRQ(SysTick_IRQn);
	
}

//Is called once every 10ms.
//Clock budget: 4,799,900 cycles.
void handleSysTick(){
	//TODO:
	__NVIC_ClearPendingIRQ(SysTick_IRQn); //Acknowledge the interrupt
}