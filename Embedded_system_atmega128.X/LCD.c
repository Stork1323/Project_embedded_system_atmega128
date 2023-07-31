/*
 * File:   LCD.c
 * Author: HP
 *
 * Created on July 10, 2023, 12:12 AM
 */


#include <xc.h>
#include "LCD.h"
#include <util/delay.h>
#include <stddef.h>

void LCD_init(){
    DDRG = (1<<LCD_EN);
    LCD_INS = 0x38; LCD_EN_H; _delay_us(1); LCD_EN_L; _delay_us(1);
    _delay_us(200);
    LCD_INS = 0x0C; LCD_EN_H; _delay_us(1); LCD_EN_L; _delay_us(1);
    _delay_us(200);
    LCD_INS = 0x06; LCD_EN_H; _delay_us(1); LCD_EN_L; _delay_us(1);
    _delay_us(200);
    LCD_INS = 0x01; LCD_EN_H; _delay_us(1); LCD_EN_L; _delay_us(1); // clear LCD
    _delay_ms(20);
}
void LCD_clear(){
     LCD_INS = 0x01; LCD_EN_H; _delay_us(1); LCD_EN_L; _delay_us(1); // clear LCD
    _delay_ms(20);
}
void LCD_print(const char *str, unsigned char line, unsigned char col){
    unsigned char add;
    switch (line){
        case 0: add = 0x80; break;
        case 1: add = 0xC0; break;
        case 2: add = 0x94; break;
        case 3: add = 0xD4; break;
    }
    LCD_INS = add + col; LCD_EN_H; _delay_us(1); LCD_EN_L; _delay_us(50);
    while(*str != NULL){
        LCD_DATA = *str++; LCD_EN_H; _delay_us(1); LCD_EN_L; _delay_us(10);
    }
}