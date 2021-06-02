#include <stdio.h>
/* Bienvenidos a este primer ejercicio de evaluación de los laboratorios.
 * Por favor leer todos los comentarios de este archivo antes de empezar a trabajar. 
 * A continuación se les presentará un código con secciones faltantes. 
 * Sigan los pasos para completar estas secciones. La nota de esta evaluación 
 * es 15% de la materia. Para obtenerlos deben realizar todos los ejercicios. 
 * Estos son mayoritariamente de programación y deberán incluir actividades 
 * como enviar capturas de pantalla por discord.
 * 
 * Además de las operaciones necesarias para resolver la actividad deben probar 
 * otras operaciones, sumar variables, realizar restas, multiplicaciones, divisiones, 
 * residuos, etc; que aunque no formen parte de la solución que implementen, servirá
 * para que practiquen más allá de lo que muestra la guía. Nosotros veremos lo que
 * practiquen extra al entregar esta actividad ya que el fin de esto es practicar, 
 * aprender, ver como se hacen las operaciones y también conseguir errores 
 * para aprender a solucionarlos */



#define CaseEstudiante 1 // Caso para usar los últimos 3 dígitos del estudiante
int last3digitsCarnet1 = 255; // Colocar los últimos tres dígitos de su carnet  

#define CaseGerardo 2 // Gerardo nos acompaña :D. Él será el caso 2
int last3digitsCarnet2 = 493; // Últimos 3 dígitos del carnet de Gerardo

int last3digitsCarnet3 = 420; // Últimos 3 dígitos del carnet del preparador
                              // Será el caso default

void main(void)
{
    
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
    carnet = 33;
    //int SumPrime = 0; // variable en la que debe arrojarse la suma de números primos
    /*Your code here*/
    int SumPrime = 0, i,number=2, prime;
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
/***************************************************************************************/
    
/***************************************************************************************/    
    // Parte 2: Implemente el código neceario para sumar los dígitos de SumPrime hasta 
    // tener 1 solo dígito. En el ejemplo anterior 1+0 haría que SumDigits sea
    // igual a 1. No está permitido usar funciones ni nada que se salga de los
    // contenidos de las guías.
    
    int SumDigits = 0,digit; //variable en la que debe arrojarse la suma de los dígitos
    /*Your code here*/
    number=SumPrime;

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

    do
    {
      SumDigits = sumdigits(number);
      number = SumDigits;
    } while (SumDigits>10);


/***************************************************************************************/
    
/***************************************************************************************/
    // Parte 3: Implemente el código neceario para escribir SumDigits en números 
    // binarios en una variable tipo long. Ejemplo: si SumDigits fuese igual a 7 
    // en la variable Binary debería verse como 111 (8 --> 1000). No está  
    // permitido usar funciones ni nada que se salga de los contenidos de las guías
    
    
    long Binary = 0;
     //variable en la que debe arrojarse el número binario
    /*Your code here*/
    int bin[4]={0,0,0,0};
    i=0;
      while (SumDigits>0)
      {
        bin[i] = SumDigits%2;
        printf("\n%d",bin[i]);
        SumDigits = SumDigits/2;
        i++;
      }yo tam
      Binary= (1000*bin[3])+(100*bin[2])+(10*bin[1])+(1*bin[0]);
/***************************************************************************************/

/***************************************************************************************/
    // Parte 4: Como último requerimiento, se pide al estudiante crear un proyecto
    // con Proteus y presentar la data de Binary en cualquier forma que el estudiante 
    // considere ilustrativa. Esto puede ser en un pantalla, LCD, gráfica, 7 segmentos,
    // un arreglo de leds, etc.
    
    // Para entregar el ejercicio tienen que entregar un zip con la solución que 
    // incluya este proyecto de MPLAB y el proyecto de proteus. Además, deben 
    // colgar en un post(s) de discord los resultados de cada una de las secciones 
    // para los tres casos del switch.
    
    while (1)
    {
        
    }
/***************************************************************************************/
    
}