#include "Serial.h"
#include <stdint.h>

/*************Hardware dependent Functions*********/
SerialBegin(uint32_t baud)
{
// Set baud rate
#if defined(F_CPU)
    uint16_t ubrr = F_CPU / 16 / baud - 1;
#else
#error "Please put F_CPU before #include \"Serial.h\""
#endif

    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)ubrr;
    // Set frame format | 8 bit 1 stop bit
    UCSR0C = (1 << URSEL) | (3 << UCSZ0);
    // Enabble TX RX
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}

void SerialPrintChar(unsigned char c)
{
    // Wait for empty transmit buffer
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

SerialPrint(char *str)
{
    while (*str)
    {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = *str;
        str++;
    }
}

/************Hardware Independent Functions************/


SerialPrintU32(uint32_t n)
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

SerialPrintlnU32(int32_t n)
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

SerialPrintS32(int32_t n)
{
    if(n < 0)
    {
        SerialPrintChar('-')
        n = -n;
    }
    SerialPrintU32(n);

}

SerialPrintlnS32(int32_t n)
{
    if(n < 0)
    {
        SerialPrintChar('-')
        n = -n;
    }
    SerialPrintlnU32(n);
}


SerialPrintU16(uint16_t n)
{
    SerialPrintU32(n);
}

SerialPrintlnU16(uint16_t n)
{
    SerialPrintlnU32(n);
}

SerialPrintS16(int16_t n)
{
    SerialPrintS32(n);
}

SerialPrintlnS16(int16_t n)
{
    SerialPrintlnS32(n);
}

SerialPrintU8(uint8_t n)
{
    SerialPrintU32(n);
}

SerialPrintS8(int8_t n)
{
    SerialPrintS32(n);
}


SerialPrintlnU8(uint8_t n)
{
    SerialPrintlnU32(n);
}

SerialPrintlnS8(int8_t n)
{
    SerialPrintlnS8(n);
}