#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>

/**
 * Problema 5, Capítulo 5
 * 
 * Escribir un programa que simule arrojar un
 * dado 60 veces. Contar e imprimír el número de veces
 * que sale cada lado
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    9 mar 2022

//cuenta cuántas caras salieron en la cantidad de tiros, y los despliega
void cuantas_caras(unsigned short tope)
{
    //variables auxiliaes
    std::vector<unsigned short> valores_conteo = {0, 0, 0, 0, 0, 0};
    unsigned short cara_dada = 0;

    //semilla
    srand(std::time(NULL));

    for(unsigned short i=0; i<tope; i++)
    {
        cara_dada = rand() % 6 + 1; //numero del [1, 6]
        switch(cara_dada)
        {
            case 1:
                valores_conteo.at(0)++;
            break;

            case 2:
                valores_conteo.at(1)++;
            break;

            case 3:
                valores_conteo.at(2)++;
            break;

            case 4:
                valores_conteo.at(3)++;
            break;

            case 5:
                valores_conteo.at(4)++;
            break;

            case 6:
                valores_conteo.at(5)++;
            break;
        }
    }

    //impresion de valores
    printf("Valores obtenidos en %d tiros del dado:",tope);
    for (unsigned short i=0; i<valores_conteo.size(); i++)
        printf("\n  Cara %d: %d veces", i+1, (unsigned short)valores_conteo.at(i));
    printf("\n");
}

int main()
{
    //valor dado por el problema
    const short max_iter = 60;

        //despliegue
    printf("\nPROBLEMA 5, CAP\u00cdTULO 5\n");
    cuantas_caras(max_iter);
    return 0;
}