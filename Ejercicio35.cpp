#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <vector>

/**
 * Problema 35, Capitulo 5
 * 
 * Los matemátcos sostiene que en un grupo formado
 * al azar con alrededor de 23 personas, la probabilidad
 * de que dos o más de los integrantes tengan la misma fecha
 * de nacimiento (mes y día) es 0.5. Escribir un programa
 * para seleccionar 23 nacimientos al azar y hacer que el 
 * programa determine si dos cualesquiera de ellos tienen
 * la misma fecha. Correr el programa varias veces.
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    10 mar 2022

//para almacenar fechas
class Date {
    public:
        unsigned short mes, dia;
};

//incluye la generación de fechas y la determinación
    //de duplicados en las mismas
class Muestra {
    public:
        Muestra(const unsigned short n): 
        tamanio_muestra(n) {
            fechas = std::vector<Date>(tamanio_muestra);
        }

        //inicializa valores para las fechas //TODAVIA SE PUEDE MEJORAR
        void gen_fechas(){
            float prob_misma_fecha = 0.5F;

            //asignación inicial de valores para la primer persona
            fechas[0].mes = (rand()%12) + 1;
            fechas[0].dia = (rand()%30) + 1;

            for (unsigned short i=1; i< tamanio_muestra; i++)
            {
                    //si la prob es mayor que lo asignado, copia el valor anterior
                if(rand()>=prob_misma_fecha)
                {
                    fechas[i] = fechas[i-1];
                    hay_duplicados = true;
                }
                else    //de lo contrario, se asigna POR COMPLETO una nueva fecha
                {
                    fechas[i].mes = (rand()%12) + 1;
                    fechas[i].dia = (rand()%31) + 1;
                }

                prob_misma_fecha = prob_misma_fecha * 0.5F;
            }

            //para ejecutar todo en una sola llamada a la función
            despliegue_duplicados();
        }

        void despliegue_duplicados()
        {
            printf("\nEn la muestra de %d personas\n", tamanio_muestra);
            if(hay_duplicados)
                printf(" SI se encontraron fechas de nacimiento iguales!!!\n");
            else
                printf(" NO se encontraron fechas de nacimiento iguales!!!\n");
        }

    private:
        unsigned short tamanio_muestra;
        std::vector<Date> fechas;
        bool hay_duplicados = false;
};

int main()
{
    //Variables auxiliares
    srand(std::time(NULL));
    const unsigned short n_personas = 23;

    //objeto auxiliar 
    Muestra experimento = Muestra(n_personas);

    //despliegue
    printf("\nPROBLEMA 35, CAP\u00cdTULO 5\n");
    experimento.gen_fechas();
}