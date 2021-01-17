#ifndef _AVR_ADC_H
#define _AVR_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


void adcBegin();
void adcAttachInterrrupt(void (*adc_isr));
void adcDetachInterrupt();
void adcSetChannel(uint8_t channel);
void adcSetAutoTriggerSource(uint8_t source);
void adcStartConversion(uint8_t channel);




#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*AVR+ADC*/
