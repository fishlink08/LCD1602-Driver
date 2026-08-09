#include "lcd1602.h"
#include <inttypes.h>

#define F_CPU 16000000UL

#include <util/delay.h>

void INIT_LCD1602(LCD1602* LCDREF) // INITIALIZE LCD1602 MODULE
{
    _delay_ms(15);

    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit);
    *(LCDREF->rs.PORT) &= ~(1 << LCDREF->rs.bit);

    *(LCDREF->DB4.PORT) |= (1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) |= (1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); // first pulse
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit);
    _delay_ms(4.1);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); // second pulse
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit);
    _delay_us(150);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); // third pulse
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit);
     _delay_us(100);

    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit); // SET to 4 bit Inference mode
    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 
    _delay_us(50);


    // Second Function SET (sets up fonts and used rows for exampl)
    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) |= (1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 


    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) |= (1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 
    _delay_us(50);


    // Setting up

    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 


    *(LCDREF->DB7.PORT) |= (1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 
    _delay_us(50);


    // 2nd Setting up

    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 


    *(LCDREF->DB4.PORT) |= (1 << LCDREF->DB4.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 
    _delay_ms(2);

    // Entry mode Set

    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 


    *(LCDREF->DB5.PORT) |= (1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) |= (1 << LCDREF->DB6.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 
    _delay_us(50);

    // INIT FINISHED

    // turn display on lol

    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 


    *(LCDREF->DB6.PORT) |= (1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) |= (1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 
    _delay_us(50);
}

void WRITE_LCD1602(LCD1602* LCDREF, uint8_t data) // WRITE TO LCD1602
{
    *(LCDREF->rs.PORT) |= (1 << LCDREF->rs.bit); // WRITE MODE
    

    uint8_t HIGH = (data >> 4);
    uint8_t LOW = (data & 0x0F);
    
    // Data
    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    if (HIGH & (1 << 0))
    {
        *(LCDREF->DB4.PORT) |= (1 << LCDREF->DB4.bit); 
    }

    if (HIGH & (1 << 1))
    {
        *(LCDREF->DB5.PORT) |= (1 << LCDREF->DB5.bit); 
    } 
    
    if (HIGH & (1 << 2))
    {
        *(LCDREF->DB6.PORT) |= (1 << LCDREF->DB6.bit); 
    } 

    if (HIGH & (1 << 3))
    {
        *(LCDREF->DB7.PORT) |= (1 << LCDREF->DB7.bit); 
    } 

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 


    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    if (LOW & (1 << 0))
    {
        *(LCDREF->DB4.PORT) |= (1 << LCDREF->DB4.bit); 
    }

    if (LOW & (1 << 1))
    {
        *(LCDREF->DB5.PORT) |= (1 << LCDREF->DB5.bit); 
    } 
    
    if (LOW & (1 << 2))
    {
        *(LCDREF->DB6.PORT) |= (1 << LCDREF->DB6.bit); 
    } 

    if (LOW & (1 << 3))
    {
        *(LCDREF->DB7.PORT) |= (1 << LCDREF->DB7.bit); 
    } 

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 

    _delay_us(50);
}


void CLEAR_DISPLAY_LCD1602(LCD1602* LCDREF) // CLEAR LCD1602 DISPLAY
{
    *(LCDREF->rs.PORT) &= ~(1 << LCDREF->rs.bit);

    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 

    *(LCDREF->DB4.PORT) |= (1 << LCDREF->DB4.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 

    _delay_us(50);
}