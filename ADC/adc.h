#ifndef _AVR_ADC_H
#define _AVR_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef enum adc_ref_t
{
    AREF    = 0<<REFS0,
    AVCC    = 1<<REFS0,
    BANDGAP = 3<<REFS0
}adc_ref_t;

typedef enum adc_trig_source_t
{
    FREE_RUNNING = 0b000,
    TIMER1_CMPB  = 0b101
}adc_trig_source_t;


void adcBegin(adc_ref_t ref);
void adcAttachInterrrupt(void (*adc_isr));
void adcDetachInterrupt();
void adcSetChannel(uint8_t channel);
void adcSetAutoTriggerSource(adc_trig_source_t trigSource);
void adcStartConversion(uint8_t channel);

uint16_t adcRead(uint8_t channel);
float adcReadAverage(uint8_t channel, uint8_t sample);
float adcReadAvcc();



#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*AVR+ADC*/
