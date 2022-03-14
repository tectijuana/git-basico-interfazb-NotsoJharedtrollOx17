#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

/**
 * Problema 66, Capítulo 1
 * 
 * Introducir un entero positivo N < 75 seguido por
 * N números reales. Imprimir cada uno de los números y
 * su promedio; imprimir en seguida tódos los números que queden
 * dentro de un rango de cinco unidades del promedio.
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    5 mar 2022

//clase auxiliar
class muestreo {
    public:
        muestreo(unsigned short n)
        {
            //Asignación de valores reales usando la distribución uniforme
            std::random_device rd; //semilla
            std::mt19937 generator(rd()); //argumento, genera enteros aleatorios
            
            //asigna los valores aleatorios desde 1 hasta 10 en la lista
            std::uniform_real_distribution<> randoms(1.0,100.0);
            for(unsigned short i=0; i<n; i++)
                valores.push_back(randoms(generator));

            //calculo del promedio de los valores
            promedio = std::accumulate(valores.begin(),valores.end(), 0)/ float(valores.size());
        }

        //muestra todos aquellos números que están en la cercania
            // del promedio en un rango de 5 unidades del mismo
        void despliegue_val_cerca_promedio()
        {
            unsigned short inicio_rango;
            unsigned short fin_rango;

            //ordenamiento ascendente de los valores
            std::sort(valores.begin(),valores.end());

            inicio_rango = leftmost_search(); //como se guarda el último que no cumple, se agrega 1
            fin_rango = rightmost_search(); //como se encuentra el último que no cumple, se sustrae 1

            //despliegue
            std::cout << "\nValores dentro de [promedio-5, promedio+5]: ";
            for(unsigned short i = inicio_rango; i<fin_rango+1; i++)
                std::cout << valores.at(i) << " ";
            std::cout << "\n";
        }

        //encuentra el índice del primer valor que 
            //és menor que (promedio+5)
        unsigned short leftmost_search()
        {
            for (unsigned short i=0; i<valores.size();i++)
                if (valores.at(i)>=promedio-5)
                {
                    return i;
                    break;
                }
            
            return 0;
        }

        //encuentra el índice del primer valor que 
            //és mayor que (promedio+5)
        unsigned short rightmost_search()
        {
            for (unsigned short i=valores.size()-1; i>0; i--)
                if (valores.at(i)<=promedio+5)
                {
                    return i;
                    break;
                }

            return valores.size()-1;
        }

        void despliegue_valores()
        {
            std::cout << "\nValores:\n";
            for (float n : valores)
                std::cout << n << " ";
            std::cout << "\n";
        }

        void despliegue_promedio()
        {
            std::cout << "\nPromedio de los valores: " << promedio << "\n";
        }

    private:
        std::vector<float> valores;
        float promedio;
};

int main() 
{
    unsigned short input; //variable auxiliar
    std::cout << "\nPROBLEMA 68, CAP\u00cdTULO 1";
    std::cout << "\nIngrese el número de valores: ";
    std::cin >> input;
    muestreo muestra = muestreo(input); //objeto auxiliar
    std::cout << "\n";
    muestra.despliegue_valores();
    muestra.despliegue_promedio();
    muestra.despliegue_val_cerca_promedio();
    return 0;
}