#include <stdio.h>
#include <vector>
#include <exception>

using namespace std;
/**
 * Problema 7, Capitulo 3
 *
 * La distancia entre dos puntos A y B se define como |A - B|.
 * Escribir un programa para comparar |A - B| y |B - A|. Usar
 * las siguientes posiciones para A y B en los datos de prueba
 * 
 *  A | 12 -5 -2  9 
 * -----------------
 *  B | 10  9  3  13
*/

//@Autor    NotsoJharedtrollOx17
//@Fecha    4 mar 2022

//excepción personalizada
struct tablaexception : public exception
{
	const char * what () const throw ()
    {
    	return "Las filas no son del mismo tama\u00f1o!\nEl c\u00e1lculo no se puede realizar...";
    }
};

//calculo del valor absoluto (distancia)
unsigned short abs_val(short input)
{
    if (input > 0) //si es mayor a 0
        return input;
    else if (input < 0) //si es menor a 0
        return -input;
    else   //si es igual a 0
        return 0;
}

//despliega la tabla con los valores absolutos
void display_abs(vector<short> &row1, vector<short> &row2)
{
    //condició inicial
    bool same_size = row1.size() == row2.size();
    if (same_size)
    {
        printf("|\tA\t|\tB\t|\t|A-B|\t|\t|B-A|\t|\n"); //encabezados de la tabla
        for (int i=0; i<row1.size();i++)
        {
            i==0 ? printf( 
                //primera iteración
                "|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",
                
                row1.front(), row2.front(), // | A | B |

                abs_val(row1.front()-row2.front()), // | |A-B| |

                abs_val(row2.front()-row1.front()) // | |B-A| |
                
                ) : 

            i == row1.size()-1 ? printf( 
                //última iteración
                "|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",
                
                row1.back(), row2.back(), // | A | B |
                
                abs_val(row1.back()-row2.back()), // | |A-B| |
                
                abs_val(row2.back()-row1.back()) // | |B-A| |
                
                ) : printf( 
                    //caso general
                "|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",
                
                row1[i], row2[i], // | A | B |
                
                abs_val(row1[i]-row2[i]), // | |A-B| |
                
                abs_val(row2[i]-row1[i]) // | |B-A| |
                
                );
        }
    }
    else 
        throw tablaexception();
}

int main(){
    
    //valores dados por el problema
    vector<short> valores_A = {12, -5, -2, 9};
    vector<short> valores_B = {10, 9, 3, 13};
    
    //despliegue de los resultados
    printf("\nPROBLEMA 7, CAP\u00cdTULO 3\n");
    try
    {
        display_abs(valores_A, valores_B);
    }
    catch(tablaexception &e)
    {
        printf(e.what());
        main();
    }
    
    return 0;
}