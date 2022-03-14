#include <stdio.h>
#include <ctime>
#include <cstdlib>

/**
 * Problema 43, Capitulo 5
 * 
 * Cada 1ro. de enero en una cierta ciudad del oeste el índice
 * de contaminación del aire es 100. Los días con "smog" y los
 * claros ocurren al azar, siendo la probabilidad de cada uno 1/2.
 * En un día claro, el índice decrece un 10% de su valor.
 * 
 * Simular 15 anios de 365 días cada uno para evaluar la probabilidad
 * de que el índice de contaminación sea mayor que 105 en un cierto día.
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    12 mar 2022

class simulacion_Clima
{
    private:
        unsigned short dias_totales;
        double index_contaminacion;
    public:
        simulacion_Clima()
        {
            dias_totales = 5475; //15 years * 365 days
            index_contaminacion = 0.0;
        }
        void calcular_Contaminacion()
        {

            //asignacion y variables auxiliares
            double probabilidad = 0.0;
            const double one_half = 1.0/2.0;
            const double one_O_five = 105.0;
            unsigned short indice, criterion_accomplished;
            bool smog_Day_OR_clear_Day, january_first, criterion_check; 
            indice = 0;
            criterion_accomplished = 0;

            //fase de simulación
            for(indice; indice<dias_totales; indice++)
            {
                //si es el primero de enero, se reinicia el índice a 100
                january_first = indice % 365 == 0;
                january_first ? index_contaminacion = 100 : 0;

                //revisión de dia con smog o sin smog
                probabilidad = rng_double();
                smog_Day_OR_clear_Day = probabilidad <= one_half;
                if(smog_Day_OR_clear_Day)
                    index_contaminacion = index_contaminacion + 0.1*index_contaminacion;
                else
                    index_contaminacion = index_contaminacion - 0.1*index_contaminacion;

                //se cumplió el criterio de index_smog > 105???
                criterion_check = index_contaminacion > one_O_five;
                criterion_check ? criterion_accomplished++ : 0; 
            }

            //impresion de resultados
                //P(index_smog > 105 en un día cualquiera)...
            probabilidad = (double)criterion_accomplished / double(dias_totales);
            printf("Simulación a 5475 días del índice de smog de la ciudad!!!");
            printf("\nP(índice smog > 105 en un día) = %lf\n\n", probabilidad);
        }
        double rng_double()
        {
            return (double)rand()/(double)RAND_MAX;
        }
};

int main()
{
    //semilla_inicial
    srand(std::time(NULL));

    //objeto auxiliar
    simulacion_Clima experimento = simulacion_Clima();

    printf("\nPROBLEMA 43, CAP\u00cdTULO 5\n\n");
    experimento.calcular_Contaminacion();
    return 0;
}