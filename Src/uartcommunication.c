/**
 * @file uartcommunication.c
 * @author Archisa Kalyani
 * @brief source file for defining uart function
 *
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
 #include<avr/io.h>

 /**
 * @brief function to initialize the UART serial communication
 *
 * @param ubrr_value
 */
void UARTinit(uint16_t ubrr_value){

    // setting Baud rate
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&(0x00ff);
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ00)|(1<<UCSZ01);

    // enballing receiver and transmitter
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}
/**
 * @brief function to read characters coming from other UART port
 *
 * @return char
 */
char UARTreadchar(){

while(!(UCSR0A & (1<<RXC0)))// uart data is not received
    {

}

return UDR0;

}
/**
 * @brief function to write characters to send it to other UART port
 *
 * @param data
 */
void UARTwritecharacter(char data){

while(!(UCSR0A & (1<<UDRE0))) // uart data is not written
    {

}
UDR0 = data;

}




