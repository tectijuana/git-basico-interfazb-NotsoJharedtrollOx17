#include <stdio.h>

/**
 * Problema 41, Capitulo 5
 * 
 * Una mano de poquer es un conjunto de cinco cartas tomadas
 * al azar de una baraja de 52 cartas. 
 * Encontrar la probabilidad de:
 *  a) una flor imperial;
 *  b) una corrida del mismo color;
 *  c) cuatro de una clase;
 *  d) una quintilla;
 *  e) una flor;
 *  f) una corrida;
 *  g) tres de una clase;
 *  h) dos de una clase;
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    12 mar 2022

class Manos_iniciales
{
    public:
        virtual double probabilidad_Obtencion(unsigned int cartas_totales) = 0;
        virtual void desplegar_Probabilidad(unsigned int cartas_totales) = 0;
    protected:
        unsigned int posibilidades;
};

class flor_Imperial : public Manos_iniciales
{
    public:
        flor_Imperial() { posibilidades = 4; }
        
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("P(una flor imperial) = %f", probabilidad_Obtencion(cartas_totales));
        }
};

class corrida_Mismo_color : public Manos_iniciales
{
    public:
        corrida_Mismo_color() { posibilidades = 36; }
    
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("\nP(una corrida del mismo color) = %f", probabilidad_Obtencion(cartas_totales));
        }
};

class cuatro_Una_clase : public Manos_iniciales
{
    public:
        cuatro_Una_clase() { posibilidades = 624; }
        
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("\nP(cuatro de una clase) = %f", probabilidad_Obtencion(cartas_totales));
        }
};

class quintilla : public Manos_iniciales
{
    public:
        quintilla() { posibilidades = 0; }
        
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("\nP(una quintilla) = %f", probabilidad_Obtencion(cartas_totales));
        }
};

class flor : public Manos_iniciales
{
    public:
        flor() { posibilidades = 5108; }
        
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("\nP(una flor (NO IMPERIAL)) = %f", probabilidad_Obtencion(cartas_totales));
        }
};

class corrida : public Manos_iniciales
{
    public:
        corrida() { posibilidades = 10200; }
        
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("\nP(una corrida (NO DEL MISMO COLOR)) = %f", probabilidad_Obtencion(cartas_totales));
        }
};

class tres_Una_clase : public Manos_iniciales
{
    public:
        tres_Una_clase() { posibilidades = 54912; }
        
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("\nP(tres de una clase) = %f", probabilidad_Obtencion(cartas_totales));
        }
};

class dos_Una_clase : public Manos_iniciales
{
    public:
        dos_Una_clase() { posibilidades = 123552; }
        
        double probabilidad_Obtencion(unsigned int cartas_totales) override
        { 
            return double(posibilidades)/double(cartas_totales); 
        }

        void desplegar_Probabilidad(unsigned int cartas_totales) override
        {
            printf("\nP(dos de una clase) = %f\n\n", probabilidad_Obtencion(cartas_totales));
        }
};

class Baraja
{
    public:
        Baraja()
        {
            cartas_totales = 2598960;
            acceso = NULL;
        }
        void desplegar_Probabilidades_manos()
        {
            printf("Probabilidades de manos iniciales!!!\n");
            desplegar_RoyalFlush();
            desplegar_StraightFlush();
            desplegar_FourofaKind();
            desplegar_Quintilla();
            desplegar_Flush();
            desplegar_Straight();
            desplegar_ThreeofaKind();
            desplegar_TwoPairs();
            acceso = NULL;
        }
        void desplegar_RoyalFlush()
        {
            acceso = &Royal_flush;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
        void desplegar_StraightFlush()
        {
            acceso = &Straight_flush;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
        void desplegar_FourofaKind()
        {
            acceso = &Four_of_a_kind;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
        void desplegar_Quintilla()
        {
            acceso = &Quintilla;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
        void desplegar_Flush()
        {
            acceso = &Flush;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
        void desplegar_Straight()
        {
            acceso = &Straight;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
        void desplegar_ThreeofaKind()
        {
            acceso = &Three_of_a_kind;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
        void desplegar_TwoPairs()
        {
            acceso = &Two_pairs;
            acceso->desplegar_Probabilidad(cartas_totales);
        }
    private:
        unsigned int cartas_totales;
        Manos_iniciales *acceso;
        flor_Imperial Royal_flush;
        corrida_Mismo_color Straight_flush;
        cuatro_Una_clase Four_of_a_kind;
        quintilla Quintilla;
        flor Flush;
        corrida Straight;
        tres_Una_clase Three_of_a_kind;
        dos_Una_clase Two_pairs;
};

int main()
{
    //objeto auxiliar
    Baraja experimento = Baraja();

    printf("\nPROBLEMA 41, CAP\u00cdTULO 5\n\n");
    experimento.desplegar_Probabilidades_manos();
    return 0;
}