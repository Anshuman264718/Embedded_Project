#include<avr/io.h>
void pwm()
{
    /**set timers and port*/
    /**16-bit timer*/
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10); /** timer 1A, set compare match and wave generation modes to 1*/
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);/** timer 1B, set wave generation mode to 1 and pracscalar (64 prescalar)*/
    DDRB|=(1<<PB1); /** set direction of pin PB1, timer 1 pin*/
}
