/***
-----------------------------------------------------------------------------
PG7233
-----------------------------------------------------------------------------
Package name  : naves.h
Description   : Rising Force Fighters
Authors       : David Altuve & Leonardo Cabrera
Email         : 19-91255@usb.ve / 20-91371@usb.ve
Version       : 01.00
Revision      : 00
Date          : 7/18/2021
-----------------------------------------------------------------------------

***/
extern uint8_t ship1;
extern uint8_t ship2;

extern int health1;
extern int health2;

extern int shield1;
extern int shield2;


void printShip(void);
void printHeart(void);
void printShield(void);
bool attack(bool isSpecial, bool player);
void fixShield(bool player);
void fix(bool player);

