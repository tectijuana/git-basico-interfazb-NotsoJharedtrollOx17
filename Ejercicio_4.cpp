#include <stdio.h>

/**
 * Problema 112, Capitulo 2
 * 
 * Imprimir si las lineas determinadas por las ecuaciones:
 * 
 * y = 5x + 19
 * y = -4x - 19
 * 
 * son perpendiculares
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    4 mar 2022

using namespace std;

class Lineas_Rectas {
    public:
        Lineas_Rectas(int m, int b):
            pendiente(m), ordenada(b) {

            }
        
        //despliega la linea en forma ax + by + c = 0 
        void Mostrar_Eq() {
            printf("\t%dx + %d\n", pendiente, ordenada);
        }

        //prueba de ortogonalidad, usamos propiedades de las pendientes
        void son_perpendiculares(Lineas_Rectas &rec1, Lineas_Rectas &rec2)
        {
            //la multiplicación de las pendietes debe resultar en -1 para
                //que sean perpedinculares entre sí
            int mult_pendientes = rec1.pendiente*rec2.pendiente;

            if (mult_pendientes == -1)
                printf("SI\n");
            else
                printf("NO\n");
        }
    private:
        int pendiente, ordenada;
};

int main() {

    //constantes dadas por el ejercicio
    const int m_1 = 5;
    const int m_2 = -4;
    const int ord_1 = 19;
    const int ord_2 = -19;

    //objetos auxiliares
    Lineas_Rectas recta1 = Lineas_Rectas(
        m_1,
        ord_1
    );
    Lineas_Rectas recta2 = Lineas_Rectas(
        m_2,
        ord_2
    );

    //despliegue de los resultados
    printf("\nPROBLEMA 112, CAPI\u00cdULO 2");
    printf("\nL\u00ednea 1: \n\n");
    recta1.Mostrar_Eq();
    printf("\nL\u00ednea 2: \n\n");
    recta2.Mostrar_Eq();
    printf("\nSon perpendiculares?: ");
    recta1.son_perpendiculares(recta1,recta2);
}
