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

/*Standard Libraries*/
#include <string.h>
#include <stdio.h>
#include "lcd.h"

/*Local Libraries*/
#include "menu.h"
#include "functions.h"
#include "naves.h"

/*Variable initialization*/
uint8_t lcdOffset = 3;
bool inGame = false;
uint8_t mainState = 0;

int special1CD = 1;
int fix1CD = 1;
int shield1CD = 1;
int special2CD = 1;
int fix2CD = 1;
int shield2CD = 1;
char s[15];

void printMenu (void)

/***
    Prints the mine screen menu

    Arguments: 

    Return values: None

***/
{
    if(inGame){
        cleanMenu();
        switch (mainState){
        case 0:
            LCDGoto(lcdOffset, 0);
            LCDPutStr(" Player 1");
            LCDGoto(lcdOffset, 1);
            LCDPutStr(">Attack");
        break;
        case 1:
            LCDGoto(lcdOffset, 0);
            LCDPutStr(" Attack");
            LCDGoto(lcdOffset, 1);
            sprintf(s, ">Special %d", special1CD);
            LCDPutStr(s);
        break;
        case 2:
            LCDGoto(lcdOffset, 0);
            sprintf(s, " Special %d", special1CD);
            LCDPutStr(s);
            LCDGoto(lcdOffset, 1);
            sprintf(s, ">Fix %d", fix1CD);
            LCDPutStr(s);
        break;
        case 3:
            LCDGoto(lcdOffset, 0);
            sprintf(s, " Fix %d", fix1CD);
            LCDPutStr(s);
            LCDGoto(lcdOffset, 1);
            sprintf(s, ">Shield %d", shield1CD);
            LCDPutStr(s);
        break;
        case 4:
            LCDGoto(lcdOffset, 0);
            LCDPutStr(" Player 2");
            LCDGoto(lcdOffset, 1);
            LCDPutStr(">Attack");
        break;
        case 5:
            LCDGoto(lcdOffset, 0);
            LCDPutStr(" Attack");
            LCDGoto(lcdOffset, 1);
            sprintf(s, ">Special %d", special2CD);
            LCDPutStr(s);
        break;
        case 6:
            LCDGoto(lcdOffset, 0);
            sprintf(s, " Special %d", special2CD);
            LCDPutStr(s);
            LCDGoto(lcdOffset, 1);
            sprintf(s, ">Fix %d", fix2CD);
            LCDPutStr(s);
        break;
        case 7:
            LCDGoto(lcdOffset, 0);
            sprintf(s, " Fix %d", fix2CD);
            LCDPutStr(s);
            LCDGoto(lcdOffset, 1);
            sprintf(s, ">Shield %d", shield2CD);
            LCDPutStr(s);
        break;
        default:
            break;
        }
    }else {
        cleanFullMenu();
        mainMenu();
    }
}

void mainMenu(void)
    /***
     Main menu state machine

    Arguments: 

    Return values: None

    ***/
    {
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
    /***
    Clean up the main menu

    Arguments: 

    Return values: None

    ***/

    {
        LCDGoto(lcdOffset, 0);
        LCDPutStr("           ");
        LCDGoto(lcdOffset, 1);
        LCDPutStr("           ");   
    }
void nextTurn(bool player){
    if(!player){
        if (special1CD > 0){
            special1CD=special1CD-1;
        }
        if (fix1CD > 0){
            fix1CD=fix1CD-1;
        }
        if (shield1CD > 0){
            shield1CD=shield1CD-1;
        }
        disableButton(false);
        enableButton(true);

        mainState  = 4;
    }else{
        if (special2CD > 0){
            special2CD=special2CD-1;
        }
        if (fix2CD > 0){
            fix2CD=fix2CD-1;
        }
        if (shield2CD > 0){
            shield2CD=shield2CD-1;
        }
        disableButton(true);
        enableButton(false);

        mainState  = 0;
    }
}

void winScreen(int player){
    if (player==0){
        cleanFullMenu();
        LCDGoto(0, 0);
        LCDPutStr("Game Over");
        LCDGoto(0, 1);
        LCDPutStr("Winner: 1");
    }else  {
        cleanFullMenu();
        LCDGoto(0, 0);
        LCDPutStr("Game Over");
        LCDGoto(0, 1);
        LCDPutStr("Winner: 2");
    }
    __delay_ms(1000);
    inGame = false;
    mainState = 0;
    health1=4;
    health2=4;
    shield1=3;
    shield2=3;
    special1CD = 1;
    fix1CD = 1;
    shield1CD = 1;
    special2CD = 1;
    fix2CD = 1;
    shield2CD = 1;
    welcomeScreen();
    printMenu();
    
    
}
void welcomeScreen(){
    cleanMenu();
    LCDGoto(lcdOffset, 0);
    LCDPutStr("Force");
    LCDGoto(lcdOffset, 1);
    LCDPutStr("Fighters");
    __delay_ms(500);
}


void failScreen(){
    cleanMenu();
    LCDGoto(lcdOffset, 0);
    LCDPutStr("   Miss");
    __delay_ms(500);
}

void cooldownScreen(){
    cleanMenu();
    LCDGoto(lcdOffset, 0);
    LCDPutStr("cooldown");
    LCDGoto(lcdOffset, 1);
    LCDPutStr("skill");
    __delay_ms(500);
}

void startFight (void)

    /***
     Starts the game routine once the ships have been chosen

        Arguments: 

        Return values: None

    ***/

    {
        cleanFullMenu();
        printShip();
        printHeart();
        printShield();
        LCDGoto(lcdOffset, 0);
        LCDPutStr("Start Fight");
        __delay_ms(1000);
        mainState  = 0;
        inGame = true;
        printMenu();

    }

void cleanFullMenu (void)
    /***
     Full screen clean

        Arguments: 

        Return values: None

    ***/
    {
        LCDGoto(0, 0);
        LCDPutStr("                ");
        LCDGoto(0, 1);
        LCDPutStr("                ");   
    }