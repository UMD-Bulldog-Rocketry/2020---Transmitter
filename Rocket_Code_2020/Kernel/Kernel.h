/*
 * Kernel.h
 *
 * Created: 2/5/2020 10:48:10 PM
 *  Author: Brice
 */ 


#ifndef KERNEL_H_
#define KERNEL_H_

private:
uint32_t UsartTxEmptyAddr, UsartRxCompleteAddr;
uint32_t SpiTxEmptyAddr, SpiRxCompleteAddr;
uint32_t I2cTxEmptyAddr, I2cRxCompleteAddr;
uint32_t PanicAddr;
uint32_t BodAddr;

public:

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
void registerUsartTxEmptyEvent(uint32_t address);
void registerUsartRxCompleteEvent(uint32_t address);

//SPI Interrupts
void registerSpiTxEmptyEvent(uint32_t address);
void registerSpiRxCompleteEvent(uint32_t address);

//I2C Interrupts
void registerI2cTxEmptyEvent(uint32_t address);
void registerI2cRxCompleteEvent(uint32_t address);

void setTimerInterval(uint32_t clockCycles);

//Things that you should hope are never called
void registerPanicEvent(uint32_t address);
void registerBodEvent(uint32_t address);



#endif /* KERNEL_H_ */