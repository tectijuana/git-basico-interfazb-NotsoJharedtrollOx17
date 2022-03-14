#include <stdio.h>
#include <math.h>
#include <ctime>
#include <cstdlib>

/**
 * Problema 39, Capitulo 5
 * 
 * Suponer que giramos una perinola divida
 * equtativamente en tres regiones numerada
 * 1, 2, 3. En este experimento hay sólo tres
 * posibles resultados: 1, 2, 3. La probabilidad
 * teórica de obtener una cualquiera de ellas es 1/3.
 * Simular el giro de la perinola 1000 veces. El
 * resultado calculado se aproxima a la probabilidad
 * teórica?
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    12 mar 2022
class Regiones
{
    public:
        virtual void fue_seleccionado(double probabilidad) = 0;
        virtual void desplegar_numero() = 0;
    protected:
        bool verificacion_rango;
};

class Region_uno : public Regiones
{
    public:
        Region_uno()
        {
            verificacion_rango = false;
        }
        void fue_seleccionado(double probabilidad) override
        {
            verificacion_rango = (probabilidad <= upper_limit);
            if(verificacion_rango)
                desplegar_numero();
        }
        void desplegar_numero() override
        {
            printf("Se seleccionó la región 1!!!\n");
        }
    private:
        const double upper_limit = 1.0/3.0;
};

class Region_dos : public Regiones
{
    public:
        Region_dos()
        {        
            verificacion_rango = false;
        }
        void fue_seleccionado(double probabilidad) override
        {
            verificacion_rango = (probabilidad > lower_limit) 
            && (probabilidad <= upper_limit);
            if(verificacion_rango)
                desplegar_numero();        
        }
        void desplegar_numero() override
        {
            printf("Se seleccionó la región 2!!!\n");
        }
    private:
        const double lower_limit = 1.0/3.0;
        const double upper_limit = 2.0/3.0;

};

class Region_tres : public Regiones
{
    public:
        Region_tres()
        {            
            verificacion_rango = false;
        }
        void fue_seleccionado(double probabilidad) override
        {
            verificacion_rango = (probabilidad > lower_limit) 
            && (probabilidad <= upper_limit);
            if(verificacion_rango)
                desplegar_numero();
        }
        void desplegar_numero() override
        {
            printf("Se seleccionó la región 3!!!\n");
        }
    private:
        const double lower_limit = 2.0/3.0;
        const double upper_limit = 1.0;

};

class Pirinola
{
    public:
        Pirinola(const unsigned short n): 
        giros(n) {
            acceso = NULL;
        }
        void simular_giros()
        {
            unsigned short indice = 0;

            printf("Perinola girada %d veces:\n", giros);
            for(indice; indice<giros; indice++)
            {
                probabilidad = rng_double();
                printf("    \nGirada No. %d!!!\n", indice+1); 
                desplegar_regiones();
            }

            acceso=NULL;         
        }
        void desplegar_regiones()
        {
            desplegar_region1();
            desplegar_region2();
            desplegar_region3();
        }
        void desplegar_region1()
        {
            acceso=&region1;
            acceso->fue_seleccionado(probabilidad);
        }
        void desplegar_region2()
        {
            acceso=&region2;
            acceso->fue_seleccionado(probabilidad);            
        }
        void desplegar_region3()
        {
            acceso=&region3;
            acceso->fue_seleccionado(probabilidad);
        }
        double rng_double()
        {
            return (double)rand()/(double)RAND_MAX;
        }
    private: 
        unsigned short giros;
        double probabilidad;
        Regiones* acceso;
        Region_uno region1;
        Region_dos region2;
        Region_tres region3;
};

int main()
{
    //Variables auxiliares
    srand(std::time(NULL));
    const unsigned short numero_giros=1000;

    //objeto auxiliar
    Pirinola experimento = Pirinola(numero_giros);

     //despliegue
    printf("\nPROBLEMA 39, CAP\u00cdTULO 5\n");
    experimento.simular_giros();
    return 0;
}