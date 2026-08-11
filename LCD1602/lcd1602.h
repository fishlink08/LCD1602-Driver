#ifndef LCD1602_H
#define LCD1602_H

typedef unsigned char uint8_t;

/*
    LCD_PIN Struct

    @param
    PORT Port of the Pin

    @param
    DDR Data Direction Register of the Pin

    @param
    bit Bit of the Pin
*/
typedef struct 
{
    volatile uint8_t* PORT;
    volatile uint8_t* DDR;
    uint8_t bit;
} LCD_PIN;

/*
    LCD1602 Struct

    @param
    rs Register Select Pin

    @param
    e Enable Pin

    @param
    DB4 Data Bus Pin 4

    @param
    DB5 Data Bus Pin 5

    @param
    DB6 Data Bus Pin 6

    @param
    DB7 Data Bus Pin 7
*/
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

/*
    Write data to LCD1602 Module

    @param
    LCDREF Reference of LCD1602 Struct

    @param
    DATA Data to be written to the LCD
*/
void WRITE_LCD1602(LCD1602* LCDREF, uint8_t DATA);

/*
    Clear the LCD1602 Display

    @param
    LCDREF Reference of LCD1602 Struct
*/
void CLEAR_DISPLAY_LCD1602(LCD1602* LCDREF);

/*
    Shift the Cursor or Display

    @param
    LCDREF Reference of LCD1602 Struct

    @param
    SHIFT_TYPE 0 = Cursor Shift, 1 = Display Shift

    @param
    SHIFT_DIRECTION 0 = Left, 1 = Right
*/
void CURSOR_SHIFT(LCD1602* LCDREF, uint8_t SHIFT_TYPE, uint8_t SHIFT_DIRECTION);

/*
    Return the Cursor to Home Position

    @param
    LCDREF Reference of LCD1602 Struct
*/
void CURSOR_RETURN(LCD1602* LCDREF);

#endif //LCD1602 Driver for ATmega328p 