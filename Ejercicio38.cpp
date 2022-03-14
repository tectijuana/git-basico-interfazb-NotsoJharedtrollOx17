#include <iostream>
#include <math.h>

/**
 * Problema 38, Capitulo 5
 * 
 * Doce personas están en una habitación. Utilizar
 * una simulación en computadora para determinar
 * aproximadamente la probabilidad de que al menos tres
 * de ellas tengan la fecha de su nacimiento en el mismo mes
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    11 mar 2022

class Muestra
{
    public:
        Muestra(unsigned short p): personas(p) {
            probabilidad_mismo_cumple = 1;
        }

        long double calcular_probabilidad()
        {
            //se usa la distribuciónn de Poisson:
                //1 - L*e^-L; L = (n choose 3) * (1/(12^2))

            unsigned short indice=0;
            long double denominador = pow(personas, 2) * 6; //(1/((12^2)*6))
            long double exponencial = 0; //e

            for(indice; indice<3; indice++)
                probabilidad_mismo_cumple = 
                probabilidad_mismo_cumple * double(personas-indice);

            probabilidad_mismo_cumple = probabilidad_mismo_cumple / denominador;
            exponencial = exp(-probabilidad_mismo_cumple);
            probabilidad_mismo_cumple = probabilidad_mismo_cumple * exponencial;
            probabilidad_mismo_cumple = 100 * (1-probabilidad_mismo_cumple);

            return probabilidad_mismo_cumple;
        }

        void desplegar_resultados()
        {
            std::cout.precision(17);
            std::cout << "Personas: " << personas;
            std::cout << "\nP(tres personas cumplan años el mismo mes) = ";
            std::cout << calcular_probabilidad() << std::fixed << std::endl << std::endl;
        }

    private:
        unsigned short personas;
        long double probabilidad_mismo_cumple;
};

int main()
{
    const unsigned short personas = 12;
    Muestra experimento = Muestra(personas);

    std::cout << "\nPROBLEMA 38, CAP\u00cdTULO 5\n";
    experimento.desplegar_resultados();
}