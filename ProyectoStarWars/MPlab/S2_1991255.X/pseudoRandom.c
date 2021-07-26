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

taylorSine -- Calculates the squared sine Taylor's series, using the TMR0 value 

***/

#include <stdio.h> 
#include "mcc_generated_files/mcc.h"

double counter = 0.0;

bool taylorSine(int ship,bool isSpecial)

    /***
     Calculates the Square Sine Taylor's series of 12 terms

        Arguments:
     
        ship      --  Which player is shooting
        isSpecial --  If the attack is a special or not

        Return values:

    ***/
    {   
        bool hit;
        unsigned N=12; 
        unsigned k=1; 
        double sinx = 0; 
        double term; 
        term = counter; 
        double prod  =  0.15;
        if (isSpecial){
            if (ship == 0){
                prod = 0.0;
            }
        }
        while (k < N) 
            { // iterate over 
                sinx +=  term; 
                k = k + 2;  // only odd numbers, since the even terms are zeros 
                term *= -(counter * counter) / ( (k-1) * k); 
            }
        sinx*=sinx;
        
        if(sinx>prod)
            {
             hit = true;
            }
        else
            {
                hit = false;
            }   
        return hit;
    } 

