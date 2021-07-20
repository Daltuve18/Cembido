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


#include <string.h>
#include <stdio.h>
#include "lcd.h"
#include "menu.h"
#include "functions.h"

uint8_t ship1;
uint8_t ship2;

uint8_t corazon=4;
uint8_t escucdo=4;



void printShip()
{
    LCDClear();
    LCDGoto(0,0);
    LCDPutChar(ship1);
    if (ship2 == 1){
        LCDGoto(15,0);
        //LCDPutChar(Poner numero de nave volteada);
    }else {
        LCDGoto(15,0);
        LCDPutChar(ship2);   
    }
      
}



