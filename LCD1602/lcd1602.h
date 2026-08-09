#ifndef LCD1602_H
#define LCD1602_H

typedef unsigned char uint8_t;

typedef struct 
{
    volatile uint8_t* PORT;
    volatile uint8_t* DDR;
    uint8_t bit;
} LCD_PIN;

typedef struct
{
    LCD_PIN rs;
    LCD_PIN e;

    LCD_PIN DB4;
    LCD_PIN DB5;
    LCD_PIN DB6;
    LCD_PIN DB7;
} LCD1602;


void INIT_LCD1602(LCD1602* LCDREF);

void WRITE_LCD1602(LCD1602* LCDREF, uint8_t data);
void CLEAR_DISPLAY_LCD1602(LCD1602* LCDREF);

#endif //LCD1602 Driver for ATmega328p 