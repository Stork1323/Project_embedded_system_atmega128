/*
 * File:   display_7seg.c
 * Author: HP
 *
 * Created on July 9, 2023, 5:25 PM
 */

#include <xc.h>
#include "seven_segment_led.h"
#include "system_def.h"
#include <util/delay.h>

unsigned char code_ca_seg_led[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void display_7seg(unsigned int value){
    Seg_led4 = code_ca_seg_led[value % 10];
    Seg_led3 = code_ca_seg_led[value/10 % 10];
    Seg_led2 = code_ca_seg_led[value/100 % 10];
    Seg_led1 = code_ca_seg_led[value/1000 % 10];
}
void display_scan_7seg(unsigned int value){
    scan_seg = code_ca_seg_led[value % 10];
    select_seg = 0b11110111;
    _delay_ms(50);
    select_seg = 0xff;
  
    scan_seg = code_ca_seg_led[value/10 % 10];
    select_seg = 0b11111011;
    _delay_ms(50);
    select_seg = 0xff;
    
    scan_seg = code_ca_seg_led[value/100 % 10];
    select_seg = 0b11111101;
    _delay_ms(50);
    select_seg = 0xff;
    
    scan_seg = code_ca_seg_led[value/1000 % 10];
    select_seg = 0b11111110;
    _delay_ms(50);
    select_seg = 0xff;
}
