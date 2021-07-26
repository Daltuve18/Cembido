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

Available functions:

printMenu      -- Print the abilities menu
mainMenu       -- Print the select main menu
cleanMenu      -- Clears the menu printed
nextTurn       -- Selects the incoming turn player
welcomeScreen  -- Prints the welcome screen
failScreen     -- Prints the missed shot screen
cooldownScreen -- Prints the ability on cooldown screen
startFight     -- Prints the start fight screen 
cleanFullMenu  -- Clears full menu 

***/
extern bool inGame;
extern uint8_t mainState;
extern uint8_t playerTurn;
extern int special1CD;
extern int fix1CD;
extern int shield1CD;
extern int special2CD;
extern int fix2CD;
extern int shield2CD;

void printMenu (void);
void cleanMenu (void);
void cleanFullMenu (void);
void mainMenu(void);
void winScreen(int player);
void failScreen(void);
void startFight (void);
void cooldownScreen(void);
void nextTurn(bool player);
void welcomeScreen(void);

