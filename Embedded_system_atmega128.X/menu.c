///*
// * File:   menu.c
// * Author: HP
// *
// * Created on July 10, 2023, 3:18 PM
// */
//
//
//#include <xc.h>
//#include "LED.h"
//#include "dc_motor.h"
//#include "menu.h"
//#include "relay.h"
//
//void Activate_device(char device, char status){
//    switch (device){
//        case RELAY_DEVICE:
//            if (status){
//                relay.setAllRelay = 0xff;
//            }
//            else {
//                relay.setAllRelay = 0x00;
//            }
//            RELAY_ACTIVATION;
//            break;
//        case MOTOR1_DEVICE:
//            motor.motor_1 = (status) ? REWARD : STOP;
//            MOTOR_ACTIVATION;
//            break;
//        case MOTOR2_DEVICE:
//            motor.motor_2 = (status) ? REWARD : STOP;
//            MOTOR_ACTIVATION;
//            break;    
//        case LED_DEVICE:
//            if (status){
//                LED0 = 0xff;
//                LED1 = 0xff;
//                LED2 = 0xff;
//                LED3 = 0xff;
//            }
//            else {
//                LED0 = 0x00;
//                LED1 = 0x00;
//                LED2 = 0x00;
//                LED3 = 0x00;
//            }
//            
//            break;
//            
//    }
//}
