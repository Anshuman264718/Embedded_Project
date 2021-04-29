/**
 * @file SeatHeatingApp.c
 * @author Archisa Kalyani
 * @brief main source file executing the entire program
 * @date 2021-04-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include<avr/io.h>
#include<util/delay.h>
#define sw1 !(PIND&(1<<PD0)) /** defining macros for pin DO and D1 */
#define sw2 !(PIND&(1<<PD1)) /**and D1 */
#include "gpio.h"
#include "adc.h"
#include "pwm.h"
#include "uartcommunication.h"
int main(void)
{
   gpio(); /**function call for setting ports*/
   UARTinit(103); /**Initialise UART registers*/
   int temp_data;

    while(1)
    {
        if((sw1==1)&(sw2==1)) /**checking input from button sensor*/
        {
            InitADC(); /**function call for initializing ADC*/
          pwm(); /**function call for executing PWM*/

            PORTB|=(1<<PB0); /**led turns on*/
            _delay_ms(200);
            uint16_t temp=ReadADC(0); /**calling channel 0*/
            _delay_ms(200);
            temp_data=PWMoutput(temp);
            UARTwritecharacter(temp_data);

        }
        else
        {
            PORTB&=~(1<<PB0); /** led turns off*/
            OCR1A=0;
            _delay_ms(200);
        }
    }
    return 0;
}
