/*
 * File:   main.c
 * Author: HP
 *
 * Created on July 9, 2023, 4:11 PM
 */


#include <xc.h>
#include <util/delay.h>
#include "system_def.h"
#include "LED.h"
#include "seven_segment_led.h"
#include "relay.h"
#include "dc_motor.h"
#include "button.h"
#include "LCD.h"
#include <stddef.h>
#include "menu.h"


unsigned long led_value = 0x55555555;
unsigned int value = 1234;




void main(void) {
    
    MCUCR |= (1<<SRE); // enable external memory
    // Single LED
    LED0 = led_value & 0xff;
    LED1 = led_value>>8 & 0xff;
    LED2 = led_value>>16 & 0xff;
    LED3 = led_value>>24 & 0xff;
    
    // 7 segment LED
    display_7seg(value);
    
    // control relay
    
    relay.setAllRelay = 0x55;
    RELAY_ACTIVATION;
    
    // control motor
    
    motor.motor_1 = FORWARD; // motor 1 is in left side
    motor.motor_2 = REWARD;
    MOTOR_ACTIVATION;
    
    // LCD
    
    LCD_init();
    LCD_print("HELLO", 0, 8);
    LCD_print("I learning" ,1 , 5); 
    LCD_print("Embedded system", 3, 3);
    _delay_ms(1000);
    
    // menu
    
    unsigned char select = 1;
    LCD_clear();
    
    Menu *menu;
    menu = &Main_menu;
    display_menu(menu, select);
    
    while(1){
        READ_BUTTON;
        if(!button.DOWN){
            while(!button.DOWN) READ_BUTTON;
            
            select = (select == 3) ? 1 : select + 1;
            LCD_clear();
        display_menu(menu, select);
        }
        if(!button.UP){
            while(!button.UP) READ_BUTTON;
            
            select = (select == 1) ? 3 : select - 1;
            LCD_clear();
        display_menu(menu, select);
        }
        if (!button.RIGHT){
            while(!button.RIGHT) READ_BUTTON;
            switch (select){
                case 1: menu = (menu->Menu_list1 != NULL) ? menu->Menu_list1 : menu; break;
                case 2: menu = (menu->Menu_list2 != NULL) ? menu->Menu_list2 : menu; break;
                case 3: menu = (menu->Menu_list3 != NULL) ? menu->Menu_list3 : menu; break;
            }
            LCD_clear();
        display_menu(menu, select);
        }
        if (!button.LEFT){
            while(!button.LEFT) READ_BUTTON;
            menu = (menu->pre != NULL) ? menu->pre : menu;
            LCD_clear();
        display_menu(menu, select);
        }
        if (!button.CHOOSE){
            while(!button.CHOOSE) READ_BUTTON;
            switch (select){
                case 1:
                    if (menu->device_on != NULL){
                        menu->device_on(menu->MenuID, ON);
                    }
                    break;
                case 2:
                    if (menu->device_off != NULL){
                        menu->device_off(menu->MenuID, OFF);
                    }
                    break;
            }
            LCD_clear();
        display_menu(menu, select);
        }
        //_delay_ms(100);
        
        
    }
    
    
    // button
    
    // 7 segment LED scanning
//    while(1){
//        display_scan_7seg(value);
//    }
    
    
    return;
}
