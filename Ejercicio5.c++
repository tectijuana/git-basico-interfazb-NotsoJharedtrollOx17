#include <stdio.h>

/**
 * Problema 118, Capitulo 2
 * 
 * Escribir un programa que resuelva las tres ecuaciones
 * siguientes:
 * 
 * x + 6y + 1 = 0
 * 2x - y + 5 = 0
 * -43 + 13y - 6 = 0
 * 
 * Sea x = 2, 4, 6, 8, ..., 50.
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    3 mar 2022

using namespace std;

class Lineas_Rectas {
    public:
        short valor_x, valor_y, valor_constante;

        //constructor
        Lineas_Rectas(short x, short y, short  _constante):
            valor_x(x), valor_y(y), valor_constante(_constante){
            }
        
        void Mostrar_Eq() {
            printf("\t%dx + %dy + %d = 0\n", valor_x, valor_y, 
                valor_constante);
        }

        //solucionador de ecuaciones, despejandola
        //de la forma y = mx + b
        double solucionador_para_y(unsigned short dominio) {
            if (valor_x!=0)
                return - double(valor_constante*dominio) / double(valor_y);
            else
                return - double(valor_x + valor_constante) / double(valor_y); 
        }
};

//verifica que el sistema pueda ser resuelto previo al cálculo
/*
bool solvencia_Sistema(vector<Lineas_Rectas> sistema) {
    
    //reducen código y aumentan lectura
    short cuantos_zero_x, cuantos_zero_y, cuantos_zero_z;
    bool hay_cero_en_x, hay_cero_en_y, hay_cero_en_z;

    for (int i = 0; i < sistema.size(); i++)
    {
        //revisa si hay ceros en x, y z
        hay_cero_en_x = sistema[i].valor_x == 0;
        hay_cero_en_y = sistema[i].valor_y == 0;
        hay_cero_en_z = sistema[i].valor_z == 0;

        //aumento de los contadores acorde a lo anterior
        hay_cero_en_x ? cuantos_zero_x++ : 0;
        hay_cero_en_y ? cuantos_zero_y++ : 0;
        hay_cero_en_z ? cuantos_zero_z++ : 0;
    }

    //deducción final
    if (cuantos_zero_x>2 || cuantos_zero_y>2 || cuantos_zero_z > 2)
        return false;
    else
        return true;
}
*/

int main() {

    //valores Eq. 1
    const short x_1 = 1;
    const short y_1 = 6;
    const short _const1 = 1;

    //valores Eq. 2
    const short x_2 = 2;
    const short y_2 = -1;
    const short _const2 = 5;

    //valores Eq. 3
    const short x_3 = 0;
    const short y_3 = 13;
    const short _const3 = 49;

    //tope de iteración
    const unsigned short MAX_VALUE = 25;
    
    /*
    vector<Lineas_Rectas> sistema = {
    };
    */

    //obetos auxiliares
    Lineas_Rectas ecuacion1 = 
        Lineas_Rectas(x_1,y_1,_const1);

    Lineas_Rectas ecuacion2 = 
        Lineas_Rectas(x_2,y_2,_const2);
        
    Lineas_Rectas ecuacion3 =    
        Lineas_Rectas(x_3,y_3,_const3);

    //despliegue de los resultados
    printf("\nPROBLEMA 118, CAP\u00cdTULO 2");
    printf("\n\nEcuaci\u00f3n 1:");
    ecuacion1.Mostrar_Eq();
    printf("Ecuaci\u00f3n 2:");
    ecuacion2.Mostrar_Eq();
    printf("Ecuaci\u00f3n 3:");
    ecuacion3.Mostrar_Eq();
    printf("\nMuestra de soluciones con x: 2, 4, ... 50\n");
    for(int i = 0; i<MAX_VALUE; i++)
    {
        printf("\n^x = %d:\n", (i+1)<<1);
        printf("    y_1 = %f\n", ecuacion1.solucionador_para_y((i+1)<<1));
        printf("    y_2 = %f\n", ecuacion2.solucionador_para_y((i+1)<<1));
        printf("    y_3 = %f\n", ecuacion3.solucionador_para_y((i+1)<<1));
    }
    return 0;
}