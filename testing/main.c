#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include "../LCD1602/lcd1602.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{   
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

    WRITE_LCD1602(&display, 'T');
    WRITE_LCD1602(&display, 'E');
    WRITE_LCD1602(&display, 'S');
    WRITE_LCD1602(&display, 'T');
    WRITE_LCD1602(&display, '!'); 
    
    _delay_ms(1000);

    //SET_CONFIG(&display, 0, 2); 
    //CURSOR_SHIFT(&display, 0, 1);
    //CURSOR_RETURN(&display);

    CLEAR_DISPLAY_LCD1602(&display); 
    while (1)
    {

    }

}