#include <iostream>

/**
 * Problema 123 , Capitulo 2
 * 
 * Determinar la suma de la serie 
 * 
 * 1 + 2 + 4 + 8 + 16 + ... + 2^n
 * 
 * para cualquier valor entero positivo en n
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    3 mar 2022

using namespace std;

//definición recursiva del problema
unsigned long long suma_aritmetica(unsigned int N) {
    if (N==0)
        return 1;
    else 
        return (suma_aritmetica(N-1) << 1) + 1;
}

int main() {

    unsigned int cant_sumandos;
    
    //despliegue de los resultados
    cout << "\nPROBLEMA 118, CAP\u00cdTULO 2\n";
    cout << "Suma aritm\u00e9tica de tipo\n";
    cout << "1 + 2 + 4 + 8 + 16 + ... + 2^n\n\n";
    cout << "Ingrese el valor para n: ";
    cin >> cant_sumandos;
    cout << "\nRESULTADO: " << suma_aritmetica(cant_sumandos) << "\n";
    return 0;
}