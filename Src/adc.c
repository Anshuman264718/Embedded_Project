#include<avr/io.h>
void InitADC()
{
    ADMUX|=(1<<REFS0); // SET Aref =AVcc= +5V
    ADCSRA|=(1<<ADEN)|(7<<ADPS0); //enable ADC and setting prescalar value of 128 fcpu
}
uint16_t ReadADC(uint8_t ch)
        {
          // select channel ch for ADC
          ADMUX&=0xf8;
          ch=ch&0b00000111;
          ADMUX|=ch;
          ADCSRA|=(1<<ADSC); // to start single conversion
          while(!(ADCSRA & (1<<ADIF))); // wait for conversion to complete
          ADCSRA|=(1<<ADIF);
          return(ADC);

        }
