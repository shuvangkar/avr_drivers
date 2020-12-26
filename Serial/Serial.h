#ifndef _SERIAL_H_
#define _SERIAL_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <avr/io.h>
#include <avr/pgmspace.h>

#include <stdint.h>

#ifndef F_CPU
#warning "F_CPU not defined"
#endif


void SerialBegin(uint32_t baud); // Hardware dependent
void SerialPrintChar(unsigned char c); // Hardware dependent
void SerialPrintF(const char *str); // Hardware dependent


void SerialPrintlnF(const char *str);
void println(void);
void SerialPrint(char *str);
void SerialPrintln(char *str);




void SerialPrintU8(uint8_t n);
void SerialPrintS8(int8_t n);
void SerialPrintU16(uint16_t n);
void SerialPrintS16(int16_t n);
void SerialPrintU32(uint32_t n);
void SerialPrintS32(int32_t n);


void SerialPrintlnU8(uint8_t n);
void SerialPrintlnS8(int8_t n);
void SerialPrintlnU16(uint16_t n);
void SerialPrintlnS16(int16_t n);
void SerialPrintlnU32(uint32_t n);
void SerialPrintlnS32(int32_t n);

void SerialPrintFloat(float n);
void SerialPrintlnFloat(float n);


#ifdef __cplusplus
}
#endif

#endif