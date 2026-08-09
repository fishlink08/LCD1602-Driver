#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "../LCD1602/lcd1602.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{   

    DDRB |= (1 << PB0);
    DDRD |= (1 << PD7);
    DDRD |= (1 << PD6);
    DDRD |= (1 << PD5);
    DDRD |= (1 << PD4);
    DDRD |= (1 << PD3);

    LCD1602 display = 
    {
        .rs = {&PORTD, &DDRD, PD3},
        .e = {&PORTD, &DDRD, PD4},
        
        .DB4 = {&PORTB, &DDRB, PB0},
        .DB5 = {&PORTD, &DDRD, PD7},
        .DB6 = {&PORTD, &DDRD, PD6},
        .DB7 = {&PORTD, &DDRD, PD5}
    };

    INIT_LCD1602(&display);


    // Writing works!

    WRITE_LCD1602(&display, 'F');
    WRITE_LCD1602(&display, 'A');
    WRITE_LCD1602(&display, 'I');
    WRITE_LCD1602(&display, 'L');
    WRITE_LCD1602(&display, '!'); 
    
    _delay_ms(1000);

    CLEAR_DISPLAY_LCD1602(&display); // works
    while (1)
    {

    }

}