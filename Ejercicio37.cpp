#include <iostream>
#include <math.h>

/**
 * Problema 37, Capitulo 5
 * 
 * Calcular e imprimir una tabla de probabilidades
 * teóricas de que dos personas en una habitación
 * con N personas tengan la misma fecha de nacimiento.
 * Variar a N de 1 a 50
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    11 mar 2022

class Muestra
{
    public:
        Muestra() {
            personas = 1;
            probabilidad_mismo_cumple = 1;
        }

        long double calcular_probabilidad()
        {
            unsigned short indice=0;
            long double denominador = pow(365, (double)personas);

            for(indice; indice<personas; indice++)
                probabilidad_mismo_cumple = 
                probabilidad_mismo_cumple * double(365-indice);

            probabilidad_mismo_cumple = probabilidad_mismo_cumple / denominador;
            probabilidad_mismo_cumple = 100 * (1-probabilidad_mismo_cumple);

            return probabilidad_mismo_cumple;
        }

        void desplegar_un_resultado()
        {
            std::cout.precision(17);
            std::cout << "\nPersonas: " << personas;
            std::cout << "\nP(dos personas cumplan años el mismo dia) = ";
            std::cout << calcular_probabilidad() << std::fixed << std::endl << std::endl;
        }

        void desplegar_varios_resultados()
        {
            for(personas; personas <= 50; personas++)
            {
                desplegar_un_resultado();
                probabilidad_mismo_cumple = 1;
            }
        }

    private:
        unsigned short personas;
        long double probabilidad_mismo_cumple;
};

int main()
{
    Muestra experimento = Muestra();

    std::cout << "\nPROBLEMA 37, CAP\u00cdTULO 5\n";
    experimento.desplegar_varios_resultados();
}

