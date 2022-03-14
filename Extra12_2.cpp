#include <stdio.h>
#include <math.h>

/**
 * Problema 12, Capítulo 2
 * 
 * Encontrar la solución para la ecuación
 * exponencial
 * 
 *  A^x = B
 * 
 * donde A = 3 y B = 81
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    6 mar 2022

class f_exponencial
{
    public:
        f_exponencial(unsigned short A, unsigned short B):
            coeff(A), _const(B){}

        void imprimir_funcion()
        {
            printf("\nFunción usada: ");
            printf("%d^x + %d = 0\n", coeff, _const);
        }

        void imprimir_solucion()
        {
            printf("\nSolución: ");
            printf("x = %f\n", newton_rhapson(0));
        }

        //calcula la raíz de la ecuacion dada; necesita 
            //derivada analítica
        float newton_rhapson(float x_n)
        {
            if (funcion_exp(x_n)==0)
                return x_n;
            else
            {
                x_n = x_n - funcion_exp(x_n)/derivada_exp(x_n);
                return newton_rhapson(x_n);
            }
        }

        //retorna el valor de f(x_n)
        float funcion_exp(float x)
        {
            return powf((float)coeff, x) - (float)_const;
        }

        //retorna el valor de f'(x_n)
            //f = A^x - B
            //f' = A^x * ln A
        float derivada_exp(float x)
        { 
            return powf((float)coeff, x) * logf((float)coeff);
        }

    private:
        unsigned short coeff, _const;
};

int main() 
{
    //constantes dadas por el problema
    const unsigned short A = 3;
    const unsigned short B = 81;

    f_exponencial equation = f_exponencial(A,B);

    printf("\nPROBLEMA 12, CAP\u00cdTULO 2");
    equation.imprimir_funcion();
    equation.imprimir_solucion();

    return 0;
}