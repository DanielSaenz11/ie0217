/**
 * Ejemplo 1 del uso de memoria dinamica
 * Contiene los pasos explicitos para declarar un puntero, asignarle memoria dinamica,
 * asignarle un valor a ese contenido de memoria dinamica y liberar la memoria
 */

#include <iostream>
using namespace std;

int main() {

    // Declarar un puntero entero
    int *pointInt;

    // Declarar un puntero flotante
    float *pointFloat;

    /* 
    Reservar memoria dinamica para los punteros
    new retorna la direccion de la memoria reservada
    */
    pointInt = new int;
    pointFloat = new float;

    /* 
    Asignar valor a la memoria
    Uso del operador de desreferencia (*) para acceder al contenido que apunta la memoria
    y asignarle un valor
    */
    *pointInt = 45; 
    *pointFloat = 45.45f;

    // Imprimir el contenido de los punteros a memoria dinamica
    cout << *pointInt << endl;
    cout << *pointFloat << endl;

    // Liberar memoria reservada
    delete pointInt;
    delete pointFloat;

    return 0;

}