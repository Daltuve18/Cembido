/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF1718
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB             :  MPLAB X 5.45

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "pin_manager.h"
#include "mcc.h"
#include "../functions.h"
#include "../menu.h"
#include "../naves.h"



void (*IOCAF0_InterruptHandler)(void);
void (*IOCAF1_InterruptHandler)(void);
void (*IOCAF2_InterruptHandler)(void);
void (*IOCAF3_InterruptHandler)(void);
void (*IOCAF4_InterruptHandler)(void);
void (*IOCAF5_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x08;
    TRISA = 0xFF;
    TRISB = 0x00;
    TRISC = 0xFF;

    /**
    ANSELx registers
    */
    ANSELC = 0xFC;
    ANSELB = 0x00;
    ANSELA = 0x00;

    /**
    WPUx registers
    */
    WPUE = 0x08;
    WPUB = 0x00;
    WPUA = 0x3F;
    WPUC = 0x00;
    OPTION_REGbits.nWPUEN = 0;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLE = 0x08;


    /**
    IOCx registers 
    */


    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN0 = 1;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN1 = 1;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN2 = 1;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN3 = 1;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN4 = 1;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN5 = 1;
    //interrupt on change for group IOCAP - positive




    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCAF0_SetInterruptHandler(IOCAF0_DefaultInterruptHandler);
    IOCAF1_SetInterruptHandler(IOCAF1_DefaultInterruptHandler);
    IOCAF2_SetInterruptHandler(IOCAF2_DefaultInterruptHandler);
    IOCAF3_SetInterruptHandler(IOCAF3_DefaultInterruptHandler);
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCAF0
    if(IOCAFbits.IOCAF0 == 1)
    {
        IOCAF0_ISR();
    }	
	// interrupt on change for pin IOCAF1
    if(IOCAFbits.IOCAF1 == 1)
    {
        IOCAF1_ISR();  
    }	
	// interrupt on change for pin IOCAF2
    if(IOCAFbits.IOCAF2 == 1)
    {
        IOCAF2_ISR();  
    }	
	// interrupt on change for pin IOCAF3
    if(IOCAFbits.IOCAF3 == 1)
    {
        IOCAF3_ISR();  
    }	
	// interrupt on change for pin IOCAF4
    if(IOCAFbits.IOCAF4 == 1)
    {
        IOCAF4_ISR();  
    }	
	// interrupt on change for pin IOCAF5
    if(IOCAFbits.IOCAF5 == 1)
    {
        IOCAF5_ISR();  
    }	
}

/**
   IOCAF0 Interrupt Service Routine
*/
void IOCAF0_ISR(void) {

    // Add custom IOCAF0 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF0_InterruptHandler)
    {
        IOCAF0_InterruptHandler();
    }
    if (inGame){
    switch (mainState){
        case 1:
            mainState  = 0;
            printMenu();
        break;
        case 2:
            mainState  = 1;
            printMenu();
        break;
        case 3:
            mainState  = 2;
            printMenu();
        break;
        default:
            break;
    }
    }else{
        switch (mainState){
        case 1:
            mainState  = 0;
            printMenu();
        break;
        default:
            break;
    }
    }
    
    
    IOCAFbits.IOCAF0 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF0 at application runtime
*/
void IOCAF0_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF0_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF0
*/
void IOCAF0_DefaultInterruptHandler(void){
    // add your IOCAF0 interrupt custom code
    // or set custom function using IOCAF0_SetInterruptHandler()
}

/**
   IOCAF1 Interrupt Service Routine
*/
void IOCAF1_ISR(void) {

    // Add custom IOCAF1 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF1_InterruptHandler)
    {
        IOCAF1_InterruptHandler();
    }
    
    if (inGame){
    switch (mainState){
        case 0:
            mainState  = 1;
            printMenu();
        break;
        case 1:
            mainState  = 2;
            printMenu();
        break;
        case 2:
            mainState  = 3;
            printMenu();
        break;
        default:
            break;
    }
    }else{
        switch (mainState){
        case 0:
            mainState  = 1;
            printMenu();
        break;
        default:
            break;
    }
    }
    IOCAFbits.IOCAF1 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF1 at application runtime
*/
void IOCAF1_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF1
*/
void IOCAF1_DefaultInterruptHandler(void){
    // add your IOCAF1 interrupt custom code
    // or set custom function using IOCAF1_SetInterruptHandler()
}

/**
   IOCAF2 Interrupt Service Routine
*/
void IOCAF2_ISR(void) {

    // Add custom IOCAF2 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF2_InterruptHandler)
    {
        IOCAF2_InterruptHandler();
    }
    if (inGame){
        bool hit;
        switch (mainState){
        case 0: // atacar
            cleanMenu();
            hit=attack(false,0);
            if(!hit){
                failScreen();
                nextTurn(0);
                printMenu();
                break;
            }
            if(health2 == 0){
                winScreen(0);
                break;
            }
            nextTurn(0);
            printMenu();
        break;
        case 1: // especial
            if (special1CD == 0){
                cleanMenu();
                hit=attack(true,0);
                if(!hit){
                    failScreen();
                    nextTurn(0);
                    printMenu();
                    break;
                }
                if(health2 == 0){
                    winScreen(0);
                    break;
                }
                special1CD=4;
                nextTurn(0);
            }else{
                cooldownScreen();
            }
            printMenu();
        break;
        case 2: // reparar
            if (fix1CD == 0){
                fix(0);
                fix1CD=3;
                nextTurn(0);
            }else{
                cooldownScreen();
            }
            printMenu();
        break;
        case 3: // escudo
            if (shield1CD ==0){
                fixShield(0);
                shield1CD=3;
                nextTurn(0);
            }else{
                cooldownScreen();
            }
            printMenu();
        break;
        default:
            break;
        }
    }else{
        switch (mainState){
        case 0:
            ship1 = 0;
            mainState  = 2;
            disableButton(false);
            enableButton(true);
            printMenu();
        break;
        case 1:
            ship1 = 1;
            mainState  = 2;
            disableButton(false);
            enableButton(true);
            printMenu();
        break;
        default:
            break;
    }
    }
    IOCAFbits.IOCAF2 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF2 at application runtime
*/
void IOCAF2_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF2
*/
void IOCAF2_DefaultInterruptHandler(void){
    // add your IOCAF2 interrupt custom code
    // or set custom function using IOCAF2_SetInterruptHandler()
}

/**
   IOCAF3 Interrupt Service Routine
*/
void IOCAF3_ISR(void) {

    // Add custom IOCAF3 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF3_InterruptHandler)
    {
        IOCAF3_InterruptHandler();
    }
     if (inGame){
        switch (mainState){
            case 5:
                mainState  = 4;
                printMenu();
            break;
            case 6:
                mainState  = 5;
                printMenu();
            break;
            case 7:
                mainState  = 6;
                printMenu();
            break;
            default:
                break;
        }
    }else{
        switch (mainState){
        case 3:
            mainState  = 2;
            printMenu();
        break;
        default:
            break;
    }
    }
    IOCAFbits.IOCAF3 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF3 at application runtime
*/
void IOCAF3_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF3_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF3
*/
void IOCAF3_DefaultInterruptHandler(void){
    // add your IOCAF3 interrupt custom code
    // or set custom function using IOCAF3_SetInterruptHandler()
}

/**
   IOCAF4 Interrupt Service Routine
*/
void IOCAF4_ISR(void) {

    // Add custom IOCAF4 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF4_InterruptHandler)
    {
        IOCAF4_InterruptHandler();
    }
     if (inGame){
        switch (mainState){
            case 4:
                mainState  = 5;
                printMenu();
            break;
            case 5:
                mainState  = 6;
                printMenu();
            break;
            case 6:
                mainState  = 7;
                printMenu();
            break;
            default:
                break;
        }
    }else{
        switch (mainState){
        case 2:
            mainState  = 3;
            printMenu();
        break;
        default:
            break;
    }
    }
    IOCAFbits.IOCAF4 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF4 at application runtime
*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF4_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF4
*/
void IOCAF4_DefaultInterruptHandler(void){
    // add your IOCAF4 interrupt custom code
    // or set custom function using IOCAF4_SetInterruptHandler()
}

/**
   IOCAF5 Interrupt Service Routine
*/
void IOCAF5_ISR(void) {

    // Add custom IOCAF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF5_InterruptHandler)
    {
        IOCAF5_InterruptHandler();
    }
    if (inGame){
        bool hit;
        switch (mainState){
        case 4: // atacar
            cleanMenu();
            hit=attack(false,1);
            if(!hit){
                failScreen();
                nextTurn(1);
                printMenu();
                break;
            }
            if(health1 == 0){
                winScreen(1);
                break;
            }
            nextTurn(1);
            printMenu();
        break;
        case 5: // especial
            if (special2CD == 0){
                cleanMenu();
                hit=attack(true,1);
                if(!hit){
                    failScreen();
                    nextTurn(1);
                    printMenu();
                    break;
                }
                if(health1 == 0){
                    winScreen(1);
                    break;
                }
                special2CD=4;
                nextTurn(1);
            }else{
                cooldownScreen();
            }
            printMenu();
        break;
        case 6: // reparar
            if (fix2CD == 0){
                fix(1);
                fix2CD=3;
                nextTurn(1);
            }else{
                cooldownScreen();
            }
            printMenu();
        break;
        case 7: // escudo
            if (shield2CD ==0){
                fixShield(1);
                shield2CD=3;
                nextTurn(1);
            }else{
                cooldownScreen();
            }
            printMenu();
        break;
        default:
            break;
    }
    }else{
        switch (mainState){
        case 2:
            ship2 = 0;
            disableButton(true);
            enableButton(false);
            startFight();
        break;
        case 3:
            ship2 = 1;
            disableButton(true);
            enableButton(false);
            startFight();
        break;
        default:
            break;
    }
    }
    IOCAFbits.IOCAF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF5 at application runtime
*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF5_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF5
*/
void IOCAF5_DefaultInterruptHandler(void){
    // add your IOCAF5 interrupt custom code
    // or set custom function using IOCAF5_SetInterruptHandler()
}

/**
 End of File
*/