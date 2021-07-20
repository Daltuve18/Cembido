/***
-----------------------------------------------------------------------------
PG7233
-----------------------------------------------------------------------------
Package name  : main
Description   : Rising Force Fighters
Authors       : David Altuve & Leonardo Cabrera
Email         : 19-91255@usb.ve / 20-91371@usb.ve
Version       : 01.00
Revision      : 00
Date          : 7/18/2021
-----------------------------------------------------------------------------

 * This main module executes the routines for the game Rising Force Fighters

***/


/* Standard libraries */

#include <stdio.h> 
#include "lcd.h"
#include "menu.h"

/* Local libraries */

#include "functions.h"

void main() 

{
    
    //System and LCD initialization
    
    SYSTEM_Initialize();
    LCD_Initialize();

    //Sprite creation

    unsigned char Pattern1 [ ] = {0x18,0x10,0x1F,0x1F,0x1F,0x10,0x18,0x00};
    
    unsigned char Pattern2 [ ] = {0x00,0x0A,0x11,0x15,0x15,0x11,0x0A,0x00};
    
    unsigned char Pattern3 [ ] = {0x00,0x00,0x0E,0x1F,0x0E,0x00,0x00,0x00} ;
    
    unsigned char Pattern4 [ ] = {0x00,0x00,0x0A,0x1F,0x1F,0x0E,0x04,0x00} ;

    /*Character storage into LCD's memory*/

    createCustomCharacter(Pattern1,1);
    createCustomCharacter(Pattern2,0);
    createCustomCharacter(Pattern3,2);
    createCustomCharacter(Pattern4,3);

    //LCD PRINTING
    
    //idleScreen();
    printMenu();
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // disable player 2 buttons
    
    disableButton(true);
    
    while (1)
    {

    }
}