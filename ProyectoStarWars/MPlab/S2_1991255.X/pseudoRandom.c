/***
-----------------------------------------------------------------------------
PG7233
-----------------------------------------------------------------------------
Package name  : pseudoRandom.c
Description   : Rising Force Fighters
Authors       : David Altuve & Leonardo Cabrera
Email         : 19-91255@usb.ve / 20-91371@usb.ve
Version       : 01.00
Revision      : 00
Date          : 7/18/2021
-----------------------------------------------------------------------------

***/

#include <stdio.h> 
#include "mcc_generated_files/mcc.h"

double counter = 0.0;

bool taylorSine(void)

    /***
     Starts the game routine once the ships have been chosen

        Arguments:
     
        count --  TMR0 counter value

        Return values: Square Sine's Taylor series expansion of 20 terms 

    ***/
    {   
        bool hit;
        unsigned N=12; 
        unsigned k=1; 
        double sinx = 0; 
        double term; 
        term = counter; 
        while (k < N) 
            { // iterate over 
                sinx +=  term; 
                k = k + 2;  // only odd numbers, since the even terms are zeros 
                term *= -(counter * counter) / ( (k-1) * k); 
            }
        sinx*=sinx;
        
        if(sinx>0.15)
            {
             hit = true;
            }
        else
            {
                hit = false;
            }   
        return hit;
    } 

