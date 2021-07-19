/***
-----------------------------------------------------------------------------
PG7233
-----------------------------------------------------------------------------
Package name  : functions.h
Description   : Rising Force Fighters
Authors       : David Altuve & Leonardo Cabrera
Email         : 19-91255@usb.ve / 
Version       : 01.00
Revision      : 00
Date          : 7/18/2021
-----------------------------------------------------------------------------

Available functions:

CreateCustomCharacter -- Stores a custom character into the LCD's CGRAM
idleScreen            -- Prints the idle screen with both ships
basicShoot            -- Shoot the basic animation in a specific direction

***/

void createCustomCharacter (unsigned char *Pattern, const char Location);
void idleScreen (void);
void basicShoot (int direction);