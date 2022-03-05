#include <iostream>

/**
 * Problema 102, capitulo 2
 * 
 * Introducir los enteros positivos A y B y determinar el
 * cociente y el residuo cuando A se divide entre B
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    1 mar 2022

using namespace std;

int main()
{
    unsigned int alfa, beta;
    double result;

    cout << "\nPROBLEMA 102, CAP\u00cdTULO 2";
    cout << "\n Ingrese el valor del numerador: ";
    cin >> alfa;
    cout << "\n Ingrese el valor del denominador: ";
    cin >> beta;
    result = double(alfa) / double(beta); //división
    cout << "\n A / B: " << result;
    result = alfa % beta; //residuo (aka modulo)
    cout << "\n A mod B: " << result << "\n";
    return 0;
}