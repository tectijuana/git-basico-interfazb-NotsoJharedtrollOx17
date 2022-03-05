#include <iostream>
#include <exception>

/**
 * Problema 2,  Capitulo 3
 * 
 * Dada una medida angular mayor que 0 grados pero menor
 * que 180 grados, clasificar el ángulo como obtuso, recto
 * o agudo.
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    3 mar 2022

using namespace std;

//excepción personalizada para el programa
struct anglesException : public exception
{
	const char * what () const throw ()
    {
    	return "El angulo supera el dominio de (0^grados, 180^grados)!";
    }
};

//revisa si és ángulo recto, agudo u obtuso
void clasificacion_angulo(double &angulo){
    if(angulo>0 && angulo<180)
    {
        if(angulo==90)
            cout << "\nEl \u00e1ngulo es recto!\n";
        else if (angulo>90)
            cout << "\nEl \u00e1ngulo es obtuso!\n";
        else
            cout << "\nEl \u00e1ngulo es agudo!\n";  
    }
    else
        throw anglesException();
}

int main()
{
    double angulo;
    try
    {
        //despliegue de los resultados
        cout << "\nPROBLEMA 2, CAP\u00cdTULO 3\n";
        cout << "\nIngrese del valor del \u00e1ngulo: ";
        cin >> angulo;
        clasificacion_angulo(angulo);
    }
    catch(anglesException &e) //excepción personalizada
    {
        cout << e.what() << endl;
        main();
    } 

    return 0;
}
