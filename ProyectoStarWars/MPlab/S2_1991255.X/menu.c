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

***/


#include <string.h>
#include <stdio.h>
#include "lcd.h"
#include "menu.h"
#include "functions.h"
uint8_t lcdOffset = 3;
bool inGame = false;
uint8_t mainState = 0;
uint8_t playerTurn = 0;

void printMenu (void)

{
    if(inGame){
        cleanMenu();
        LCDGoto(lcdOffset, 0);
        LCDPutStr("   Menu   ");
    }else {
        cleanFullMenu();
        mainMenu();
    }
}

void mainMenu(void){
    switch (mainState){
        case 0:
            LCDGoto(0, 0);
            LCDPutStr("Select ship#1");
            LCDGoto(0, 1);
            LCDPutStr("> Tie Fighter");
        break;
        case 1:
            LCDGoto(0, 0);
            LCDPutStr("  Tie Fighter");
            LCDGoto(0, 1);
            LCDPutStr("> X wing");
        break;
        case 2:
            LCDGoto(0, 0);
            LCDPutStr("Select ship#2");
            LCDGoto(0, 1);
            LCDPutStr("> Tie Fighter");
        break;
        case 3:
            LCDGoto(0, 0);
            LCDPutStr("  Tie Fighter");
            LCDGoto(0, 1);
            LCDPutStr("> X wing");
        break;
        default:
            break;
    }
}

void cleanMenu (void)

{
    LCDGoto(lcdOffset, 0);
    LCDPutStr("           ");
    LCDGoto(lcdOffset, 1);
    LCDPutStr("           ");
    
}


void startFight (void)

{
    cleanFullMenu();
    idleScreen();
    LCDGoto(lcdOffset, 0);
    LCDPutStr("Start Fight");
    __delay_ms(2000);
    mainState  = 0;
    inGame = true;
    printMenu();
    
    
}

void cleanFullMenu (void)

{
    LCDGoto(0, 0);
    LCDPutStr("                ");
    LCDGoto(0, 1);
    LCDPutStr("                ");
    
}