/**
 * @file pwm.c
 * @author Archisa Kalyani
 * @brief source file to implement pulse width modulation
 *
 * @date 2021-04-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#include<avr/io.h>
#include<util/delay.h>
void pwm()
{
    /**set timers and port*/
    /**16-bit timer*/
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10); /** timer 1A, set compare match and wave generation modes to 1*/
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);/** timer 1B, set wave generation mode to 1 and pracscalar (64 prescalar)*/
    DDRB|=(1<<PB1); /** set direction of pin PB1, timer 1 pin*/
}
int PWMoutput(uint16_t temp_ADC)
{
   int temperature;

    if((temp_ADC>=0) && (temp_ADC<=209)){

        OCR1A = 205; /**20% of duty cycle*/
        temperature = 20;
        _delay_ms(20);
    }
    else if((temp_ADC>=210) && (temp_ADC<=509)){

        OCR1A = 410; /**40% of duty cycle*/
        temperature = 25;
        _delay_ms(20);
    }
    else if((temp_ADC>=510) && (temp_ADC<=709)){

        OCR1A = 717;/**70% of duty cycle*/
        temperature = 29;
        _delay_ms(20);
    }
    else if((temp_ADC>=710) && (temp_ADC<=1024)){

        OCR1A = 973; /**95% of duty cycle*/
        temperature = 33;
        _delay_ms(20);
    }
    else{
        OCR1A = 0; /** 0% of duty cycle*/
        temperature = 0;
    }
    return temperature;

}

