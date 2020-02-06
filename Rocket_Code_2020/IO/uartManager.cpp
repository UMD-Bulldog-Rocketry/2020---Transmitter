/*
 * SERCOM2_Manager.cpp
 *
 * Created: 1/30/2020 9:09:07 PM
 *  Author: Brice Johnson
 */ 
#include "uartManager.h"
#include "sam.h"
#include "samd21g18a.h"

char rxBuf [SER_BUF_SIZE]={};
char txBuf [SER_BUF_SIZE]={};
int rxReadHeadPos = 0;
int rxWriteHeadPos = 0;
int txReadHeadPos = 0;
int txWriteHeadPos = 0;

void registerSercom2(){
	//configure the events of SERCOM2 (USART)
	__NVIC_SetVector(HardFault_IRQn, ((uint32_t) *SERCOM2Event));
	__NVIC_EnableIRQ(SERCOM2_IRQn);
}

void ConfigureSERCOM2(){
	SERCOM2->USART.CTRLA.bit.SWRST = 1; //reset SERCOM 2
		while(SERCOM2->USART.CTRLA.bit.SWRST==1);//Wait for the reset to finish.
		SERCOM2->USART.BAUD.reg = BAUD_RATE_9600;
		SERCOM2->USART.CTRLA.bit.DORD = 0;
		SERCOM2->USART.CTRLA.bit.FORM = 0x01;//USART, 1-bit parity
		SERCOM2->USART.CTRLA.bit.RXPO = 0x01;//Set Rx pin to SERCOM2 Pin 1
		SERCOM2->USART.CTRLA.bit.TXPO = 0x00;//Set Tx pin to SERCOM2 Pin 0
		SERCOM2->USART.CTRLA.bit.SAMPR = 0x01;// oversample 16x, fractional detection
		SERCOM2->USART.CTRLA.bit.IBON = 1; //Overflow notification when frame complete
		SERCOM2->USART.CTRLA.bit.RUNSTDBY = 1; //Still run while sleeping
		SERCOM2->USART.CTRLB.bit.PMODE = 0; //Even parity;
		SERCOM2->USART.CTRLB.bit.ENC = 0;
		SERCOM2->USART.CTRLB.bit.COLDEN = 1; //enable collision detection;
		SERCOM2->USART.CTRLB.bit.SBMODE = 0; //Have one stop bit;
		SERCOM2->USART.CTRLB.bit.CHSIZE = 0; //have a character size of 8 bits;
		SERCOM2->USART.INTENSET.reg = 0b00101110;//Enable a set of interrupts:
											 /*Error Interrupt (bit 7) (Disabled)
											 * Receive Break Interrupt (bit 5)
											 * Receive Start Interrupt (bit 3)
											 * Receive Complete Interrupt (bit 2)
											 * Transmit Complete Interrupt. (bit 1)*/	
		SERCOM2->USART.CTRLA.bit.ENABLE =1;
		SERCOM2->USART.CTRLB.bit.TXEN =1;
		SERCOM2->USART.CTRLB.bit.RXEN =1;
}

void SERCOM2Event(){
	__NVIC_DisableIRQ(SERCOM2_IRQn); //Disable the serial interrupt while handling serial events
	while(SERCOM2->USART.INTFLAG.reg>0){ //While we have flags, continue to try to clear them.
		//Generic catch-all flag
		if(SERCOM2->USART.INTFLAG.bit.ERROR){
			
		}
		//If there is a break in the RX transmission.
		if(SERCOM2->USART.INTFLAG.bit.RXBRK){
			
		}
		//Clear to send (And there is data to send)
		if(SERCOM2->USART.INTFLAG.bit.CTSIC == 1 && txReadHeadPos != txWriteHeadPos){
			SERCOM2->USART.DATA.reg = txBuf[txReadHeadPos];//Write a byte to the tx reg
			txReadHeadPos += 1; //Advance the read head
			txReadHeadPos %= SER_BUF_SIZE; //Loop the read head if necessary.
			SERCOM2->USART.STATUS.bit.CTS = 1; //Clear status indicator
			SERCOM2->USART.INTFLAG.bit.CTSIC = 1;//Clear flag
		}
		//Something new came in!
		if(SERCOM2->USART.INTFLAG.bit.RXC){
			if(rxWriteHeadPos != rxReadHeadPos){ //
				rxBuf[rxWriteHeadPos] = SERCOM2->USART.DATA.reg;
				rxWriteHeadPos = (rxWriteHeadPos+1)%SER_BUF_SIZE;
			}
			SERCOM2->USART.INTFLAG.bit.RXC = 1;//clear flag
		}
		
	}
	__NVIC_ClearPendingIRQ(SysTick_IRQn);//Acknowledge
	__NVIC_EnableIRQ(SERCOM2_IRQn);//Re-enable the serial interrupt
}