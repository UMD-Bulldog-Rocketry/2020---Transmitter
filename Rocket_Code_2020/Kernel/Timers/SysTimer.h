/*
 * SysTimer.h
 *
 * Created: 2/9/2020 11:43:41 AM
 *  Author: Brice
 */ 

//This is the timer used to coordinate the real time events.

#ifndef SYSTIMER_H_
#define SYSTIMER_H_



void initSysTimer();
void registerSysTimerEvents();
void unregisterSysTimerEvents();
uint32_t getCurrentMillis();


#endif /* SYSTIMER_H_ */