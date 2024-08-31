/**
 * Palabras clave en memoria dinamica
 * 
 * // Inicializacion de memoria dinamica
 * pointerVariable = new dataType;
 * 
 * // Liberar memoria dinamica
 * delete pointerVariable;
 */

#include <iostream>
using namespace std;

int main() {
    // Declarar un puntero entero
    int *pointVar;

    // Reservar memoria dinamica para asignar al puntero
    pointVar = new int; // new devuelve la direccion de memoria reservada

    // Asignar valor a la variable para la que se reservo memoria dinamica
    *pointVar = 45;

    // Imprimir valor de la variable para la que se reservo memoria
    cout << *pointVar;

    // Liberar memoria dinamica
    delete pointVar;

    return 0;
}