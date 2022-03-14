#include <iostream>
#include <math.h>

/**
 * Problema 36, Capitulo 5
 * 
 * Usted se encuentra en una habitación con otras
 * 29 personas. Cuál es la probabilidad de una de ellas
 * tenga la misma fecha de nacimieto que usted?
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
            unsigned short indice=0;
            long double denominador = pow(365, (double)personas);

            for(indice; indice<personas; indice++)
                probabilidad_mismo_cumple = 
                probabilidad_mismo_cumple * double(365-indice);

            probabilidad_mismo_cumple = probabilidad_mismo_cumple / denominador;
            probabilidad_mismo_cumple = 100 * (1-probabilidad_mismo_cumple);

            return probabilidad_mismo_cumple;
        }

        void desplegar_resultados()
        {
            std::cout.precision(17);
            std::cout << "Personas: " << personas;
            std::cout << "\nP(dos personas cumplan años el mismo dia) = ";
            std::cout << calcular_probabilidad() << std::fixed << std::endl << std::endl;
        }

    private:
        unsigned short personas;
        long double probabilidad_mismo_cumple;
};

int main()
{
    const unsigned short personas = 30;
    Muestra experimento = Muestra(personas);

    std::cout << "\nPROBLEMA 36, CAP\u00cdTULO 5\n";
    experimento.desplegar_resultados();
}