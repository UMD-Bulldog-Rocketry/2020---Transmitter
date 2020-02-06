/*
 * SERCOM2_Manager.h
 *
 * Created: 1/30/2020 9:09:46 PM
 *  Author: Brice
 */ 


#ifndef SERCOM2_Manager
#define SERCOM2_Manager

#ifndef CPU_CLK
#define CPU_CLK 48000000
#endif

//USART baud rate calculated by datasheet table 25-2
#define BAUD_RATE_9600 (65536*(CPU_CLK-153600))/CPU_CLK
#define BAUD_RATE_19200 (65536*(CPU_CLK-307200))/CPU_CLK
#define BAUD_RATE_38400 (65536*(CPU_CLK-614400))/CPU_CLK
#define BAUD_RATE_57600 (65536*(CPU_CLK-921600))/CPU_CLK
#define BAUD_RATE_115200 (65536*(CPU_CLK-1843200))/CPU_CLK
#define BAUD_RATE_128000 (65536*(CPU_CLK-2048000))/CPU_CLK
#define BAUD_RATE_256000 (65536*(CPU_CLK-4096000))/CPU_CLK

//Define the serial buffer sizes in bytes.
//Not recommended to be below 32.
#define SER_BUF_SIZE 16

extern char rxBuf [SER_BUF_SIZE];
extern char txBuf [SER_BUF_SIZE];
extern int rxReadHeadPos;
extern int rxWriteHeadPos;
extern int txReadHeadPos;
extern int txWriteHeadPos;

void SERCOM2Event();
void ConfigureSERCOM2();
void registerSercom2();

#endif /* INCFILE1_H_ */