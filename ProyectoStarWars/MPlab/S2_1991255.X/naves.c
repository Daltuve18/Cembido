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
#include "naves.h"

/*Local Libraries*/

#include "menu.h"
#include "functions.h"
#include "psudoRandom.h"

uint8_t ship1;
uint8_t ship2;

int health1=4;
int health2=4;

int shield1=3;
int shield2=3;

bool attack(bool isSpecial, bool player){
    if (!player){
        basicShoot(0);
        if (taylorSine(ship1,isSpecial)){
            if (isSpecial){
                if (shield2 == 0){
                    health2 = health2-2;
                }else{
                    shield2 = shield2-2;
                }
                if (shield2 < 0){
                    shield2=0;
                    health2 = health2-1;
                }
                if (health2 < 0){
                    health2 = 0;
                }
            }else{
                if (shield2 == 0){
                    health2 = health2-1;
                }else{
                    shield2 = shield2-1;
                }
            }
            printHeart();
            printShield();
            return true;
        } else{
            return false;
        }
    }else{
        basicShoot(1);
        if (taylorSine(ship2,isSpecial)){
            if (isSpecial){
                if (shield1 == 0){
                    health1 = health1-2;
                }else{
                    shield1 = shield1-2;
                }
                if (shield1 < 0){
                    shield1=0;
                    health1 = health1-1;
                }
                if (health1 < 0){
                    health1 = 0;
                }
            }else{
                if (shield1 == 0){
                    health1 = health1-1;
                }else{
                    shield1 = shield1-1;
                }
            }
            printHeart();
            printShield();
            return true;
        } else{
            return false;
        }
        
    }
}

void fix(bool player){
    if(!player){
        if (health1<4){
            health1=health1+1;
            
        }
    }else{
        if (health2<4){
            health2=health2+1;
            
        }
    }
    printHeart();
}

void fixShield(bool player){
    int value = 1;
    if(!player){
        if(ship1 ==  1){
            value  = 2;
        }
        if (shield1<4){
            shield1=shield1+value;
        }
        if (shield1 >4){
            shield1=4;
        }
    }else{
        if(ship2 ==  1){
            value  = 2;
        }
        if (shield2<4){
            shield2=shield2+value; 
        }
        if (shield2 >4){
            shield2=4;
        }
    }
    printShield();
}

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
                createCustomCharacter(heart11,3);
                LCDGoto(0, 1);
                LCDPutChar(3);
            break;
            case 2:
                LCDGoto(0, 1);
                LCDPutStr(" ");
                unsigned char heart12 [ ] = {0x00,0x0A,0x1D,0x19,0x19,0x0A,0x04,0x00};
                createCustomCharacter(heart12,3);
                LCDGoto(0, 1);
                LCDPutChar(3);
            break;
            case 3:
                LCDGoto(0, 1);
                LCDPutStr(" ");
                unsigned char heart13 [ ] = {0x00,0x0A,0x1D,0x1D,0x1D,0x0E,0x04,0x00};
                createCustomCharacter(heart13,3);
                LCDGoto(0, 1);
                LCDPutChar(3);
            break;
                case 4:
                LCDGoto(0, 1);
                LCDPutStr(" ");
                unsigned char heart14 [ ] = {0x00,0x00,0x0A,0x1F,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(heart14,3);
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
                createCustomCharacter(heart21,5);
                LCDGoto(15, 1);
                LCDPutChar(5);
            break;
            case 2:
                LCDGoto(15, 1);
                LCDPutStr(" ");
                unsigned char heart22 [ ] = {0x00,0x0A,0x1D,0x19,0x19,0x0A,0x04,0x00};
                createCustomCharacter(heart22,5);
                LCDGoto(15, 1);
                LCDPutChar(5);
            break;
            case 3:
                LCDGoto(15, 1);
                LCDPutStr(" ");
                unsigned char heart23 [ ] = {0x00,0x0A,0x1D,0x1D,0x1D,0x0E,0x04,0x00};
                createCustomCharacter(heart23,5);
                LCDGoto(15, 1);
                LCDPutChar(5);
            break;
                case 4:
                LCDGoto(15, 1);
                LCDPutStr(" ");
                unsigned char heart24 [ ] = {0x00,0x00,0x0A,0x1F,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(heart24,5);
                LCDGoto(15, 1);
                LCDPutChar(5);
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
                createCustomCharacter(shield11,6);
                LCDGoto(1, 1);
                LCDPutChar(6);
            break;
            case 2:
                LCDGoto(1, 1);
                LCDPutStr(" ");
                unsigned char shield12 [ ] = {0x00,0x1F,0x11,0x11,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(shield12,6);
                LCDGoto(1, 1);
                LCDPutChar(6);
            break;
                case 3:
                LCDGoto(1, 1);
                LCDPutStr(" ");
                unsigned char shield13 [ ] = {0x00,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(shield13,6);
                LCDGoto(1, 1);
                LCDPutChar(6);
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
                createCustomCharacter(shield21,7);
                LCDGoto(14, 1);
                LCDPutChar(7);
            break;
            case 2:
                LCDGoto(14, 1);
                LCDPutStr(" ");
                unsigned char shield22 [ ] = {0x00,0x1F,0x11,0x11,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(shield22,7);
                LCDGoto(14, 1);
                LCDPutChar(7);
            break;
                case 3:
                LCDGoto(14, 1);
                LCDPutStr(" ");
                unsigned char shield23 [ ] = {0x00,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00};
                createCustomCharacter(shield23,7);
                LCDGoto(14, 1);
                LCDPutChar(7);
            break;
            default:
                break;
            }
    }