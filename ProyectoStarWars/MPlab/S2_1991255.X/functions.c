/***
-----------------------------------------------------------------------------
PG7233
-----------------------------------------------------------------------------
Package name  : functions.c
Description   : Rising Force Fighters
Authors       : David Altuve & Leonardo Cabrera
Email         : 19-91255@usb.ve / 20-91371@usb.ve
Version       : 01.00
Revision      : 00
Date          : 7/18/2021
-----------------------------------------------------------------------------

Available functions:

CreateCustomCharacter -- Stores a custom character into the LCD's CGRAM

***/

/* Standard libraries */

#include <string.h>
#include <stdio.h>
#include "lcd.h"

/*Global Variables*/
bool player;

void createCustomCharacter (unsigned char *Pattern, const char Location)

    /***
        Stores a custom character into the LCD's CGRAM

        Arguments: 

        *Pattern    -- Direction where the pattern is stored
        Location    -- CGRAM direction where the pattern will be stored in the LCD

        Return values: None

    ***/

    {

    int i=0; 
    LCDPutCmd (0x40+(Location*8));     //Send the Address of CGRAM
    
    for (i=0; i<8; i++)
    
        LCDPutChar (Pattern [ i ] );         //Pass the bytes of pattern on LCD

    }

void idleScreen (void)

    /***

    Prints the idle screen with both ships

    Arguments: None

    Return values: None

    ***/

    {
        LCDClear();
        LCDGoto(0,0);
        LCDPutChar(1);
        LCDGoto(15,0);
        LCDPutChar(0);
    }

void basicShoot(int direction)
    /***

    Shoot the basic animation in a specific direction

    Arguments: 

        direction: Side to print the shoot animation

    Return values: None

    ***/

    {
        
        if (direction == 0)
        {
            int j = 1;

            while(j<=14)

            {
                LCDGoto(j,0);
                LCDPutChar(2);
                __delay_ms(125);
                j++;
                LCDGoto(j-1,0);
                LCDPutStr(" ");
            };
        }
        
        else
        {
            int j=14;

            while(j>=1)

            {
                LCDGoto(j,0);
                LCDPutChar(2);
                __delay_ms(125);
                j--;
                LCDGoto(j+1,0);
                LCDPutStr(" ");
            };
        }
        

    }

void disableButton (bool player)

    /***

    Prints the idle screen with both ships

    Arguments: None

    Return values: None

    ***/
    {
    if (player == true)
        
        {
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN3 = 0;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN4 = 0;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN5 = 0;
        }
    else
        
        {
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN0 = 0;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN1 = 0;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN2 = 0;
        }
    
    }

void enableButton (bool player)

    /***

    Prints the idle screen with both ships

    Arguments: None

    Return values: None

    ***/
    {
    if (player == true)
        
        {
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN3 = 1;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN4 = 1;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN5 = 1;
        }
    else
        
        {
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN0 = 1;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN1 = 1;
        //interrupt on change for group IOCAN - negative
        IOCANbits.IOCAN2 = 1;
        }
    
    }