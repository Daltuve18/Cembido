/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF1718
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#include <stdio.h>
#include "mcc_generated_files/mcc.h"
#include "lcd.h"
/*
                         Main application
 */
#define CaseEstudiante 1 // Caso para usar los últimos 3 dígitos del estudiante
int last3digitsCarnet1 = 255; // Colocar los últimos tres dígitos de su carnet  

#define CaseGerardo 2 // Gerardo nos acompaña :D. Él será el caso 2
int last3digitsCarnet2 = 493; // Últimos 3 dígitos del carnet de Gerardo

int last3digitsCarnet3 = 420; // Últimos 3 dígitos del carnet del preparador
                              // Será el caso default

int sumdigits(int number)
{ 
  int SumDigits = 0,digit;
  while (number>0)
  {
    digit = number%10;
    SumDigits = SumDigits + digit;
    number = number /10;
  }
  return SumDigits;
}


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    LCD_Initialize();
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:
    
    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();
    LCDGoto(0,0);
    LCDPutStr("sumPrime=");
    
    const int label = 1; // Escoja el número de la persona a utilizar
    int carnet; 
    
    switch (label) // Escoge el carnet a utilizar
    {
        case CaseEstudiante:
        {
            carnet = last3digitsCarnet1;
            break;
        }
        case CaseGerardo:
        {
            carnet = last3digitsCarnet2;
            break;
        }
        default:
        {
            carnet = last3digitsCarnet3; //El caso default será el del preparador
        }
    }
    /***************************************************************************************/
    // Parte 1: Implemente un código que consiga los números primos del 1 
    // al número guardado en carnet y los sume. Ejm: Del 1 al 5 SumPrime debe
    // arrojar 10. No está permitido usar funciones ni nada que se salga de los
    // contenidos de las guías.
    //int SumPrime = 0; // variable en la que debe arrojarse la suma de números primos
    /*Your code here*/
    int SumPrime = 0, i,number=2, prime;
    char printchar[20];
    while(number<=carnet)
    {
      prime = 1;
      for(i=2;i<=number/2;i++)
      {
        if(number%i==0)
        {
          prime = 0;
          break;
        }
      }
      if(prime==1)
      {
        SumPrime= SumPrime+number;
      }
      ++number;
    }
    sprintf(printchar,"%d",SumPrime);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    __delay_ms(2000);
    LCDClear();
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    // Parte 2: Implemente el código neceario para sumar los dígitos de SumPrime hasta 
    // tener 1 solo dígito. En el ejemplo anterior 1+0 haría que SumDigits sea
    // igual a 1. No está permitido usar funciones ni nada que se salga de los
    // contenidos de las guías.
    
    int SumDigits = 0; //variable en la que debe arrojarse la suma de los dígitos
    /*Your code here*/
    number=SumPrime;
    LCDGoto(0,0);
    LCDPutStr("sumDigits=");
    
    do
    {
      SumDigits = sumdigits(number);
      number = SumDigits;
    } while (SumDigits>10);
    sprintf(printchar,"%d",SumDigits);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    __delay_ms(2000);
    LCDClear();

/***************************************************************************************/
    
/***************************************************************************************/
    // Parte 3: Implemente el código neceario para escribir SumDigits en números 
    // binarios en una variable tipo long. Ejemplo: si SumDigits fuese igual a 7 
    // en la variable Binary debería verse como 111 (8 --> 1000). No está  
    // permitido usar funciones ni nada que se salga de los contenidos de las guías
    
    LCDGoto(0,0);
    LCDPutStr("Binary=");
    long Binary = 0;
     //variable en la que debe arrojarse el número binario
    /*Your code here*/
    int bin[4]={0,0,0,0};
    i=0;
      while (SumDigits>0)
      {
        bin[i] = SumDigits%2;
        SumDigits = SumDigits/2;
        i++;
      }
      Binary= (1000*bin[3])+(100*bin[2])+(10*bin[1])+(1*bin[0]);
/***************************************************************************************/
    sprintf(printchar,"%d",Binary);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    __delay_ms(2000);
    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/