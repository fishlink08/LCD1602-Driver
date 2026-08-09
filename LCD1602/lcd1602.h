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


/*
    Initialize LCD1602 Module

    @param
    LCDREF Reference of LCD1602 Struct
*/
void INIT_LCD1602(LCD1602* LCDREF);

/*
    Set Configs of LCD1602 Module

    @param
    LCDREF Reference of LCD1602 Struct

    @param
    FONT 0 = 5x7 Style, 1 = 5x10

    @param
    ROWS 1 = 1 Row Used, 2 = 2 Rows Used 
*/
void SET_CONFIG(LCD1602* LCDREF, uint8_t FONT, uint8_t ROWS);

void WRITE_LCD1602(LCD1602* LCDREF, uint8_t data);
void CLEAR_DISPLAY_LCD1602(LCD1602* LCDREF);

#endif //LCD1602 Driver for ATmega328p 