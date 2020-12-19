#include "Serial.h"
#include <stdint.h>


/*************Hardware dependent Functions*********/
SerialBegin(uint32_t baud)
{
    // Set baud rate
    #if defined(F_CPU)
    uint16_t ubrr = F_CPU/16/baud - 1;
    #else
    #error "Please put F_CPU before #include \"Serial.h\""
    #endif
    
    UBRR0H = (uint8_t)(ubrr>>8);
    UBRR0L = (uint8_t)ubrr;
    // Set frame format | 8 bit 1 stop bit
    UCSR0C = (1<<URSEL)|(3<<UCSZ0);
    // Enabble TX RX
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);

}

void printChar(unsigned char c)
{
    // Wait for empty transmit buffer
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = c;
}

/************Hardware Independent Functions************/
SerialPrint(char *str)
{
    
}
