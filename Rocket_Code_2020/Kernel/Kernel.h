/*
 * Kernel.h
 *
 * Created: 2/5/2020 10:48:10 PM
 *  Author: Brice
 */ 


#ifndef KERNEL_H_
#define KERNEL_H_
#include "sam.h"
#include "IO/uartManager.h"

//private:
void (*UsartTxEmptyAddr)(), (*UsartRxCompleteAddr)();
void (*SpiTxEmptyAddr)(), (*SpiRxCompleteAddr)();
void (*I2cTxEmptyAddr)(), (*I2cRxCompleteAddr)();
void (*PanicAddr)();
void (*BodAddr)();

//public:

void initUSART();
void initSPI();
void initI2C();
void initCriticalSystems(); //Hardfault systems
void initTimerSystems(); //SysTick
void initBODSystem(); //Brown-out Detection

void registerUSARTEvents();
void registerSPIEvents();
void registerI2CEvents();
void registerCriticalEvents();
void registerTimerEvents();
void registerBODEvents();

//USART Interrupts
void registerUsartTxEmptyEvent(void *(address)());
void registerUsartRxCompleteEvent(void *(address)());

//SPI Interrupts
void registerSpiTxEmptyEvent(void *(address)());
void registerSpiRxCompleteEvent(void *(address)());

//I2C Interrupts
void registerI2cTxEmptyEvent(void *(address)());
void registerI2cRxCompleteEvent(void *(address)());

//Things that you should hope are never called
void registerPanicEvent(void *(address)());
void registerBodEvent(void *(address)());

void setTimerInterval(uint32_t clockCycles);

#endif /* KERNEL_H_ */