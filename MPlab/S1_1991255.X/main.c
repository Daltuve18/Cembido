//Sprint1 David Altuve

#include <stdio.h> //Librería para el character print
#include "mcc_generated_files/mcc.h"
#include "lcd.h" //Librería para manejar la pantalla LCD
/*
                         Main application
 */
#define CaseEstudiante 1 // Caso para usar los últimos 3 dígitos del estudiante
int last3digitsCarnet1 = 255; // Colocar los últimos tres dígitos de su carnet  

#define CaseGerardo 2 // Gerardo nos acompaña :D. Él será el caso 2
int last3digitsCarnet2 = 493; // Últimos 3 dígitos del carnet de Gerardo

int last3digitsCarnet3 = 420; // Últimos 3 dígitos del carnet del preparador
                              // Será el caso default

int sumdigits(int number) //Función para sumar los dígitos de un número entero
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
    // Inicialización de dispositivos
    
    SYSTEM_Initialize(); //Inicialización para el microprocesador
    LCD_Initialize(); //Inicialización para la pantalla LCD
    
    // Inicialización de constantes y selección de casos
    
    const int label =1;// Escoja el número de la persona a utilizar
    int carnet; 
    char printchar[10];
    
    // Elección de carnet a calcular
    
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
    
    int SumPrime = 0; // variable en la que debe arrojarse la suma de números primos
    /*Your code here*/
    // Impresión en pantalla para el apartado 1
    sprintf(printchar,"%d",carnet);
    LCDGoto(0,0);
    LCDPutStr("Carnet:");
    LCDGoto(0,1);
    LCDPutStr(printchar);
    
    //Declaración de variables
    
    int i,number=2, prime;
    
    //Cálculo de suma de números primos
    
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
    
    //Impresión en pantalla del resultado
    LCDClear();
    LCDGoto(0,0);
    LCDPutStr("SumPrime=");
    sprintf(printchar,"%d",SumPrime);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    __delay_ms(5000);
    LCDClear();
    
    // Parte 2: Implemente el código neceario para sumar los dígitos de SumPrime hasta 
    // tener 1 solo dígito. En el ejemplo anterior 1+0 haría que SumDigits sea
    // igual a 1. No está permitido usar funciones ni nada que se salga de los
    // contenidos de las guías.
    
    int SumDigits = 0; //variable en la que debe arrojarse la suma de los dígitos
    /*Your code here*/
    
    //Impresión en pantalla para el apartado 2
    LCDGoto(0,0);
    LCDPutStr("sumDigits=");
    
    //Rutina para sumar los dígitos de un número entero
    
    number=SumPrime;
    do
    {
      SumDigits = sumdigits(number);
      number = SumDigits;
    } while (SumDigits>10);
    
    //Impresión en pantalla del resultado
    
    sprintf(printchar,"%d",SumDigits);
    LCDGoto(0,1);
    LCDPutStr(printchar);
    __delay_ms(5000);
    LCDClear();

/***************************************************************************************/
    
/***************************************************************************************/
    // Parte 3: Implemente el código neceario para escribir SumDigits en números 
    // binarios en una variable tipo long. Ejemplo: si SumDigits fuese igual a 7 
    // en la variable Binary debería verse como 111 (8 --> 1000). No está  
    // permitido usar funciones ni nada que se salga de los contenidos de las guías
    
    //Impresión en pantalla del apartado 3
    
    LCDGoto(0,0);
    LCDPutStr("Binary=");
    long Binary = 0;
    
     //variable en la que debe arrojarse el número binario
    /*Your code here*/
    
    //Rutina para convertir un entero de un solo dígito en binario
    
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