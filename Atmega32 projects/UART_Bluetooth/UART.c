/*
 * UART.c
 *
 *  Created on: 23 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART.h"


#define UDR *((volatile u8 *) 0x2c)
#define UCSRA *((volatile u8 *) 0x2B)
#define UDRE 5

#define UBRRH   *((volatile u8*) 0x40)
#define UBRRL   *((volatile u8*) 0x29)
#define UCSRB  *((volatile u8*) 0x2A)
#define UCSRC  *((volatile u8*) 0x40)

#define UBBR   *((volatile u16*) 0x29)

static volatile u8 Data[20];
static u8 Currentindex=0;

void UART_voidInit(void)
{
	u8 UCSRCMASK;
	/*Disable Double speed and multiprocessor communication mode*/
	UCSRA=0;
	/*Choose the BaudRate and Select UBRRH register if needed*/
#if UART_BAUDRATE < 256
	UBRRL=UART_BAUDRATE;
#elif UART_BAUDRATE >= 256
	UBBR =(0b10000000 << 8) | UART_BAUDRATE;

#endif
	/*Choose the UCSRC Register*/
	SET_BIT(UCSRCMASK,7);
	/*Choose Uart Mode*/
#if UART_MODE == UART_ASYNCH
	CLR_BIT(UCSRCMASK,6);
#elif UART_MODE == UART_SYNCH
	SET_BIT(UCSRCMASK,6);
#endif

	/*Choose Uart Parity Bit*/
#if UART_PARITY == UART_PARITY_DISABLE
	CLR_BIT(UCSRCMASK,4);
	CLR_BIT(UCSRCMASK,5);
#elif UART_PARITY == UART_PARITY_EVEN
	CLR_BIT(UCSRCMASK,4);
	SET_BIT(UCSRCMASK,5);
#elif UART_PARITY == UART_PARITY_ODD
	SET_BIT(UCSRCMASK,4);
	SET_BIT(UCSRCMASK,5);
#endif

	/*Choose Uart Mode*/
#if UART_STOP_NUM == UART_ONE_STOP
	CLR_BIT(UCSRCMASK,3);
#elif UART_STOP_NUM == UART_TWO_STOP
	SET_BIT(UCSRCMASK,3);
#endif

#if UART_DATA_SIZE == UART_DATA_SIZE_5
	CLR_BIT(UCSRCMASK,1);
	CLR_BIT(UCSRCMASK,2);
	CLR_BIT(UCSRB,2);
#elif UART_DATA_SIZE == UART_DATA_SIZE_6
	SET_BIT(UCSRCMASK,1);
	CLR_BIT(UCSRCMASK,2);
	CLR_BIT(UCSRB,2);
#elif UART_DATA_SIZE == UART_DATA_SIZE_7
	CLR_BIT(UCSRCMASK,1);
	SET_BIT(UCSRCMASK,2);
	CLR_BIT(UCSRB,2);
#elif UART_DATA_SIZE == UART_DATA_SIZE_8
	SET_BIT(UCSRCMASK,1);
	SET_BIT(UCSRCMASK,2);
	CLR_BIT(UCSRB,2);
#elif UART_DATA_SIZE == UART_DATA_SIZE_9
	SET_BIT(UCSRCMASK,1);
	SET_BIT(UCSRCMASK,2);
	SET_BIT(UCSRB,2);
#endif
	UCSRC=UCSRCMASK;

	/*Enable the transmiter and the receiver*/
	UCSRB=0b00011000;
}
void UART_voidSend(u8 Data)
{
	UDR=Data;
	/*Check that the last transmit is complete*/
	while(GET_BIT(UCSRA,6) == 0);
	/*clear this bit by software*/
	SET_BIT(UCSRA,6);
}

u8 UART_u8ReceivePolling(void)
{
	/*check that there a new byte to read*/
	while(GET_BIT(UCSRA,7) == 0);
	return UDR;
}

void UART_EnableRecieveInterrupt(void)
{
	SET_BIT(UCSRB,7);
}

void UART_DisableRecieveInterrupt(void)
{
	CLR_BIT(UCSRB,7);
}


void Uart_Receive(u8 * data, u16 * len)
{
	u16 i;
	CLR_BIT(UCSRB,7); // disable receive interrupt
	for(i=0;i<Currentindex;i++)
	{
		data[i]=Data[i];
	}
	*len=Currentindex;
	Currentindex=0;
	SET_BIT(UCSRB,7); // enable receive interrupt
}

void __vector_13 (void)__attribute__((signal,used));
void __vector_13 (void)
{
	Data[Currentindex]=UDR;
	Currentindex++;
}

