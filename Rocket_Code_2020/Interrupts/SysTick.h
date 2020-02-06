/*
 * SysTick.h
 *
 * Created: 1/30/2020 10:42:46 PM
 *  Author: Brice Johnson
 */ 


#ifndef SYSTICK_H_
#define SYSTICK_H_

#ifndef CPU_CLK
#define CPU_CLK 48000000
#endif

#define SYSTICK_INTERVAL_MS 10 //System should always run at 100 Hz
#define SYSTICK_INTERVAL_CYCLES (CPU_CLK/1000*SYSTICK_INTERVAL_MS)-1
#define SYSTICK_CALIBRATION_VALUE (CPU_CLK/100)-1

void registerSysTick();
void handleSysTick();

#endif /* SYSTICK_H_ */