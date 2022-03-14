#include <stdio.h>

/**
 * Problema 33, Capitulo 5
 * 
 * Willie Bigstep, cátcher de los Medias Rojas de Houston,
 * tiene una probabilidad de 0.3 de pegar un git cada vez que batea.
 * Cuál es la probabilidad en 50 veces al bat de que su promedio sea
 * menor que 0.25?
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    10 mar 2022

float prom_menor_un_cuarto (const double p, const double p_menos_1,
    const unsigned short n_eventos)
{
    double promedio=0;

    //contadores
    unsigned short i = 0;
    unsigned short j = n_eventos;
    unsigned short menor_un_cuarto;

    //verificación por medio de la formula de la media aritmética
    for(i; i<=n_eventos; i++)
    {
        promedio = ((double)i*p+(double)j*p_menos_1) / (double)n_eventos;
        promedio < 0.25F ? menor_un_cuarto++ : 0;
        j--;
    }

    return menor_un_cuarto;
}

int main()
{
    //debido a que es un tipo de binomio
        //si la probabilidad de un evento es 
        // p, pues su complemento es 1-p
    const double pega_hit = 0.3F;
    const double no_pega_hit = 0.7F;
    const unsigned short n_bateadas = 50;
    double menor_que_un_cuarto = prom_menor_un_cuarto(
            pega_hit, 
            no_pega_hit, 
            n_bateadas);

        //despliegue de los resultados
    printf("\nPROBLEMA 33, CAP\u00cdTULO 5\n");
    printf("P(pegar hit) = %f", pega_hit);
    printf("\nP(pegar hit) = %f", no_pega_hit);
    printf("\nP(promedio < 0.25) = %f\n", menor_que_un_cuarto);
    return 0;
}