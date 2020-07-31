#ifndef _DIO_REGISTER
#define _DIO_REGISTER
/* Group A registers */
#define PORTA *((u8*)0x3B)
#define DDRA *((u8*)0x3A)
#define PINA *((u8*)0x39)

/* Group B registers */
#define PORTB *((u8*)0x38)
#define DDRB *((u8*)0x37)
#define PINB *((u8*)0x36)

/* Group C registers */
#define PORTC *((u8*)0x35)
#define DDRC *((u8*)0x34)
#define PINC *((u8*)0x33)

/* Group D registers */
#define PORTD *((u8*)0x32)
#define DDRD *((u8*)0x31)
#define PIND *((u8*)0x30)

#endif