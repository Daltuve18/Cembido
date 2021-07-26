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

CreateCustomCharacter -- Stores a custom character into the LCD's CGRAM
basicShot             -- Basic shot animation 
disableButton         -- Disables a player's buttons
enableButton          -- enables a player's buttons
 
***/

/*Global Variables*/

extern bool player;

/*Functions*/

void createCustomCharacter (unsigned char *Pattern, const char Location);
void basicShot (int direction);
void disableButton(bool player);
void enableButton(bool player);