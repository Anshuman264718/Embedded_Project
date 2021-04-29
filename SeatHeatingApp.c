

#include<avr/io.h>
#include<util/delay.h>
#define sw1 !(PIND&(1<<PD0)) /** defining macros for pin DO and D1 */
#define sw2 !(PIND&(1<<PD1)) /**and D1 */


int SeatHeatingApp(void)

{
   gpio(); /**function call for setting ports*/
   InitADC(); /**function call for initializing ADC*/
   pwm(); /**function call for executing PWM*/

    while(1)
    {
        if((sw1==1)&(sw2==1)) /**checking input from button sensor*/
        {
            PORTB|=(1<<PB0); /**led turns on*/
            _delay_ms(200);
        }
        else
        {
            PORTB&=~(1<<PB0); /** led turns off*/
            _delay_ms(200);
        }

       uint16_t temp=ReadADC(0); /**calling channel 0*/
        _delay_ms(200);

        /** the function gives ADC values as input for PWM*/
        OCR1A= ReadADC(0) ;
        _delay_ms(2000);

    }
    return 0;
}
