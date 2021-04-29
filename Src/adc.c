
/**
 * @file adc.c
 * @author Archisa Kalyani
 * @brief source file to implement ADC function for temperature sensor
 * @date 2021-04-26
 *
 * @copyright Copyright (c) 2021
 *
 */

#include<avr/io.h>
/** \brief
 function to initialize ADC
 */

void InitADC()
{
    ADMUX|=(1<<REFS0); /** SET Aref =AVcc= +5V*/
    ADCSRA|=(1<<ADEN)|(7<<ADPS0); /**enable ADC and setting prescalar value of 128 fcpu*/
}
/** \brief this function receives the temperature values from the temperature sensor and stores
  output in 2 8-bit ADC register(ADCL AND ADCH)
* \param ch
 * \return ADC to uint16_t
 *
 */

uint16_t ReadADC(uint8_t ch)
        {
          /** select channel ch for ADC*/
          ADMUX&=0xf8;
          ch=ch&0b00000111;
          ADMUX|=ch;
          /** to start single conversion*/
          ADCSRA|=(1<<ADSC);
          /** wait for conversion to complete*/
          while(!(ADCSRA & (1<<ADIF)));
          ADCSRA|=(1<<ADIF);
          return(ADC);

        }

