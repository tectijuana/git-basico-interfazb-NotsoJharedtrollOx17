#include <stdio.h>

/**
 * Problema 40, Capitulo 5
 * 
 * El acuniador del rey pone 500 monedas en una caja y coloca
 * una falsa por cada caja. El rey sospecha, pero en lugar de
 * probar todas las moneda en una caja saca una moneda al azar
 * de cada una de las 500 cajas. Cuál es la proabilidad de que
 * encuentre al menos una falsa
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    12 mar 2022

class Monedas
{
    public:
        Monedas(unsigned short mr, unsigned short mf, unsigned short c):
            monedas_reales(mr), monedas_falsas(mf), cajas(c) {}
        double probabilidad_monedasFalsas()
        {
            return 100.0*(double(monedas_falsas)/double(total_monedas));
        }
        void total_monedasReales()
        {
            monedas_reales = monedas_reales * cajas;
        }
        void total_monedasFalsas()
        {
            monedas_falsas = monedas_falsas * cajas;
        }
        void total_monedasGeneral()
        {
            total_monedas = monedas_reales + monedas_falsas;
        }
        void desplegar_probabilidades()
        {
            total_monedasReales();
            total_monedasFalsas();
            total_monedasGeneral();
            printf("\nMonedas reales: %d",monedas_reales);
            printf("\nMonedas falsas: %d",monedas_falsas);
            printf("\nCantidad de cajas: %d",cajas);
            printf("\nP(encontrar una moneda falsa) = %f\n\n",probabilidad_monedasFalsas());
        }
    private:
        unsigned int monedas_reales, total_monedas;
        unsigned short monedas_falsas, cajas;
};

int main()
{
    //constantes dadas por el problema
    const unsigned short monedas_reales = 500;
    const unsigned short monedas_falsas = 1;
    const unsigned short cajas = 500;

    //objeto auxiliar
    Monedas experimento = Monedas(monedas_reales, monedas_falsas, cajas);

    printf("\nPROBLEMA 40, CAP\u00cdTULO 5\n");
    experimento.desplegar_probabilidades();
    return 0;
}