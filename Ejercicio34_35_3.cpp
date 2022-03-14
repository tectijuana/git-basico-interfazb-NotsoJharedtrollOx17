#include <stdio.h>
#include <cmath>
using namespace std;

/**
 * Problema 35, Capitulo 3
 * 
 * La fórmula de Herón puede usarse para encontrar el área de cualquier
 * triánulo, dadas las medidas de los tres lados. La formula es:
 * 
 * Area = sqrt(s(s - a)(s - b)(s - c))
 * 
 * donde s = 1/2 (a + b + c). Encontrar el área de un triángulo cuyos
 * lados sean 6, 8 y 10 m.
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    4 mar 2022

//clase auxiliar para los calculos del triangulo
class triangle {
    public:
        double a,b,c;
        float one_fourths = 0.25F; //constante auxiliar

        triangle(short l1, short l2, short l3)
        {
            a = double(l1);
            b = double(l2);
            c = double(l3);
        }

        //muestra de cálculos
        void desplegar_medidas() {
            printf("MEDIDAS");
            printf("\nLado 1: %f", a);
            printf("\nLado 2: %f", b);
            printf("\nLado 3: %f", c);
            printf("\nPerimetro: %fm", perimetro());
            printf("\n\u00c1rea: %fm^2\n", area_heron());
        }

        double perimetro(){
            return a + b + c;
        }

        double area_heron(){
            double per = perimetro(); 
            double coeff; //argumentos estilo (s-k)

            //caculo iterativo
            for(short i = 0; i<0x3;i++)
            {
                switch(i)
                {
                    case 0:
                        coeff = per - a; //(s-a) 
                    break;

                    case 1:
                        coeff *= per - b; //(s-b)
                    break;

                    case 2:
                        coeff *= per - c; //(s-a)(s-b)(s-c)
                        coeff *= per; //s(s-a)(s-b)(s-c)
                        coeff = one_fourths * sqrt(coeff); //formula herón
                    break;
                }
            }
            return coeff;
        }
};

int main(){

    //valores dados por el problema
    const short a = 0x6;
    const short b = 0x8;
    const short c = 0xa;

    //objeto auxiliar
    triangle ejemplo = triangle(a,b,c);

    //despliegue de los resultados
    printf("\nPROBLEMA 7, CAP\u00cdTULO 3\n");
    printf("\u00c1rea de un tri\u00e1ngulo por medio de la f\u00f3rmula de Her\u00f3n\n\n");
    ejemplo.desplegar_medidas();
    return 0;
}