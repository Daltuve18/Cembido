/***
-----------------------------------------------------------------------------
PG7233
-----------------------------------------------------------------------------
Package name  : naves.c
Description   : Rising Force Fighters
Authors       : David Altuve & Leonardo Cabrera
Email         : 19-91255@usb.ve / 20-91371@usb.ve
Version       : 01.00
Revision      : 00
Date          : 7/18/2021
-----------------------------------------------------------------------------

***/

/*Standard Libraries */

#include <string.h>
#include <stdio.h>
#include "lcd.h"

/*Local Libraries*/

#include "menu.h"
#include "functions.h"
#include "psudoRandom.h"

uint8_t ship1;
uint8_t ship2;

uint8_t health1=4;
uint8_t health2=4;

uint8_t shield1=4;
uint8_t shield2=4;


void printShip()
{
    LCDClear();
    LCDGoto(0,0);
    LCDPutChar(ship1);
    if (ship2 == 1){
        LCDGoto(15,0);
        LCDPutChar(4);
    }else {
        LCDGoto(15,0);
        LCDPutChar(ship2);   
    }   
}


void printHeart(void)

    {
        switch (health1){
            case 0:
                LCDGoto(0, 1);
                LCDPutStr(" ");
            break;
            case 1:
                LCDGoto(0, 1);
                LCDPutStr(" ");
                unsigned char heart11 [ ] = {0x00,0x0A,0x15,0x11,0x11,0x0A,0x04,0x00};
                createCustomCharacter(heart11,5);
                LCDGoto(0, 1);
                LCDPutChar(5);
            break;
            case 2:
                LCDGoto(0, 1);
                LCDPutStr(" ");
                unsigned char heart12 [ ] = {0x00,0x0A,0x1D,0x19,0x19,0x0A,0x04,0x00};
                createCustomCharacter(heart12,5);
                LCDGoto(0, 1);
                LCDPutChar(5);
            break;
            case 3:
                LCDGoto(0, 1);
                LCDPutStr(" ");
                unsigned char heart13 [ ] = {0x00,0x0A,0x1D,0x1D,0x1D,0x0E,0x04,0x00};
                createCustomCharacter(heart13,5);
                LCDGoto(0, 1);
                LCDPutChar(5);
            break;
                case 4:
                LCDGoto(0, 1);
                LCDPutStr(" ");
                LCDGoto(0, 1);
                LCDPutChar(3);
            break;
            default:
                break;
            }
    
        switch (health2)
        {
            case 0:
                LCDGoto(15, 1);
                LCDPutStr(" ");
            break;
            case 1:
                LCDGoto(15, 1);
                LCDPutStr(" ");
                unsigned char heart21 [ ] = {0x00,0x0A,0x15,0x11,0x11,0x0A,0x04,0x00};
                createCustomCharacter(heart21,6);
                LCDGoto(15, 1);
                LCDPutChar(5);
            break;
            case 2:
                LCDGoto(15, 1);
                LCDPutStr(" ");
                unsigned char heart22 [ ] = {0x00,0x0A,0x1D,0x19,0x19,0x0A,0x04,0x00};
                createCustomCharacter(heart22,6);
                LCDGoto(15, 1);
                LCDPutChar(6);
            break;
            case 3:
                LCDGoto(15, 1);
                LCDPutStr(" ");
                unsigned char heart23 [ ] = {0x00,0x0A,0x1D,0x1D,0x1D,0x0E,0x04,0x00};
                createCustomCharacter(heart23,6);
                LCDGoto(15, 1);
                LCDPutChar(6);
            break;
                case 4:
                LCDGoto(15, 1);
                LCDPutStr(" ");
                LCDGoto(15, 1);
                LCDPutChar(3);
            break;
            default:
                break;
            }

    }
    
void printShield(void)

    {
        switch (shield1){
            case 0:
                LCDGoto(1, 1);
                LCDPutStr(" ");
            break;
            case 1:
                LCDGoto(1, 1);
                LCDPutStr(" ");
                unsigned char shield11 [ ] = {0x00,0x1F,0x11,0x11,0x11,0x0A,0x04,0x00};
                createCustomCharacter(shield11,5);
                LCDGoto(0, 1);
                LCDPutChar(5);
            break;
            case 2:
                LCDGoto(1, 1);
                LCDPutStr(" ");
                unsigned char shield12 [ ] = {0x00,0x1F,0x11,0x11,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(shield12,5);
                LCDGoto(0, 1);
                LCDPutChar(5);
            break;
                case 3:
                LCDGoto(1, 1);
                LCDPutStr(" ");
                LCDGoto(1, 1);
                LCDPutChar(8);
            break;
            default:
                break;
            }
    
        switch (shield2)
        {
            case 0:
                LCDGoto(14, 1);
                LCDPutStr(" ");
            break;
            case 1:
                LCDGoto(14, 1);
                LCDPutStr(" ");
                unsigned char shield21 [ ] = {0x00,0x1F,0x11,0x11,0x11,0x0A,0x04,0x00};
                createCustomCharacter(shield21,6);
                LCDGoto(14, 1);
                LCDPutChar(5);
            break;
            case 2:
                LCDGoto(14, 1);
                LCDPutStr(" ");
                unsigned char shield22 [ ] = {0x00,0x1F,0x11,0x11,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(shield22,6);
                LCDGoto(14, 1);
                LCDPutChar(6);
            break;
                case 3:
                LCDGoto(14, 1);
                LCDPutStr(" ");
                LCDGoto(14, 1);
                LCDPutChar(8);
            break;
            default:
                break;
            }

    }