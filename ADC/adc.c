#include "adc.h"

void (*_isrCb)() = NULL;

ISR(ADC_vect)
{
  _isrCb();
}

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

void adcAttachInterrrupt(void(*adc_isr))
{
    _isrCb = adc_isr;
     ADCSRA |= ((1 << ADIE)| (1 << ADEN));  //ADC Conversion complete interrupt enable
     sei(); //enable global interrupt
}

void adcDetachInterrupt()
{
     ADCSRA &= ~((1 << ADEN) | (1 << ADIE));
}

void adcSetChannel(uint8_t channel)
{
    ADMUX = (ADMUX & 0b11110000) | (channel);
}

void adcStartConversion(uint8_t channel)
{
  setChannel(channel);
  ADCSRA |= (1 << ADSC);  //start conversion
}

uint16_t adcRead(uint8_t channel)
{
  ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	ADCSRA |=1<<ADSC; //Start Conversion
	while(!(ADCSRA&(1<<ADIF))); //Wait until conversion completes
	ADCSRA|= 1<<ADIF; //ADIF must be cleared(1) to trigger a new conversion next time
	return ADCW; //return ADC value  
}
float adcReadAverage(uint8_t channel, uint8_t sample)
{
    uint32_t adcSum = 0; 
	for(byte i = 0; i< sample; i++)
	{
		adcSum += read(channel);
	}

	float result = (float)adcSum/N;
	return result;
}
float adcReadAvcc()
{
    float avcc = readAverage(0b1110,50);
	avcc = (1024.0*1.1)/avcc;
	return avcc;
}