#include <stdio.h>

/**
 * Problema 42, Capitulo 5
 * 
 * Suponer que un jugador apuesta $5 en el siguiente
 * juego:
 *  
 *  • Se arrojan dos dados. Si se sale un impar, pierde.
 *  • Si los dados dan pares, saca una carta de una baraja común.
 *  • Si la carta es un As, 3, 5, 7 ó 9, el jugador gana el valor
 *  de la carta; 
 *  • En otras condiciones, pierde.
 * 
 * Qué ganará (o perderá) en promedio el jugador en este juego?
 * 
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    12 mar 2022

class perdida_Ganancia
{
    public:
        virtual double get_Dinero() = 0;
        virtual double get_Suceso() = 0;
    protected:
        short dinero, numero_sucesos;
};

class perdida_de_Uno : public perdida_Ganancia
{
    public:
        perdida_de_Uno()
        {
            dinero = -1;
            numero_sucesos = 594;
        }
        virtual double get_Dinero() override
        {
            return double(dinero);
        }
        virtual double get_Suceso() override
        {
            return double(numero_sucesos);
        }
};

class ganancia_de_Uno : public perdida_Ganancia
{
    public:
        ganancia_de_Uno()
        {
            dinero = 1;
            numero_sucesos = 72;
        }
        virtual double get_Dinero() override
        {
            return double(dinero);
        }
        virtual double get_Suceso() override
        {
            return double(numero_sucesos);
        }
};

class ganancia_de_Tres : public perdida_Ganancia
{
    public:
        ganancia_de_Tres()
        {
            dinero = 3;
            numero_sucesos = 72;
        }
        virtual double get_Dinero() override
        {
            return double(dinero);
        }
        virtual double get_Suceso() override
        {
            return double(numero_sucesos);
        }
};

class ganancia_de_Cinco : public perdida_Ganancia
{
    public:
        ganancia_de_Cinco()
        {
            dinero = 5;
            numero_sucesos = 72;
        }
        virtual double get_Dinero() override
        {
            return double(dinero);
        }
        virtual double get_Suceso() override
        {
            return double(numero_sucesos);
        }
};

class ganancia_de_Siete : public perdida_Ganancia
{
    public:
        ganancia_de_Siete()
        {
            dinero = 7;
            numero_sucesos = 72;
        }
        virtual double get_Dinero() override
        {
            return double(dinero);
        }
        virtual double get_Suceso() override
        {
            return double(numero_sucesos);
        }
};

class ganancia_de_Nueve : public perdida_Ganancia
{
    public:
        ganancia_de_Nueve()
        {
            dinero = 9;
            numero_sucesos = 72;
        }
        virtual double get_Dinero() override
        {
            return double(dinero);
        }
        virtual double get_Suceso() override
        {
            return double(numero_sucesos);
        }
};

class Valor_Esperado
{
    public:
        Valor_Esperado()
        {
            acceso = NULL;
            total_eventos = obtener_total_eventos();
        }
        double numero_perdidas_Uno()
        {
            acceso = &perder_Uno;
            return acceso->get_Suceso();
        }
        double numero_ganancias_Uno()
        {
            acceso = &ganar_Uno;
            return acceso->get_Suceso();
        }
        double numero_ganancias_Tres()
        {
            acceso = &ganar_Tres;
            return acceso->get_Suceso();
        }
        double numero_ganancias_Cinco()
        {
            acceso = &ganar_Cinco;
            return acceso->get_Suceso();
        }
        double numero_ganancias_Siete()
        {
            acceso = &ganar_Siete;
            return acceso->get_Suceso();
        }
        double numero_ganancias_Nueve()
        {
            acceso = &ganar_Nueve;
            return acceso->get_Suceso();
        }
        double valor_perdida_Uno()
        {
            acceso = &perder_Uno;
            return acceso->get_Dinero();
        }
        double valor_ganancia_Uno()
        {
            acceso = &ganar_Uno;
            return acceso->get_Dinero();
        }
        double valor_ganancia_Tres()
        {
            acceso = &ganar_Tres;
            return acceso->get_Dinero();
        }
        double valor_ganancia_Cinco()
        {
            acceso = &ganar_Cinco;
            return acceso->get_Dinero();
        }
        double valor_ganancia_Siete()
        {
            acceso = &ganar_Siete;
            return acceso->get_Dinero();
        }
        double valor_ganancia_Nueve()
        {
            acceso = &ganar_Nueve;
            return acceso->get_Dinero();
        }
        double probabilidad_perdidas_Uno()
        {
            acceso = &perder_Uno;
            return acceso->get_Suceso() / total_eventos;
        }
        double probabilidad_ganancias_Uno()
        {
            acceso = &ganar_Uno;
            return acceso->get_Suceso() / total_eventos;
        }
        double probabilidad_ganancias_Tres()
        {
            acceso = &ganar_Tres;
            return acceso->get_Suceso() / total_eventos;
        }
        double probabilidad_ganancias_Cinco()
        {
            acceso = &ganar_Cinco;
            return acceso->get_Suceso() / total_eventos;
        }
        double probabilidad_ganancias_Siete()
        {
            acceso = &ganar_Siete;
            return acceso->get_Suceso() / total_eventos;
        }
        double probabilidad_ganancias_Nueve()
        {
            acceso = &ganar_Nueve;
            return acceso->get_Suceso() / total_eventos;
        }
        double obtener_total_eventos()
        {
            acceso = NULL;
            return numero_perdidas_Uno() + numero_ganancias_Uno() + numero_ganancias_Tres()
                + numero_ganancias_Cinco() + numero_ganancias_Siete() + numero_ganancias_Nueve();
        }
        double valor_Esperado_perderUno()
        {
            return valor_perdida_Uno() * probabilidad_perdidas_Uno();
        }
        double valor_Esperado_ganarUno()
        {
            return valor_ganancia_Uno() * probabilidad_ganancias_Uno();
        }
        double valor_Esperado_ganarTres()
        {
            return valor_ganancia_Tres() * probabilidad_ganancias_Tres();
        }
        double valor_Esperado_ganarCinco()
        {
            return valor_ganancia_Cinco() * probabilidad_ganancias_Cinco();
        }
        double valor_Esperado_ganarSiete()
        {
            return valor_ganancia_Siete() * probabilidad_ganancias_Siete();
        }
        double valor_Esperado_ganarNueve()
        {
            return valor_ganancia_Nueve() * probabilidad_ganancias_Nueve();
        }
        double valor_Esperado_Total()
        {
            acceso = NULL;
            return valor_Esperado_perderUno() + valor_Esperado_ganarUno() + valor_Esperado_ganarTres()
                + valor_Esperado_ganarCinco() + valor_Esperado_ganarSiete() + valor_Esperado_ganarNueve();
        }
        void desplegar_valor_Esperado()
        {
            printf("E[ganancia/pérdida en el juego] = %f\n\n", valor_Esperado_Total());
        }
    private:
        double total_eventos;
        perdida_Ganancia *acceso;
        perdida_de_Uno perder_Uno;
        ganancia_de_Uno ganar_Uno;
        ganancia_de_Tres ganar_Tres;
        ganancia_de_Cinco ganar_Cinco;
        ganancia_de_Siete ganar_Siete;
        ganancia_de_Nueve ganar_Nueve;

};

int main()
{
    //objeto auxiliar
    Valor_Esperado experimento = Valor_Esperado();

    printf("\nPROBLEMA 42, CAP\u00cdTULO 5\n\n");
    experimento.desplegar_valor_Esperado();
    return 0;
}