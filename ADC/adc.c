#include "adc.h"

void (*_isrCb)();

void adcBegin(adc_ref_t ref)
{
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //Prescaler 128.So F_adc = 16MHz/128 = 125KHz
    ADMUX |= (uintr_t)ref;
    ADCSRA |= (1 << ADEN);
}

void adcSetAutoTriggerSource(adc_trig_source_t trigSource)
{
    uint8_t source = (uint8_t)trigSource;
    if (source)
    {
        ADCSRA |= (1 << ADATE); //ADC Auto trigger enable
    }
    ADCSRB &= 0b11111000; //Clearing trigger source bits
    ADCSRB |= source;
}

void adcAttachInterrrupt(void(*adc_isr));
void adcDetachInterrupt();
void adcSetChannel(uint8_t channel);

void adcStartConversion(uint8_t channel);

uint16_t adcRead(uint8_t channel);
float adcReadAverage(uint8_t channel, uint8_t sample);
float adcReadAvcc();