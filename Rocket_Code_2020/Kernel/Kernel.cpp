/*
 * Kernel.cpp
 *
 * Created: 2/5/2020 10:48:21 PM
 *  Author: Brice
 */
#include "sam.h"
#include "IO/uartManager.h"


uint32_t UsartTxEmptyAddr=0, 
	UsartRxCompleteAddr=0, 
	SpiTxEmptyAddr=0, 
	SpiRxCompleteAddr=0, 
	I2cTxEmptyAddr=0, 
	I2cRxCompleteAddr=0, 
	PanicAddr=0, 
	BodAddr=0;

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
}

void registerBodEvents(){
	//TODO
}

//Interrupt
void registerUsartTxEmptyEvent(uint32_t address){
	UsartTxEmptyAddr = address;
}
void registerUsartRxCompleteEvent(uint32_t address){
	UsartRxCompleteAddr = address;
}

void registerSpiTxEmptyEvent(uint32_t address){
	SpiTxEmptyAddr = address;
}
void registerSpiRxCompleteEvent(uint32_t address){
	SpiRxCompleteAddr = address;
}

void registerI2cTxEmptyEvent(uint32_t address){
	I2cTxEmptyAddr = address;
}
void registerI2cRxCompleteEvent(uint32_t address){
	I2cRxCompleteAddr = address;
}

void registerPanicEvent(uint32_t address){
	PanicAddr = address;	
}
void registerBodEvent(uint32_t address){
	BodAddr = address;	
}
