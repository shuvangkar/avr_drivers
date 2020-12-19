#ifndef _SERIAL_H_
#define _SERIAL_H_

#ifdef __cplusplus
extern "C" {
#endif


SerialBegin(uint32_t baud);
void SerialPrintChar(unsigned char c);

 
SerialPrintU8(uint8_t n);
SerialPrintS8(int8_t n);
SerialPrintU16(uint16_t n);
SerialPrintS16(int16_t n);
SerialPrintU32(uint32_t n);
SerialPrintS32(int32_t n);

SerialPrintln(char *str);
SerialPrintlnU8(uint8_t n);
SerialPrintlnS8(int8_t n);
SerialPrintlnU16(uint16_t n);
SerialPrintlnS16(int16_t n);
SerialPrintlnU32(uint32_t n);
SerialPrintlnS32(int32_t n);

SerialPrintFloat(float n);
SerialPrintlnFloat(float n);


#ifdef __cplusplus
}
#endif
#endif