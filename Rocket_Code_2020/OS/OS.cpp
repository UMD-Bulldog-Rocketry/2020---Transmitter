/*
 * OS.cpp
 *
 * Created: 1/30/2020 11:05:34 PM
 *  Author: Brice
 */ 

#define PROFILING_ENABLED 0



void OSInit(){
	
}

void OSTick(){
	
}

uint32_t getMillis(){
	return (getCurrentClockCycle()*1000)/CPU_FREQUENCY;	
}

uint64_t getMicros(){
	return (getCurrentClockCycle()*1000000)/CPU_FREQUENCY;
}