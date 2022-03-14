#include <stdio.h>
#include <utility>

/**
 * Problema 44, Capítulo 2
 * 
 * Encontrar la potencia de una potencia; es decir
 * 
 * (a^m)^n
 * 
 * donde a = 20, m = 3, n = 2
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    9 mar 2022

class Potencias
{
    public:
        Potencias(unsigned short _a, unsigned short _m, 
        unsigned short _n): coeff(_a), expon_inter(_m), 
        expon_exter(_n) {}

        void imprimir_eq() 
        {
            printf("\nExpresión a calcular: (a^m)^n");
            printf("\nValores:\n a: %d\n m: %d\n n: %d",
                coeff, expon_inter, expon_exter);
            printf("\nResultado: "); //AGREGAR F(X)
            printf("%ld\n", potencia_de_potencia());
        }

        //calcula la expresión: (a^m)^n
            //se recuerda que (a^m)^n = a^(n*m)
        unsigned long potencia_de_potencia()
        {
            //opciones de cálculo
            switch (coeff)
            {
                case 0: //si el coeficiente es cero: 0^n = 0;
                    return 0;               
                    break;
            
                case 1: //si el coeficiente es uno: 1^n = 1;
                    return 1;         
                    break;

                default:
                    //exponente 'real': (a^m)^n = a^(n*m)
                    unsigned short mult_expon = expon_inter * expon_exter;

                    switch (mult_expon)
                    {
                        case 0: //si exponente es cero
                            return 1;
                            break;

                        case 1: //si el exponente es uno
                            return coeff;
                            break;
                        
                        default: //cálculo común
                            return potencias(mult_expon, coeff);
                            break;
                    }

                    break;
            }

            return 0;
        }

        //revisa cuantas veces un número es divisible
            //entre dos; usa duplas para almacenar:
                // • el número más pequenio acorde a lo estipulado 
                // • cuántas veces el n_original se pudo dividir
        std::pair<unsigned short, short> propiedades_entre_dos(unsigned short num)
        {   
            short counter = 0;

            while (!(num%2))
            {
                num = num>>1;
                counter++;
            }

            counter == 0 ? counter = -1 : 0;

            //retorna la cantidad de veces que el numero
                //se divide entre 2, y el remanente actual
            return std::make_pair(num, counter);
        }

        //calcula el valor de coeff elevado a exp: coeff^exp
        unsigned long potencias(unsigned short exp, unsigned short _coeff) //   DEBUG
        {
            //calculos previos: propiedades del coeficiente y el futuro exponente
            unsigned short exp_og = exp;
            std::pair<unsigned short, short> prop_coeff = propiedades_entre_dos(_coeff);        
            exp = exp * (unsigned short)prop_coeff.second;

            //si el numero es completamente divisible entre dos
            if (prop_coeff.first==1)
               return 1 << exp; // 1 * 2^exp;
            else
            {
                unsigned int other_coeff = prop_coeff.first;
                for(unsigned short i=0; i<exp_og-1; i++)
                    other_coeff = other_coeff*prop_coeff.first;
                
                return other_coeff << exp;
            }
        }

    private:
        unsigned short coeff, expon_inter, expon_exter;
};

int main() 
{
    //constantes dadas por el problema
    const unsigned short a = 20;
    const unsigned short m = 3;
    const unsigned short n = 2;

    //objeto auxiliar
    Potencias problema = Potencias(a,m,n);

    //despliegue
    printf("\nPROBLEMA 44, CAP\u00cdTULO 2\n");
    problema.imprimir_eq();

    return 0;
}