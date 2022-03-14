#include <iostream>

/**
 * Problema 122, Capitulo 2
 * 
 * Encontrar la suma de una serie aritmética
 *  
 * A + (A+D) + (A+2D) + ... + (A+(N-1)D)
 * 
 * para valores dados de A, D y N.
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    3 mar 2022

using namespace std;

//excepciones a la sumatoria, para ahorrar procesamiento
double excep_def_aritmetica(double A, double D, unsigned int N){
    if (A==0)
    {
        double n_minus_1_cycles = (double(N)-1)/2;
        return double(N)*n_minus_1_cycles*D;
    }
    else if (D==0)
        return double(N)*A;
    else
    {
        double n_minus_1_cycles = (double(N)-1)/2;
        return double(N)*(A+n_minus_1_cycles*D);
    }  
}

//retorna el resultado de la serie
double suma_aritmetica(double A, double D, unsigned int N){
    switch(N){
        case 0: //cuando n=0, resulta 0
            return 0;
        break;
        case 1: //cuando n=1, resulta A
            return A;
        break;
        default: //resulta n(A+((n-1)/2)*D) (fórmula general)
            return excep_def_aritmetica(A,D,N);
        break;
    }
}

int main(){

    double A,D;
    unsigned int  N;

    //despliegue de los resultados
    cout << "\nPROBLEMA 118, CAP\u00cdTULO 2\n";
    cout << "Suma aritm\u00e9tica de tipo\n";
    cout << "A + (A+D) + (A+2D) + ... + (A+(N-1)D)\n\n";
    cout << "Ingrese el valor para A: ";
    cin >> A;
    cout << "\nIngrese el valor para D: ";
    cin >> D;
    cout << "\nIngrese el valor para N: ";
    cin >> N;
    cout << "\nRESULTADO: " << suma_aritmetica(A,D,N) << "\n";
    return 0;
}