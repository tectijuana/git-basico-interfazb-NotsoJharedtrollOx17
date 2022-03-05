#include <iostream>
# include <math.h>

/**
 * Problema 101, Capitulo 2
 * 
 * La función entera máxima se denota con f(x)= [x]. La función
 * asocia a cada número real x con el entero más grande que no exceda a x.
 * 
 * Encontrar el valor de la función entera máxima dado un argumento que sea
 * positivo, negativo ó cero.
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    1 mar 2022

using namespace std;

//representa la función del problema
int _floor(double number)
{
    int result = 0;
    double decimals = fmod(number, 1.0f); //evaluación del módulo, permite obtener decimales
    decimals == 0 ? result = number : // si x = 0 
        number > 0 ?  //si x > 0
            result = int(number-decimals) :
                result = int(number-decimals) - 1; //si x < 0
    return result;
}

int main()
{
    double number;
    cout << "\nPROBLEMA 101, CAP\u00cdTULO 2\n";
    cout << "Calculadora de la funci\u00f3n entera m\u00e1xima";
    cout << "\nIngrese el valor a evaluar: ";
    cin >> number;
    cout << "\nResultado: " << _floor(number) << "\n";
    return 0;
}