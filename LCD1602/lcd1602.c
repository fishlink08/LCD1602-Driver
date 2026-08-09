#include "lcd1602.h"
#include <inttypes.h>

#define F_CPU 16000000UL

#include <util/delay.h>

void INIT_LCD1602(LCD1602* LCDREF) // INITIALIZE LCD1602 MODULE
{
    *(LCDREF->e.DDR) |= (1 << LCDREF->e.bit);
    *(LCDREF->rs.DDR) |= (1 << LCDREF->rs.bit);
    *(LCDREF->DB4.DDR) |= (1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.DDR) |= (1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.DDR) |= (1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.DDR) |= (1 << LCDREF->DB7.bit);

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

    // Now in 4 bit inference mode btw
    // Function SET (sets up fonts and used rows, and size format)
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


    // Display OFF

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


    // Display Clear

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

    // Display ON

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

void WRITE_LCD1602(LCD1602* LCDREF, uint8_t DATA) // WRITE TO LCD1602
{
    *(LCDREF->rs.PORT) |= (1 << LCDREF->rs.bit); // WRITE MODE
    

    uint8_t HIGH = (DATA >> 4);
    uint8_t LOW = (DATA & 0x0F);
    
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

void SET_CONFIG(LCD1602* LCDREF, uint8_t FONT, uint8_t ROWS)
{
    *(LCDREF->rs.PORT) &= ~(1 << LCDREF->rs.bit);

    *(LCDREF->DB4.PORT) &= ~(1 << LCDREF->DB4.bit);
    *(LCDREF->DB5.PORT) |= (1 << LCDREF->DB5.bit);
    *(LCDREF->DB6.PORT) &= ~(1 << LCDREF->DB6.bit);
    *(LCDREF->DB7.PORT) &= ~(1 << LCDREF->DB7.bit);

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 

    *(LCDREF->DB5.PORT) &= ~(1 << LCDREF->DB5.bit);

    if (FONT == 1)
    {
        *(LCDREF->DB6.PORT) |= (1 << LCDREF->DB6.bit);
    }

    if (ROWS == 2)
    {
        *(LCDREF->DB7.PORT) |= (1 << LCDREF->DB7.bit);
    }

    *(LCDREF->e.PORT) |= (1 << LCDREF->e.bit); 
    _delay_us(1);
    *(LCDREF->e.PORT) &= ~(1 << LCDREF->e.bit); 
    
    _delay_us(50);

}