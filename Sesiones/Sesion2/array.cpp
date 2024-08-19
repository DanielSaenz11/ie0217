/**
 * Array
 * Arreglo de datos que se pueden acceder por su indice
 * 
 * data_type nombre[tamano] = {d1, d2, d3, ...}
 */

#include <iostream>
using namespace std;

int main() {
    // Forma 1: Colocar todos los elementos
    int x1[6] = {19, 10, 8, 17, 9, 15};

    // Forma 2: Los espacios vacios se llenan con 0
    int x2[6] = {19, 10, 8};

    // Array bidiomensional
    // Forma 1: Los primeros corresponden a la primera fila y asi sucesivamente
    int test1[2][3] = {2, 4, 5, 9, 0, 19};

    // Forma 2: Las llaves internan diferencian los elementos de cada fila
    int test2[2][3] = {{2, 4, 5}, {9, 0, 19}};


    return 0;
}