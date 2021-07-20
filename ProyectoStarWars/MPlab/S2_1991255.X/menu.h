/***
-----------------------------------------------------------------------------
PG7233
-----------------------------------------------------------------------------
Package name  : functions.h
Description   : Rising Force Fighters
Authors       : David Altuve & Leonardo Cabrera
Email         : 19-91255@usb.ve / 20-91371@usb.ve
Version       : 01.00
Revision      : 00
Date          : 7/18/2021
-----------------------------------------------------------------------------

***/
extern bool inGame;
extern uint8_t mainState;
extern uint8_t playerTurn;

void printMenu (void);
void cleanMenu (void);
void cleanFullMenu (void);
void mainMenu(void);
void startFight (void);

