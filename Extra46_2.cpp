#include <stdio.h>
#include <utility>
#include <iostream>

/**
 * Problema 46, Capítulo 2
 * 
 * Cambiar el decimal periódico a fracción
 * racional de la forma:
 * 
 *  M   /   N
 * 
 * donde M y N sean enteros
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    9 mar 2022

class num_racionales
{
    public:
        num_racionales(unsigned int num) {
            fraccion.first = num;
            fraccion.second = potencias_diez() - 1;
        }

        //obtiene la cantidad de dígitos del repetando (asumiendo base 10)
        unsigned short norma_numerador(unsigned int digits)
        {
            unsigned short n = 0;

            do
            {
                n++;
                digits/= 10;
            }
            while (digits);

            return n;
        }

        //obtiene 10^n por medio de bitshifts
        unsigned int potencias_diez()
        {
            unsigned int ultimo_factor = 5;
            unsigned short longitud = norma_numerador(fraccion.first);

            for(unsigned short i=0; i<longitud-1; i++)
                ultimo_factor = ultimo_factor * 5;
            
            return ultimo_factor << longitud;
        }

        //retorna el máximo común denominador para reducir las fracciones
        unsigned int gcd(std::pair<unsigned int, unsigned int> componentes)
        {   
            while (componentes.second){
                componentes = { 
                    componentes.second, 
                    componentes.first%componentes.second
                    };      
            }

            return componentes.first;
        }

        //reduccion de la fracción por medio del máximo común denominador
        void reduccion_fracc()
        {
            unsigned int factor_redox = gcd(fraccion);

            fraccion.first /= factor_redox;
            fraccion.second /= factor_redox;
        }

        void mostrar_fracc()
        {
            printf("Expresión racional equivalente: %d / %d\n\n",
            fraccion.first, fraccion.second);
        }

    private:
        std::pair<unsigned int, unsigned int> fraccion;
};

int main()
{
    //variable auxiliar
    unsigned int decimales;

    //despliegue
    printf("\nPROBLEMA 46, CAP\u00cdTULO 2\n");
    printf("Ingrese los decimales periódicos: 0.");
    std::cin >> decimales;

    //objeto auxiliar y llamada de sus funciones
    num_racionales expresion = num_racionales(decimales);
    expresion.reduccion_fracc();
    expresion.mostrar_fracc();
}