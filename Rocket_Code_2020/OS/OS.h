/*
 * OS.h
 *
 * Created: 1/30/2020 11:05:21 PM
 *  Author: Brice
 */ 


#ifndef OS_H_
#define OS_H_

#ifndef CPU_FREQUENCY
#define CPU_FREQUENCY 48000000
#endif

#include "../Kernel/Kernel.h"

void OSInit();
void OSTick();
uint64_t getMicros();
uint32_t getMillis();


#endif /* OS_H_ */