/*
 * Kernel.cpp
 *
 * Created: 2/5/2020 10:48:21 PM
 *  Author: Brice
 */
#include "Kernel.h"


/*void *(UsartTxEmptyAddr)(), // not used at the moment.
	*(UsartRxCompleteAddr)(), 
	*(SpiTxEmptyAddr)(), 
	*(SpiRxCompleteAddr)(), 
	*(I2cTxEmptyAddr)(), 
	*(I2cRxCompleteAddr)(), 
	*(PanicAddr)(), 
	*(BodAddr)();*/

void initUSART(){
	ConfigureSERCOM2();
}

void initSPI(){
	//TODO
}

void initI2C(){
	//TODO
}

void initCriticalSystems(){
	//TODO
}

void initTimerSystems(){
	//TODO
}

void initBodEvents(){
	//TODO
}

//Interrupt registry.

void registerUSARTEvents(){
	registerSercom2();
}

void registerSPIEvents(){
	//TODO
}

void registerI2CEvents(){
	//TODO
}

void registerCriticalEvents(){
	//TODO
}

void registerTimerEvents(){
	//TODO
	return;
}

void registerBodEvents(){
	//TODO
	registerSpiTxEmptyEvent(*(registerTimerEvents())); // example, do not use in implementation
}

//Interrupt
void registerUsartTxEmptyEvent(void (*address)()){
	UsartTxEmptyAddr = *address;
}
void registerUsartRxCompleteEvent(void (*address)()){
	UsartRxCompleteAddr = address;
	address();
}

void registerSpiTxEmptyEvent(void (*address)()){
	SpiTxEmptyAddr = address;
}
void registerSpiRxCompleteEvent(void (*address)()){
	SpiRxCompleteAddr = *address;
}

void registerI2cTxEmptyEvent(void (address)()){
	I2cTxEmptyAddr = *address;
}
void registerI2cRxCompleteEvent(void (*address)()){
	I2cRxCompleteAddr = *address;
}

void registerPanicEvent(void (*address)()){
	PanicAddr = address;	
}
void registerBodEvent(void (*address)()){
	BodAddr = address;	
}

void setTimerInterval(uint32_t clockCycles){
	//TODO
}
