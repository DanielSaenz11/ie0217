/**
 * Punto de entrada de ejecucion del proyecto
 * Archivo donde se encuentra la funcion main()
 */

// Incluir libreria y header file
#include <iostream>
#include "funciones.hpp"

using namespace std;

int main() {

    // Declarar objetos Student con el argumento de marks
    Student student1(88.0), student2(56.0);

    // Llamada de la funcion calculateAverage()
    calculateAverage(student1, student2);

    return 0;
}