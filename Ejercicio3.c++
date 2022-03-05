#include <stdio.h>
#include <algorithm>
#include <vector>
#include <ctime>


/**
 * Problema 103, Capitulo 2
 * 
 * Calcular e imprimir el determinante de una matríz 2x2
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    3 mar 2022

using namespace std;

//clase auxiliar para el programa
class Determinant_2x2 {
    public:
        Determinant_2x2() { //constructor
            n_values = matrix.size();
            for (unsigned short i = 0; i < n_values; i++)
                matrix.at(i) = rand() % 100; //aleatorio
        }

        //impresión de la matriz
        void Display_Matrix() {
            for (unsigned short i = 0; i < n_values; i++)
            {
                switch(i) {
                    case 0: 
                    printf("\t%d\t",matrix.front());
                    break;
                    
                    case 1:
                    printf("%d\n\n",matrix.at(i));
                    break;

                    case 2:
                    printf("\t%d\t",matrix.at(i));
                    break;

                    case 3:
                    printf("%d\n\n",matrix.back());
                    break;            
                }
            }
        }
        
        //formula
        int formula_determinant() {
            return matrix.at(0)*matrix.at(3)-matrix.at(1)*matrix.at(2); //formula común
        }

        //Excepciones para el cálculo por formula
        int Determinant_Exceps() {
            
            //variables auxiliares
            unsigned short count = 0;            
            bool any_zeroes, combo_cero;
            any_zeroes = false;
            combo_cero = false;

            //Cuantos 0s dentro del arreglo???
            for(unsigned short i=0; i<n_values; i++)
            {
                if(matrix.at(i)==0)
                {
                    count++;
                    any_zeroes = true;
                }
            }

            //casos especiales para formula
            if (count==0 & any_zeroes == false) //si no hay ningun 0
                return formula_determinant();
            else
            {
                //se evalua el resto de los casos
                switch(count)
                {
                    case 1: //si solo hay un 0
                        return formula_determinant();
                    break;

                    case 2: //si hay dos 0s              
                        /**
                         * Revisamos si la matríz de incidencia corresponde a algúna
                         * de las dos combinaciones de abajo; si una u otra suceden,
                         * el cálculo de la determinante va a ser 0.
                         * 
                         * Combinación: 
                         *                          
                         *     | 0    1 |       | 1     0 |
                         *     |        |   OR  |         |
                         *     | 1    0 |       | 0     1
                        */
                        for (unsigned short i = 0; i < n_values>>1; i++)
                            for(unsigned short j = n_values-1; j > n_values>>1; j--)
                                combo_cero = matrix.at(i) == 0 & matrix.at(j) == 0;

                        if (combo_cero | !combo_cero) 
                            // si una u otra combinación sucede, retornamos 0
                            return 0;
                        else //de lo contrario aplicamos la fórmula
                            return formula_determinant();
                    break;

                    default: //caso si hay tres o más 0s
                        return 0;
                    break;
                }
            }
        }

    private:
        vector<int> matrix = {0 , 0 , 0, 0};
        short n_values;
};

int main()
{
    srand(time(NULL)); //semilla para rand()
    Determinant_2x2 matriz_ejemplo; //objeto auxiliar

    printf("\nPROBLEMA 102, CAP\u00cdTULO 2");
    printf("\nValores de la matr\u00edz 2x2: \n\n");
    matriz_ejemplo.Display_Matrix(); //impresión de los valores de la matríz
    printf("Determinante de la matr\u00edz: %d\n", 
        matriz_ejemplo.Determinant_Exceps()); //determinante
    
    return 0;
}