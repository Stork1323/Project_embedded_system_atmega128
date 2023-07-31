/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */





/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stddef.h>
#include "LCD.h"
#include "relay.h"
#include "LED.h"
#include "dc_motor.h"
#include "system_def.h"

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

#define ON 1
#define OFF 0

#define RELAY_DEVICE 0
#define MOTOR1_DEVICE 1
#define MOTOR2_DEVICE 2
#define LED_DEVICE 3

void Activate_device(char device, char status){
    switch (device){
        case RELAY_DEVICE:
            if (status){
                relay.setAllRelay = 0xff;
            }
            else {
                relay.setAllRelay = 0x00;
            }
            RELAY_ACTIVATION;
            break;
        case MOTOR1_DEVICE:
            motor.motor_1 = (status) ? REWARD : STOP;
            MOTOR_ACTIVATION;
            break;
        case MOTOR2_DEVICE:
            motor.motor_2 = (status) ? REWARD : STOP;
            MOTOR_ACTIVATION;
            break;    
        case LED_DEVICE:
            if (status){
                LED0 = 0xff;
                LED1 = 0xff;
                LED2 = 0xff;
                LED3 = 0xff;
            }
            else {
                LED0 = 0x00;
                LED1 = 0x00;
                LED2 = 0x00;
                LED3 = 0x00;
            }
            
            break;
            
    }
}


typedef struct Linker{
    char MenuID;
    struct Linker *pre;
    char title[20];
    char list1[20];
    struct Linker *Menu_list1; void (*device_on) (char, char);
    char list2[20];
    struct Linker *Menu_list2; void (*device_off) (char, char);
    char list3[20];
    struct Linker *Menu_list3;
} Menu;
Menu Main_menu, Sensor_menu, Actuator_menu, Setting_menu, Temperature_menu, Humidity_menu;
Menu Relay_menu, Motor_menu, Led_menu, Motor1_set_menu, Motor2_set_menu;

Menu Main_menu = {
    NULL,
    NULL,
    "Main menu",
    "Sensor",
    &Sensor_menu, NULL,
    "Actuator",
    &Actuator_menu,NULL,
    "Setting",
    &Setting_menu
};
///--------------------------------
Menu Sensor_menu = {
    NULL,
    &Main_menu,
    "Sensors",
    "Temperature",
    &Temperature_menu,NULL,
    "Humidity",
    &Humidity_menu,NULL,
    "Date&Time",
    NULL
};
Menu Temperature_menu = {
    NULL,
    &Sensor_menu,
    "Temperature",
    "ON",
    NULL,NULL,
    "OFF",
    NULL,NULL,
    "Setup",
    NULL
};
Menu Humidity_menu = {
    NULL,
    &Sensor_menu,
    "Humidity",
    "ON",
    NULL,NULL,
    "OFF",
    NULL,NULL,
    "Setup",
    NULL
};
//----------------------------------
Menu Actuator_menu = {
    NULL,
    &Main_menu,
    "Actuators",
    "Relays",
    &Relay_menu,NULL,
    "Motors",
    &Motor_menu,NULL,
    "Leds",
    &Led_menu
};
Menu Relay_menu = {
    RELAY_DEVICE,
    &Actuator_menu,
    "Relays",
    "ON",
    NULL,&Activate_device,
    "OFF",
    NULL,&Activate_device,
    NULL,
    NULL
};
Menu Motor_menu = {
    NULL,
    &Actuator_menu,
    "Motors",
    "Motor 1",
    &Motor1_set_menu,NULL,
    "Motor 2",
    &Motor2_set_menu,NULL,
    NULL,
    NULL
};
Menu Motor1_set_menu = {
    MOTOR1_DEVICE,
    &Motor_menu,
    "Motor 1 ",
    "ON",
    NULL,&Activate_device,
    "OFF",
    NULL,&Activate_device,
    NULL,
    NULL
};
Menu Motor2_set_menu = {
    MOTOR2_DEVICE,
    &Motor_menu,
    "Motor 2 ",
    "ON",
    NULL,&Activate_device,
    "OFF",
    NULL,&Activate_device,
    NULL,
    NULL
};
Menu Led_menu = {
    LED_DEVICE,
    &Actuator_menu,
    "Led",
    "ON",
    NULL,&Activate_device,
    "OFF",
    NULL,&Activate_device,
    NULL,
    NULL
};
//-------------------------------
Menu Setting_menu = {
    NULL,
    &Main_menu,
    "Setting",
    "Date",
    NULL,NULL,
    "Speed",
    NULL,NULL,
    "Channel",
    NULL
};
//-------------------------------

void display_menu(Menu *menu, unsigned char select){
    LCD_print(menu->title, 0, 6);
    LCD_print(menu->list1, 1, 2);
    LCD_print(menu->list2, 2, 2);
    LCD_print(menu->list3, 3, 2);
    LCD_print(">", select, 0);
}
