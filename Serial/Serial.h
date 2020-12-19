#ifndef _SERIAL_H_
#define _SERIAL_H_

#ifdef __cplusplus
extern "C" {
#endif


void SerialBegin(uint32_t baud);
void SerialPrintChar(unsigned char c);
void SerialPrint(char *str)
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