//Sprint1 David Altuve

#include <stdio.h> //Librer�a para el character print
#include "mcc_generated_files/mcc.h"
#include "lcd.h" //Librer�a para manejar la pantalla LCD
/*
                         Main application
 */
#define CaseEstudiante 1 // Caso para usar los �ltimos 3 d�gitos del estudiante
int last3digitsCarnet1 = 255; // Colocar los �ltimos tres d�gitos de su carnet  

#define CaseGerardo 2 // Gerardo nos acompa�a :D. �l ser� el caso 2
int last3digitsCarnet2 = 493; // �ltimos 3 d�gitos del carnet de Gerardo

int last3digitsCarnet3 = 420; // �ltimos 3 d�gitos del carnet del preparador
                              // Ser� el caso default

int sumdigits(int number) //Funci�n para sumar los d�gitos de un n�mero entero
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

//Estructura de main

void main(void)
{
    // Inicializaci�n de dispositivos
    
    SYSTEM_Initialize(); //Inicializaci�n para el microprocesador
    LCD_Initialize(); //Inicializaci�n para la pantalla LCD
    
    // Inicializaci�n de constantes y selecci�n de casos
    
    const int label =1;// Escoja el n�mero de la persona a utilizar
    int carnet; 
    char printchar[10];
    
    // Elecci�n de carnet a calcular
    
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
            carnet = last3digitsCarnet3; //El caso default ser� el del preparador
        }
    }
    /***************************************************************************************/
    // Parte 1: Implemente un c�digo que consiga los n�meros primos del 1 
    // al n�mero guardado en carnet y los sume. Ejm: Del 1 al 5 SumPrime debe
    // arrojar 10. No est� permitido usar funciones ni nada que se salga de los
    // contenidos de las gu�as.
    
    int SumPrime = 0; // variable en la que debe arrojarse la suma de n�meros primos
    /*Your code here*/
    // Impresi�n en pantalla para el apartado 1
    sprintf(printchar,"%d",carnet);
    LCDGoto(0,0);
    LCDPutStr("Carnet:");
    LCDGoto(0,1);
    LCDPutStr(printchar);
    
    //Declaraci�n de variables
    
    int i,number=2, prime;
    
    //C�lculo de suma de n�meros primos
    
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
        SumPrime = SumPrime+number;
      }
      ++number;
    }
    
    //Impresi�n en pantalla del resultado
    LCDClear();
    LCDGoto(0,0);
    LCDPutStr("SumPrime=");
    sprintf(printchar,"%d",SumPrime);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    __delay_ms(5000);
    LCDClear();
    
    // Parte 2: Implemente el c�digo neceario para sumar los d�gitos de SumPrime hasta 
    // tener 1 solo d�gito. En el ejemplo anterior 1+0 har�a que SumDigits sea
    // igual a 1. No est� permitido usar funciones ni nada que se salga de los
    // contenidos de las gu�as.
    
    int SumDigits = 0; //variable en la que debe arrojarse la suma de los d�gitos
    /*Your code here*/
    
    //Impresi�n en pantalla para el apartado 2
    LCDGoto(0,0);
    LCDPutStr("sumDigits=");
    
    //Rutina para sumar los d�gitos de un n�mero entero
    
    number=SumPrime;
    do
    {
      SumDigits = sumdigits(number);
      number = SumDigits;
    } while (SumDigits>10);
    
    //Impresi�n en pantalla del resultado
    
    sprintf(printchar,"%d",SumDigits);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    __delay_ms(5000);
    LCDClear();

/***************************************************************************************/
    
/***************************************************************************************/
    // Parte 3: Implemente el c�digo neceario para escribir SumDigits en n�meros 
    // binarios en una variable tipo long. Ejemplo: si SumDigits fuese igual a 7 
    // en la variable Binary deber�a verse como 111 (8 --> 1000). No est�  
    // permitido usar funciones ni nada que se salga de los contenidos de las gu�as
    
    //Impresi�n en pantalla del apartado 3
    
    LCDGoto(0,0);
    LCDPutStr("Binary=");
    long Binary = 0;
    
     //variable en la que debe arrojarse el n�mero binario
    /*Your code here*/
    
    //Rutina para convertir un entero de un solo d�gito en binario
    
    int bin[4]={0,0,0,0};
    i=0;
    number=SumDigits;
    
      while (number>0)
      {
        bin[i] = number%2;
        number = number/2;
        i++;
      }
    Binary= (1000*bin[3])+(100*bin[2])+(10*bin[1])+(1*bin[0]);
      
/***************************************************************************************/
    //Escritura en pantalla del resultado
      
    sprintf(printchar,"%d",Binary);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    
    while (1)
    {
        //Ciclo infinito
        
        int check1 = SumPrime;
        int check2 = SumDigits;
        long check3 = Binary;
        
    }
}
/**
 End of File
*/