#include "Serial.h"
#define F_CPU 16000000UL
/*************Hardware dependent Functions*********/
void SerialBegin(uint32_t baud)
{
	// Set baud rate
	//#ifdef F_CPU
	//#warning "F_CPU Defined"
	uint16_t ubrr = F_CPU / 16 / baud - 1;
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)ubrr;
	// Set frame format | 8 bit 1 stop bit
	UCSR0C = (1 << USBS0) | (3 << UCSZ00);
	// Enable TX RX
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	//#else
	//	#error "Please define F_CPU before #include "Serial.h""
	//#endif

	
}

void SerialPrintChar(unsigned char c)
{
	// Wait for transmit buffer to empty
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = c;
}

void SerialPrint(char *str)
{
	while (*str)
	{
		while (!(UCSR0A & (1 << UDRE0)));
		UDR0 = *str;
		str++;
	}
}

void SerialPrintln(char *str)
{
	SerialPrint(str);
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = '\r';
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = '\n';
}

/************Hardware Independent Functions************/


void SerialPrintU32(uint32_t n)
{
	char buf[13];
	char *ptr = &buf[sizeof(buf) - 1]; //buf[12] -> last index of buffer
	*ptr = '\0';//null last index

	uint32_t  temp;
	char c;
	do
	{
		temp = n;
		n = n/10;
		c = temp - n*10;
		*--ptr = c + '0';
	}while(n);
	SerialPrint(ptr);
}

void SerialPrintlnU32(uint32_t n)
{
	char buf[15];
	char *ptr = &buf[sizeof(buf) - 1]; //buf[12] -> last index of buffer
	*ptr = '\0';
	*--ptr  = '\n';
	*--ptr  = '\r';

	uint32_t  temp;
	char c;
	do
	{
		temp = n;
		n = n/10;
		c = temp - n*10;
		*--ptr = c + '0';
	}while(n);
	SerialPrint(ptr);
}

void SerialPrintS32(int32_t n)
{
	if(n < 0)
	{
		SerialPrintChar('-');
		n = -n;
	}
	SerialPrintU32(n);

}

void SerialPrintlnS32(int32_t n)
{
	if(n < 0)
	{
		SerialPrintChar('-');
		n = -n;
	}
	SerialPrintlnU32(n);
}


void SerialPrintU16(uint16_t n)
{
	SerialPrintU32(n);
}

void SerialPrintlnU16(uint16_t n)
{
	SerialPrintlnU32(n);
}

void SerialPrintS16(int16_t n)
{
	SerialPrintS32(n);
}

void SerialPrintlnS16(int16_t n)
{
	SerialPrintlnS32(n);
}

void SerialPrintU8(uint8_t n)
{
	SerialPrintU32(n);
}

void SerialPrintS8(int8_t n)
{
	SerialPrintS32(n);
}


void SerialPrintlnU8(uint8_t n)
{
	SerialPrintlnU32(n);
}

void SerialPrintlnS8(int8_t n)
{
	SerialPrintlnS8(n);
}