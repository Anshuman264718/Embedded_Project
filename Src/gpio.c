#include<avr/io.h>
void gpio()
{
  //setting direction of ports
  DDRB|=(1<<PB0); // set b0=1 for led
  DDRD&=~(1<<PD0); // clear bit
  DDRD&=~(1<<PD1); // clear bit

  // input for push buttons, pull-up +5V
  PORTD|=(1<<PD0);
  PORTD|=(1<<PD1);

}
