/*
 * HardFault.h
 *
 * Created: 1/30/2020 9:38:59 PM
 *  Author: Brice Johnson
 */ 


#ifndef HARDFAULT_H_
#define HARDFAULT_H_
#include "sam.h"
#include "samd21g18a.h"

#ifndef MAXIMUM_INTERRUPTS
#define MAXIMUM_INTERRUPTS 10
#endif

extern IRQn_Type interrupts [MAXIMUM_INTERRUPTS];
extern uint32_t currentInterruptIndex;

void handleHardFault();
void registerHardFault();
bool registerInterrupt(IRQn_Type type);

#endif /* HARDFAULT_H_ */